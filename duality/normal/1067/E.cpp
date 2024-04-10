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
#define MOD 998244353
#define INV2 ((MOD+1)/2)

vi adjList[500000];
LLI dp[500000][2],dp2[500000][2];
int doDFS(int u,int p) {
    int i,v;
    vi c;
    vlli L,R,V;
    LLI all = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS(v,u),c.pb(v);
            L.pb((2*dp2[v][1]+dp2[v][0]) % MOD);
            all *= 2*(dp2[v][1]+dp2[v][0]),all %= MOD;
        }
    }
    if (L.empty()) {
        dp2[u][0] = 1;
        return 0;
    }
    R = L;
    for (i = 1; i < L.size(); i++) L[i] *= L[i-1],L[i] %= MOD;
    for (i = (int) R.size()-2; i >= 0; i--) R[i] *= R[i+1],R[i] %= MOD;
    dp2[u][0] = L.back();
    for (i = 0; i < c.size(); i++) {
        int v = c[i];
        LLI x = ((2*dp[v][1]+dp[v][0]) % MOD)*((i == 0) ? 1:L[i-1]);
        x %= MOD,x *= ((i == (int) R.size()-1) ? 1:R[i+1]),x %= MOD;
        dp[u][0] += x,dp[u][0] %= MOD;
        x = ((i == 0) ? 1:L[i-1]),x *= ((i == (int) R.size()-1) ? 1:R[i+1]),x %= MOD;
        V.pb(x);
    }
    dp2[u][1] = (all-dp2[u][0]+MOD) % MOD;
    for (i = 0; i < c.size(); i++) v = c[i],L[i] = R[i] = (2*(dp2[v][1]+dp2[v][0])) % MOD;
    for (i = 1; i < L.size(); i++) L[i] *= L[i-1],L[i] %= MOD;
    for (i = (int) R.size()-2; i >= 0; i--) R[i] *= R[i+1],R[i] %= MOD;
    for (i = 0; i < c.size(); i++) {
        int v = c[i];
        LLI x = (dp[v][0])*((i == 0) ? 1:L[i-1]);
        x %= MOD,x *= ((i == (int) R.size()-1) ? 1:R[i+1]),x %= MOD;
        dp[u][1] += x,dp[u][1] %= MOD;
        x = ((i == 0) ? 1:L[i-1]);
        x *= ((i == (int) R.size()-1) ? 1:R[i+1]),x %= MOD;
        x = (x+MOD-V[i]) % MOD;
        x *= (2*dp[v][1]+dp[v][0]) % MOD,x %= MOD;
        dp[u][1] += x,dp[u][1] %= MOD;
    }
    dp[u][1] += dp2[u][1],dp[u][1] %= MOD;
    return 0;
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
    doDFS(0,-1);
    int ans = (dp[0][0]+dp[0][1]) % MOD;
    printf("%d\n",(2*ans) % MOD);

    return 0;
}