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

int c[1500][1500];
vpii poss[1500][1500];
int x,y;
bool comp(pii a,pii b) {
    return max(a.first-y,a.second-x) < max(b.first-y,b.second-x);
}
int seen[1500*1500],num[1501];
int main() {
    int i,j;
    int n,q;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf("%d",&c[i][j]);
    }

    int k;
    for (i = n-1; i >= 0; i--) {
        for (j = n-1; j >= 0; j--) {
            vpii v;
            v.pb(mp(i,j));
            if (i < n-1) v.insert(v.end(),poss[i+1][j].begin(),poss[i+1][j].end());
            if (j < n-1) v.insert(v.end(),poss[i][j+1].begin(),poss[i][j+1].end());
            if ((i < n-1) && (j < n-1)) v.insert(v.end(),poss[i+1][j+1].begin(),poss[i+1][j+1].end());
            x = j,y = i;
            sort(v.begin(),v.end(),comp);
            for (k = 0; k < v.size(); k++) {
                if (poss[i][j].size() > q) break;
                if (!seen[c[v[k].first][v[k].second]]) {
                    poss[i][j].pb(v[k]);
                    seen[c[v[k].first][v[k].second]] = 1;
                }
            }
            for (k = 0; k < v.size(); k++) seen[c[v[k].first][v[k].second]] = 0;
            if (poss[i][j].size() <= q) num[min(n-i,n-j)]++;
            else num[min(max(poss[i][j][q].first-i,poss[i][j][q].second-j),min(n-i,n-j))]++;
        }
    }
    for (i = n-1; i >= 1; i--) num[i] += num[i+1];
    for (i = 1; i <= n; i++) printf("%d\n",num[i]);

    return 0;
}