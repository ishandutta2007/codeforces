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

int fact[1000001];
LLI modPow(LLI n,LLI e) {
    LLI r = 1;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
LLI inv(LLI n) {
    return modPow(n,MOD-2);
}
LLI choose(int n,int k) {
    return ((((LLI) fact[n]*inv(fact[k])) % MOD)*inv(fact[n-k])) % MOD;
}
int main() {
    int n;
    cin >> n;

    int i;
    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = ((LLI) i*fact[i-1]) % MOD;
    LLI ans = 0;
    for (i = 1; i <= n; i++) {
        if (i & 1) ans += 2*((((((LLI) modPow(3,(LLI) n*(n-i)+i)*fact[n]) % MOD)*inv(fact[i])) % MOD)*inv(fact[n-i])) % MOD;
        else ans -= 2*((((((LLI) modPow(3,(LLI) n*(n-i)+i)*fact[n]) % MOD)*inv(fact[i])) % MOD)*inv(fact[n-i])) % MOD;
        ans %= MOD;
    }
    for (i = 1; i <= n; i++) {
        LLI c = -3*modPow(-1,i+n)*choose(n,i);
        LLI x = -modPow(3,n-i);
        ans += (c*(modPow(x+1,n)-modPow(x,n))) % MOD,ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << endl;

    return 0;
}