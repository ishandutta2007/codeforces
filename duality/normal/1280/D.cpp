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

int n;
int diff[3000];
vi adjList[3000];
int size[3000];
pair<int,LLI> dp[3000][3000],dp2[3000][3000];
int doDFS(int u,int p) {
    int i,j,k;
    vi c;
    size[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) size[u] += doDFS(v,u),c.pb(v);
    }
    int sum = 0;
    for (i = 0; i < c.size(); i++) {
        int v = c[i];
        if (i == 0) {
            for (j = 0; j <= sum+size[v]; j++) dp2[i][j] = mp(0,-1e18);
            for (j = 0; j < size[v]; j++) {
                dp2[0][j] = max(dp2[0][j],mp(dp[v][j].first + (dp[v][j].second > 0),(LLI) diff[u]));
                dp2[0][j+1] = mp(dp[v][j].first,dp[v][j].second+diff[u]);
            }
        }
        else {
            for (j = 0; j <= sum+size[v]; j++) dp2[i][j] = mp(0,-1e18);
            for (j = 0; j <= sum; j++) {
                for (k = 0; k < size[v]; k++) {
                    dp2[i][j+k+1] = max(dp2[i][j+k+1],mp(dp2[i-1][j].first+dp[v][k].first,dp2[i-1][j].second+dp[v][k].second));
                    dp2[i][j+k] = max(dp2[i][j+k],mp(dp2[i-1][j].first+dp[v][k].first+(dp[v][k].second > 0),dp2[i-1][j].second));
                }
            }
        }
        sum += size[v];
    }
    if (c.empty()) dp[u][0] = mp(0,diff[u]);
    else {
        for (i = 0; i <= sum; i++) dp[u][i] = dp2[c.size()-1][i];
    }
    return size[u];
}
int main() {
    int i;
    int t,w,m,u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < n; i++) scanf("%d",&diff[i]);
        for (i = 0; i < n; i++) scanf("%d",&w),diff[i] = w-diff[i];
        for (i = 0; i < n-1; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        doDFS(0,-1);
        printf("%d\n",dp[0][n-m].first + (dp[0][n-m].second > 0));
        for (i = 0; i < n; i++) adjList[i].clear();
    }

    return 0;
}