#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

vi c[300000],c2[300000];
pii order[300000];
vpii occ[300000];
int last[300000],last2[300000],pos[300000];
int main() {
    int i,j;
    int t,n,q,k;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&q);
        for (i = 0; i < q; i++) {
            scanf("%d",&k),c[i].resize(k);
            for (j = 0; j < k; j++) scanf("%d",&c[i][j]),c[i][j]--;
            order[i] = mp(k,i);
        }
        sort(order,order+q);
        for (i = 0; i < q; i++) c2[i] = c[order[i].second];
        for (i = 0; i < q; i++) c[i] = c2[i];

        LLI sum = 0;
        for (i = 0; i < q; i++) sum += c[i].size();
        LLI best = sum*q,sum2 = 0;
        int p = -1,bad = 0;
        for (i = 0; i < q; i++) {
            sum2 += (LLI) c[i].size()*(c[i].size()-1)/2;
            LLI x = sum2+sum*(q-i-1);
            if (x < best) best = x,p = i;
        }
        for (i = 0; i <= p; i++) {
            for (j = 0; j < c[i].size()-1; j++) occ[c[i][j]].pb(mp(i,j));
        }
        fill(last,last+n,-1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < occ[i].size(); j++) {
                int x = c[occ[i][j].first][occ[i][j].second+1];
                for (k = occ[i][j].second+1; k < c[occ[i][j].first].size(); k++) {
                    int y = c[occ[i][j].first][k];
                    if ((last[y] == i) && (last2[y] != x)) {
                        bad = 1;
                        break;
                    }
                    last[y] = i,last2[y] = x;
                }
                if (bad) break;
            }
            if (bad) break;
        }
        if (!bad) {
            for (i = p+1; i < q; i++) {
                for (j = 0; j < c[i].size(); j++) pos[c[i][j]] = j+1;
                for (j = 0; j < q; j++) {
                    int e = c[i].size();
                    for (k = 0; k < c[j].size(); k++) {
                        if (pos[c[j][k]] != 0) {
                            if ((k < c[j].size()-1) && (pos[c[j][k]] < c[i].size()) && (c[j][k+1] != c[i][pos[c[j][k]]])) e = min(e,pos[c[j][k]]);
                            if (pos[c[j][k]] > e) {
                                bad = 1;
                                break;
                            }
                        }
                    }
                    if (bad) break;
                }
                for (j = 0; j < c[i].size(); j++) pos[c[i][j]] = 0;
                if (bad) break;
            }
        }

        printf(bad ? "Human\n":"Robot\n");
        for (i = 0; i < n; i++) occ[i].clear();
    }

    return 0;
}