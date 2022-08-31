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

int MOD;
int modPow(int b,int e) {
    int r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*b) % MOD;
        e >>= 1;
        b = ((LLI) b*b) % MOD;
    }
    return r;
}
int inv(int n) {
    return modPow(n,MOD-2);
}
LLI fact[405],num[405];
LLI dp[405][405];
int main() {
    int n;
    cin >> n >> MOD;

    int i,j,k;
    dp[0][0] = 1;
    fact[0] = 1;
    for (i = 1; i <= n+1; i++) fact[i] = ((LLI) i*fact[i-1]) % MOD;
    for (i = 1; i <= n+1; i++) {
        num[i] = modPow(2,i-1);
        num[i] = (num[i]*inv(fact[i])) % MOD;
    }
    for (i = 1; i <= n+1; i++) {
        for (j = 0; j <= i; j++) {
            for (k = 0; k < i-1; k++) {
                int d = i-k-1;
                if (j >= d) {
                    dp[i][j] += dp[k][j-d]*num[d];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    LLI ans = 0;
    for (i = 1; i <= n; i++) ans += dp[n+1][i]*fact[i],ans %= MOD;
    cout << ans << endl;

    return 0;
}