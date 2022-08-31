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

int a[200000];
vi pos[200000];
int pre[200001],pre2[200001];
int occ[200000],occ2[200005];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),pos[--a[i]].pb(i);

    int j;
    int m = 0;
    for (i = 0; i < n; i++) {
        if (pos[i].size() > pos[m].size()) m = i;
    }
    int c = 0;
    for (i = 0; i < n; i++) {
        if (pos[i].size() == pos[m].size()) c++;
    }
    if (c >= 2) {
        printf("%d\n",n);
        return 0;
    }
    int ans = 0;
    for (i = 0; i < n; i++) pre[i+1] = pre[i]+(a[i] == m);
    int B = sqrt(n);
    for (i = 0; i < n; i++) {
        if (i == m) continue;
        if (pos[i].empty()) continue;
        if (pos[i].size() > B) {
            for (j = 0; j < n; j++) pre2[j+1] = pre2[j]+(a[j] == i);
            vpii S;
            for (j = 0; j < n; j++) {
                pii p = mp(j,pre2[j]-pre[j]);
                if (S.empty() || (p.second < S.back().second)) S.pb(p);
                int c = pre2[j+1]-pre[j+1];
                int l = 0,r = S.size();
                while (l < r) {
                    int m = (l+r) / 2;
                    if (S[m].second <= c) r = m;
                    else l = m+1;
                }
                if (r < S.size()) ans = max(ans,j-S[r].first+1);
            }
        }
    }
    for (i = 1; i <= B+2; i++) {
        vpii cand;
        for (j = 0; j < pos[m].size(); j++) {
            int k = j+i-1;
            if (k >= pos[m].size()) break;
            int l = (j == 0) ? 0:pos[m][j-1]+1;
            int r = (k == pos[m].size()-1) ? n-1:pos[m][k+1]-1;
            cand.pb(mp(l,r));
        }
        int l = 0,r = -1,b = 0;
        fill(occ,occ+n,0);
        fill(occ2,occ2+n+5,0);
        occ2[0] = 1;
        for (j = 0; j < cand.size(); j++) {
            while (r < cand[j].second) {
                r++;
                if (a[r] != m) {
                    b += 2;
                    occ2[occ[a[r]]]--;
                    occ[a[r]]++;
                    occ2[occ[a[r]]]++;
                    while (occ2[b] == 0) b--;
                }
            }
            while (l < cand[j].first) {
                if (a[l] != m) {
                    b += 2;
                    occ2[occ[a[l]]]--;
                    occ[a[l]]--;
                    occ2[occ[a[l]]]++;
                    while (occ2[b] == 0) b--;
                }
                l++;
            }
            if (b >= i) ans = max(ans,r-l+1);
        }
    }
    printf("%d\n",ans);

    return 0;
}