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

LLI fact[1000005],inv[1000005];
LLI modPow(LLI b,int e) {
    LLI r = 1;
    while (e > 0) {
        if (e & 1) r *= b,r %= MOD;
        e >>= 1;
        b *= b,b %= MOD;
    }
    return r;
}
LLI pown[1000005],powm[1000005];
int main() {
    int n,m,a,b;
    cin >> n >> m >> a >> b;

    int i,k;
    fact[0] = inv[0] = 1;
    for (i = 1; i < 1000005; i++) {
        fact[i] = (fact[i-1]*i) % MOD;
        inv[i] = modPow(fact[i],MOD-2);
    }
    pown[0] = powm[0] = 1;
    for (i = 1; i < 1000005; i++) pown[i] = (pown[i-1]*n) % MOD,powm[i] = (powm[i-1]*m) % MOD;
    LLI ans = 0;
    for (k = 0; k <= min(n-2,m); k++) {
        LLI x = (fact[m-1]*((inv[k]*inv[m-1-k]) % MOD)) % MOD;
        x *= powm[n-2-k],x %= MOD;
        x *= fact[n-2],x %= MOD;
        x *= inv[n-k-2],x %= MOD;
        if (k < n-2) {
            x *= pown[n-k-3],x %= MOD;
            x *= k+2,x %= MOD;
        }
        ans += x;
        if (ans >= MOD) ans -= MOD;
    }
    printf("%I64d\n",ans);

    return 0;
}