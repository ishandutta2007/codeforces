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

int h[200000];
int inv(LLI n) {
    LLI r = 1;
    int e = MOD-2;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
int fact[200001];
int power[200001];
int C(int n,int k) {
    return ((((LLI) fact[n]*inv(fact[k])) % MOD)*inv(fact[n-k])) % MOD;
}
int main() {
    int i,j;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) scanf("%d",&h[i]);

    int c = 0,ans = 1;
    for (i = 0; i < n; i++) {
        if (h[i] == h[(i+1) % n]) ans = ((LLI) ans*k) % MOD;
        else c++;
    }
    fact[0] = 1;
    for (i = 1; i <= c; i++) fact[i] = ((LLI) fact[i-1]*i) % MOD;
    LLI sum = 1;
    for (i = 0; i < c; i++) sum *= k,sum %= MOD;
    power[0] = 1;
    for (i = 1; i <= c; i++) power[i] = ((LLI) power[i-1]*(k-2)) % MOD;
    for (i = 0; 2*i <= c; i++) {
        sum -= ((((LLI) power[c-2*i]*C(c,i)) % MOD)*C(c-i,i)) % MOD;
        sum %= MOD;
    }
    if (sum < 0) sum += MOD;
    sum = ((LLI) sum*inv(2)) % MOD;
    ans = ((LLI) ans*sum) % MOD;
    printf("%d\n",ans);

    return 0;
}