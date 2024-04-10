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

LLI fact[4000005],invfact[4000005];
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
LLI choose(int n,int k) {
    if ((k < 0) || (k > n)) return 0;
    else return ((((LLI) fact[n]*invfact[k]) % MOD)*invfact[n-k]) % MOD;
}
LLI invchoose(int n,int k) {
    if ((k < 0) || (k > n)) return 0;
    else return ((((LLI) invfact[n]*fact[k]) % MOD)*fact[n-k]) % MOD;
}
LLI dp[2000001];
int main() {
    int n,m;
    cin >> n >> m;

    int i;
    fact[0] = 1;
    for (i = 1; i < 4000005; i++) fact[i] = (i*fact[i-1]) % MOD;
    invfact[4000004] = inv(fact[4000004]);
    for (i = 4000003; i >= 0; i--) invfact[i] = ((i+1)*invfact[i+1]) % MOD;
    LLI sum = 0;
    for (i = 1; i <= n; i++) {
        LLI c = (choose(m+i-1,m-1)*invchoose(m+i,m)) % MOD;
        dp[i] = ((c*sum+((choose(m+i-1,m-1)*choose(n+m+1,n)) % MOD)*invchoose(n+m,n)) % MOD)*inv(1-c);
        dp[i] %= MOD;
        if (dp[i] < 0) dp[i] += MOD;
        sum += dp[i],sum %= MOD;
    }
    cout << (dp[n]*inv(choose(m+n-1,m-1))) % MOD << endl;

    return 0;
}