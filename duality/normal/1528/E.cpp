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

int inv(int n) {
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
int INV2 = inv(2);
int INV6 = inv(6);
LLI dp[1000001];
int main() {
    int n;
    cin >> n;

    int i;
    dp[0] = 1;
    for (i = 1; i <= n; i++) {
        dp[i] = dp[i-1]+1;
        dp[i] += (((dp[i-1]*(dp[i-1]+1)) % MOD)*INV2) % MOD;
        dp[i] %= MOD;
    }

    LLI ans1 = dp[n-1];
    ans1 += (((dp[n-1]*(dp[n-1]+1)) % MOD)*INV2) % MOD;
    ans1 += (((((dp[n-1]*(dp[n-1]+1)) % MOD)*(dp[n-1]+2)) % MOD)*INV6) % MOD;
    ans1 %= MOD;
    ans1 = 2*ans1+MOD-1,ans1 %= MOD;
    n--;
    LLI ans2 = dp[n-1];
    ans2 += (((dp[n-1]*(dp[n-1]+1)) % MOD)*INV2) % MOD;
    ans2 += (((((dp[n-1]*(dp[n-1]+1)) % MOD)*(dp[n-1]+2)) % MOD)*INV6) % MOD;
    ans2 %= MOD;
    ans2 = 2*ans2+MOD,ans2 %= MOD;
    LLI ans = (ans1-ans2+MOD) % MOD;
    n++;
    vi a(n+1),b(n+1);
    for (i = 1; i <= n; i++) a[i] = (((dp[i-1]*(dp[i-1]+1)) % MOD)*INV2) % MOD;
    for (i = n; i >= 1; i--) a[i] = (a[i]-a[i-1]+MOD) % MOD;
    for (i = 1; i <= n; i++) b[i] = (b[i-1]+a[i]) % MOD;
    for (i = 1; i <= n-2; i++) ans += (LLI) a[i]*b[n-i-1],ans %= MOD;
    cout << ans << endl;

    return 0;
}