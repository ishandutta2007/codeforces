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

vlli pf;
vi f;
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
int dp[2][60];
int main() {
    LLI n;
    int K;
    cin >> n >> K;

    int i,j,k;
    for (i = 2; (LLI) i*i <= n; i++) {
        if ((n % i) == 0) {
            int c = 0;
            while ((n % i) == 0) n /= i,c++;
            pf.pb(i),f.pb(c+1);
        }
    }
    if (n > 1) pf.pb(n),f.pb(2);

    LLI ans = 1;
    for (i = 0; i < f.size(); i++) {
        LLI p = 1;
        for (j = 0; j < f[i]; j++) dp[1][j] = p,p *= pf[i],p %= MOD;
        for (j = 0; j < K; j++) {
            int p = j & 1,sum = 0;
            for (k = 0; k < f[i]; k++) {
                sum += dp[!p][k],sum %= MOD;
                dp[p][k] = ((LLI) sum*inv(k+1)) % MOD;
            }
        }
        ans *= dp[(K-1) & 1][f[i]-1],ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}