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

vi adjList[50];
double dp[50][50],dp2[50][50];
int size[50];
double fact[51];
double C[51][51];
int doDFS(int u,int p) {
    int i,j,k,l;
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
            for (j = 0; j <= size[v]; j++) {
                dp2[0][j] = 0;
                for (k = 0; k < size[v]; k++) {
                    if (k >= j) dp2[0][j] += 0.5*dp[v][k]/size[v];
                    else dp2[0][j] += dp[v][j-1]/size[v];
                }
            }
            for (j = size[v]+1; j < size[u]; j++) dp2[0][j] = 0;
        }
        else {
            for (j = 0; j <= sum+size[v]; j++) {
                dp2[i][j] = 0;
                for (k = 0; k < size[v]; k++) {
                    for (l = 0; l <= min(j,size[v]); l++) {
                        double p = C[size[v]][l]*C[sum][j-l]/C[sum+size[v]][j];
                        if (k >= l) dp2[i][j] += 0.5*dp2[i-1][j-l]*dp[v][k]/size[v]*p;
                        else dp2[i][j] += dp2[i-1][j-l]*dp[v][l-1]/size[v]*p;
                    }
                }
            }
            for (j = sum+size[v]+1; j < size[u]; j++) dp2[i][j] = 0;
        }
        sum += size[v];
    }
    if (c.empty()) dp[u][0] = 1;
    else {
        for (i = 0; i < size[u]; i++) dp[u][i] = dp2[c.size()-1][i];
    }
    return size[u];
}
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    int j;
    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = i*fact[i-1];
    for (i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
    for (i = 0; i < n; i++) doDFS(i,-1),printf("%.10lf\n",dp[i][0]);

    return 0;
}