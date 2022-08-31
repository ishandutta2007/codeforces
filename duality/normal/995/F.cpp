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

vi adjList[3000];
int dp[3000][3050];
int doDFS(int u) {
    int i,j;
    fill(dp[u],dp[u]+3050,1);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS(v);
        for (j = 0; j < 3050; j++) dp[u][j] = ((LLI) dp[u][j]*dp[v][j]) % MOD;
    }
    for (i = 1; i < 3050; i++) dp[u][i] = (dp[u][i]+dp[u][i-1]) % MOD;
    return 0;
}
LLI inv(LLI n) {
    LLI r = 1;
    int e = MOD-2;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
LLI poly[3050],temp[3050],temp2[3050];
int main() {
    int i;
    int n,D,p;
    scanf("%d %d",&n,&D);
    for (i = 1; i < n; i++) scanf("%d",&p),adjList[p-1].pb(i);
    doDFS(0);

    int j;
    temp[0] = 1;
    for (i = 1; i < n+50; i++) {
        for (j = i; j >= 0; j--) temp[j+1] += temp[j],temp[j] *= -i,temp[j] %= MOD;
        for (j = 0; j <= i+1; j++) temp[j] %= MOD;
    }
    for (i = 1; i < n+50; i++) {
        LLI d = 1;
        for (j = 1; j < n+50; j++) {
            if (i != j) d *= i-j,d %= MOD;
        }
        LLI c = (dp[0][i-1]*inv(d)) % MOD;
        LLI ii = inv(-i);
        for (j = 0; j < n+49; j++) {
            temp[j] *= ii,temp[j] %= MOD;
            temp[j+1] -= temp[j],temp[j+1] %= MOD;
        }
        for (j = 0; j <= n+49; j++) temp[j] %= MOD;
        for (j = 0; j < n+50; j++) poly[j] += c*temp[j],poly[j] %= MOD;
        for (j = n+48; j >= 0; j--) temp[j+1] += temp[j],temp[j] *= -i,temp[j] %= MOD;
        for (j = 0; j <= n+49; j++) temp[j] %= MOD;
    }
    LLI ans = 0;
    for (i = n+49; i >= 0; i--) ans *= D,ans += poly[i],ans %= MOD;
    if (ans < 0) ans += MOD;
    printf("%lld\n",ans);

    return 0;
}