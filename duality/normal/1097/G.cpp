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
#define MOD 1000000007

int n,K;
vi adjList[100000];
int ipow2[100001];
int inv(int n) {
    LLI r = 1;
    int e = MOD-2;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
int size[100000];
int dp[100000][201],ans[201];
int doDFS(int u,int p) {
    int i,j,k;
    size[u] = 1,dp[u][0] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS(v,u);
            for (j = min(size[v]-1,K-1); j >= 0; j--) {
                int x = dp[v][j];
                if (j == 0) x = (1-ipow2[size[v]]+MOD) % MOD;
                ans[j+1] += ((LLI) x*(1-ipow2[n-size[v]]+MOD)) % MOD,ans[j+1] %= MOD;
                dp[v][j+1] += x,dp[v][j+1] %= MOD;
            }
            for (j = min(size[u]-1,K-1); j >= 0; j--) {
                for (k = 1; k <= min(size[v],K); k++) {
                    if (j+k > K) break;
                    int x = ((LLI) dp[u][j]*dp[v][k]) % MOD;
                    if (j > 0) ans[j+k] += x,ans[j+k] %= MOD;
                    dp[u][j+k] += x,dp[u][j+k] %= MOD;
                }
            }
            size[u] += size[v];
        }
    }
    return 0;
}
int dp2[201][201],fact[201];
int main() {
    int i;
    int a,b;
    scanf("%d %d",&n,&K);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    int j,x = inv(2);
    ipow2[0] = 1;
    for (i = 1; i <= n; i++) ipow2[i] = ((LLI) ipow2[i-1]*x) % MOD;
    int p = 1;
    for (i = 0; i < n; i++) p *= 2,p %= MOD;
    doDFS(0,-1);
    for (i = 1; i <= K; i++) ans[i] = ((LLI) ans[i]*p) % MOD;
    dp2[0][0] = fact[0] = 1;
    for (i = 1; i <= K; i++) {
        for (j = 1; j <= i; j++) dp2[i][j] = ((LLI) dp2[i-1][j]*j+dp2[i-1][j-1]) % MOD;
        fact[i] = ((LLI) fact[i-1]*i) % MOD;
    }
    int sum = 0;
    for (i = 1; i <= K; i++) sum += ((((LLI) ans[i]*dp2[K][i]) % MOD)*fact[i]) % MOD,sum %= MOD;
    printf("%d\n",sum);

    return 0;
}