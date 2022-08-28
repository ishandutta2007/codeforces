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

vi adjList[300];
int r,dp[300][300],dp2[300][300],size[300],temp[300],temp2[300];
int doDFS(int u,int p) {
    int i;
    vi c;
    size[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) size[u] += doDFS(v,u),c.pb(v);
    }
    if (c.empty()) {
        dp[u][0] = dp2[u][0] = 1;
        return 1;
    }
    else {
        int j,k,sum = 1;
        for (i = 0; i < size[u]; i++) dp[u][i] = dp2[u][i] = 0;
        for (i = 0; i < c.size(); i++) {
            int v = c[i];
            if (i == 0) {
                for (j = 0; j < size[v]; j++) {
                    dp[u][j+1] = (dp[u][j+1]+dp[v][j]) % MOD;
                    if (j+1 <= r) dp2[u][0] = (dp2[u][0]+dp[v][j]) % MOD;
                    if (j+1 <= r) dp2[u][j+1] = (dp2[u][j+1]+dp2[v][j]) % MOD;
                    else dp[u][0] = (dp[u][0]+dp2[v][j]) % MOD;
                    dp2[u][0] = (dp2[u][0]+dp2[v][j]) % MOD;
                }
            }
            else {
                for (j = 0; j < sum+size[v]; j++) temp[j] = temp2[j] = 0;
                for (j = 0; j < sum; j++) {
                    for (k = 0; k < size[v]; k++) {
                        temp[max(j,k+1)] = (temp[max(j,k+1)]+(LLI) dp[u][j]*dp[v][k]) % MOD;
                        temp2[min(j,k+1)] = (temp2[min(j,k+1)]+(LLI) dp2[u][j]*dp2[v][k]) % MOD;
                        if (j+k+1 <= r) {
                            temp2[j] = (temp2[j]+(LLI) dp2[u][j]*dp[v][k]) % MOD;
                            temp2[k+1] = (temp2[k+1]+(LLI) dp[u][j]*dp2[v][k]) % MOD;
                        }
                        else {
                            temp[k+1] = (temp[k+1]+(LLI) dp2[u][j]*dp[v][k]) % MOD;
                            temp[j] = (temp[j]+(LLI) dp[u][j]*dp2[v][k]) % MOD;
                        }
                    }
                }
                for (j = 0; j < sum+size[v]; j++) dp[u][j] = temp[j],dp2[u][j] = temp2[j];
            }
            sum += size[v];
        }
        for (i = r+1; i < size[u]; i++) dp[u][i] = 0;
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

    LLI ans = MOD-1;
    for (r = 0; r < n; r++) {
        doDFS(0,-1);
        for (i = 0; i < n; i++) ans += dp2[0][i];
        ans %= MOD;
    }
    for (i = 0; i < n; i++) ans = (ans*((MOD+1)/2)) % MOD;
    ans = (n-1-ans+MOD) % MOD;
    printf("%I64d\n",ans);

    return 0;
}