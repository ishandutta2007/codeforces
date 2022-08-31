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

int k;
vi adjList1[4000],adjList2[4000];
int ways1[76],ways2[76];
vi dp[4000][4001];
vi sum[4000];
int pp[4000];
int doDFS(int u,int p) {
    if (!dp[u][p].empty()) return 0;
    int i,j;
    if (sum[u].empty()) {
        sum[u].resize(k+1);
        //fill(sum[u].begin(),sum[u].end(),0);
        for (i = 0; i < adjList1[u].size(); i++) {
            int v = adjList1[u][i];
            if (v != p) {
                doDFS(v,u);
                for (j = 0; j <= k; j++) {
                    sum[u][j] += dp[v][u][j];
                    if (sum[u][j] >= MOD) sum[u][j] -= MOD;
                }
            }
        }
        pp[u] = p;
    }
    vi c = sum[u];
    for (i = 0; i < adjList1[u].size(); i++) {
        int v = adjList1[u][i];
        if (v == p) {
            if (v != pp[u]) {
                for (j = 0; j <= k; j++) {
                    c[j] -= dp[v][u][j];
                    if (c[j] < 0) c[j] += MOD;
                }
            }
        }
        else if (v == pp[u]) {
            doDFS(v,u);
            for (j = 0; j <= k; j++) {
                c[j] += dp[v][u][j];
                if (c[j] >= MOD) c[j] -= MOD;
            }
        }
    }
    dp[u][p].resize(k+1);
    dp[u][p][0] = 1;
    for (i = 2; i <= k; i += 2) {
        LLI x = 0;
        for (j = 0; j < i; j += 2) x += ((LLI) c[j]*dp[u][p][i-j-2]) % MOD;
        dp[u][p][i] = x % MOD;
    }
    //cout<<u<<","<<p<<": ";
    //for (i = 0; i <= k; i++) cout << dp[u][p][i]<<" ";
    //cout<<endl;
    return 0;
}
int C[100][100];
int main() {
    int i;
    int n1,n2;
    int u,v;
    scanf("%d %d %d",&n1,&n2,&k);
    for (i = 0; i < n1-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList1[u].pb(v);
        adjList1[v].pb(u);
    }
    for (i = 0; i < n2-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList2[u].pb(v);
        adjList2[v].pb(u);
    }
    if (k & 1) {
        printf("0\n");
        return 0;
    }

    int j;
    for (i = 0; i < n1; i++) {
        doDFS(i,n1);
        for (j = 0; j <= k; j++) {
            ways1[j] += dp[i][n1][j];
            if (ways1[j] >= MOD) ways1[j] -= MOD;
        }
    }
    for (i = 0; i < n1; i++) {
        for (j = 0; j <= n1; j++) dp[i][j].clear();
        sum[i].clear();
    }
    for (i = 0; i < 4000; i++) swap(adjList1[i],adjList2[i]);
    swap(n1,n2);
    for (i = 0; i < n1; i++) {
        doDFS(i,n1);
        for (j = 0; j <= k; j++) {
            ways2[j] += dp[i][n1][j];
            if (ways2[j] >= MOD) ways2[j] -= MOD;
        }
    }
    for (i = 0; i < 100; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1]+C[i-1][j]) % MOD;
    }
    LLI ans = 0;
    for (i = 0; i <= k; i += 2) {
        ans += (((LLI) ways1[i]*ways2[k-i]) % MOD)*C[k][i];
        ans %= MOD;
    }
    printf("%I64d\n",ans);

    return 0;
}