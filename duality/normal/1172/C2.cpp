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

int a[200000],w[200000];
int dp[3001][3001],dp2[3001][3001];
int inv(int n) {
    n %= MOD;
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 0; i < n; i++) scanf("%d",&w[i]);

    int j;
    int sum0 = 0,sum1 = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == 0) sum0 += w[i];
        else sum1 += w[i];
    }
    dp[0][0] = dp2[0][0] = 1;
    for (i = 0; i < m; i++) {
        for (j = 0; j <= i; j++) {
            int sum = sum0+sum1+j-(i-j),isum = inv(sum);
            dp[i+1][j+1] += dp[i][j]*((((LLI) sum1+j)*isum) % MOD) % MOD,dp[i+1][j+1] %= MOD;
            dp[i+1][j] += dp[i][j]*((((LLI) sum0-(i-j)-1)*isum) % MOD) % MOD,dp[i+1][j] %= MOD;
            dp2[i+1][j+1] += dp2[i][j]*((((LLI) sum1+j-dp2[i][j]+MOD)*isum) % MOD) % MOD,dp2[i+1][j+1] %= MOD;
            dp2[i+1][j+1] += (dp2[i][j]+1)*(((LLI) dp2[i][j]*isum) % MOD) % MOD,dp2[i+1][j+1] %= MOD;
            dp2[i+1][j] += dp2[i][j]*((((LLI) sum0-(i-j))*isum) % MOD) % MOD,dp2[i+1][j] %= MOD;
        }
    }
    int ex0 = 0,ex1 = 0;
    for (i = 0; i <= m; i++) {
        ex0 += dp[m][i],ex0 %= MOD;
        ex1 += dp2[m][i],ex1 %= MOD;
    }
    for (i = 0; i < n; i++) {
        if (a[i] == 0) printf("%d\n",((LLI) ex0*w[i]) % MOD);
        else printf("%d\n",((LLI) ex1*w[i]) % MOD);
    }

    return 0;
}