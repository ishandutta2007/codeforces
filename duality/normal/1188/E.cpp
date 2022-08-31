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

int inv(LLI n) {
    LLI r = 1,e = MOD-2;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
int a[100000],m[100001];
int fact[2000001];
int C(int n,int k) {
    if (k > n) return 0;
    else return ((((LLI) fact[n]*inv(fact[k])) % MOD)*inv(fact[n-k])) % MOD;
}
int main() {
    int i;
    int k;
    scanf("%d",&k);
    for (i = 0; i < k; i++) scanf("%d",&a[i]);
    sort(a,a+k);

    for (i = 0; i < k; i++) {
        if (a[i] < i) {
            int p = i;
            for (i = p+1; i < k; i++) a[i] = a[p];
            break;
        }
    }

    fact[0] = 1;
    for (i = 1; i <= 2000000; i++) fact[i] = ((LLI) i*fact[i-1]) % MOD;
    LLI s = 0,sum = 0,ans = 0;
    for (i = 0; i < k; i++) s += a[i] % k,sum += a[i],m[k-(a[i] % k)]++;
    for (i = 0; i < k; i++) {
        ans += C((sum-s)/k+k-1,k-1),ans %= MOD;
        s += k,s -= k*m[i+1];
    }
    printf("%d\n",(int) ans);

    return 0;
}