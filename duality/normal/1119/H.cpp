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

int B[1 << 17],C[1 << 17],BC[1 << 17],ans[1 << 17];
int modPow(LLI b,int e) {
    LLI r = 1;
    b %= MOD;
    while (e > 0) {
        if (e & 1) r *= b,r %= MOD;
        e >>= 1;
        b *= b,b %= MOD;
    }
    return r;
}
int FWHT(int *a,int s) {
    int i,j,k;
    for (k = 1; k < (1 << s); k <<= 1) {
        for (i = 0; i < (1 << s); i += (k << 1)) {
            for (j = 0; j < k; j++) {
                int v = a[i+j+k];
                a[i+j+k] = a[i+j]-v,a[i+j] = a[i+j]+v;
                if (a[i+j+k] < 0) a[i+j+k] += MOD;
                if (a[i+j] >= MOD) a[i+j] -= MOD;
            }
        }
    }
    return 0;
}
int main() {
    int i;
    int n,k,x,y,z,a,b,c;
    int xora = 0;
    scanf("%d %d %d %d %d",&n,&k,&x,&y,&z);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d",&a,&b,&c);
        xora ^= a,b ^= a,c ^= a;
        B[b]++,C[c]++,BC[b^c]++;
    }
    LLI inv2 = modPow(2,MOD-2),inv4 = modPow(4,MOD-2);
    FWHT(B,k),FWHT(C,k),FWHT(BC,k);
    for (i = 0; i < (1 << k); i++) {
        LLI p = (B[i]+C[i])*inv2,q = (B[i]+BC[i])*inv2,r = (C[i]+BC[i])*inv2;
        p %= MOD,q %= MOD,r %= MOD;
        LLI all = ((n+p+q+r)*inv4) % MOD;
        LLI c = modPow((LLI) x+y+z,all);
        c *= modPow((LLI) x-y+z,(all-q+MOD) % MOD),c %= MOD;
        c *= modPow((LLI) x+y-z,(all-r+MOD) % MOD),c %= MOD;
        c *= modPow((LLI) x-y-z,(all-p+MOD) % MOD),c %= MOD;
        if (c < 0) c += MOD;
        ans[i] = c;
    }
    FWHT(ans,k);
    for (i = 0; i < (1 << k); i++) ans[i] = ((LLI) ans[i]*modPow(1 << k,MOD-2)) % MOD;
    for (i = 0; i < (1 << k); i++) printf("%d%c",ans[i^xora],(i == (1 << k)-1) ? '\n':' ');

    return 0;
}