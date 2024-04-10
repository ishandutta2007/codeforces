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

int modPow(LLI b,LLI e) {
    LLI r = 1;
    while (e > 0) {
        if (e & 1) r *= b,r %= MOD;
        e >>= 1;
        b *= b,b %= MOD;
    }
    return r;
}
bitset<200001> bs;
vi f[200001];
int main() {
    int n,K;
    scanf("%d %d",&n,&K);

    int i,j;
    bs.set();
    for (i = 2; i <= 2*n; i++) {
        if (bs[i]) {
            for (j = i; j <= 2*n; j += i) bs[j] = 0,f[j].pb(i);
        }
    }

    int g,k;
    int ans = 0;
    for (g = 1; g <= n-1; g++) {
        int c = (n-1)/g;
        for (i = 2; i <= 2*c; i++) {
            int l = max(1,i-c),r = min(i-1,c);
            if (l <= r) {
                int x = 0;
                for (j = 0; j < (1 << f[i].size()); j++) {
                    int b = 0,p = 1;
                    for (k = 0; k < f[i].size(); k++) {
                        if (j & (1 << k)) b++,p *= f[i][k];
                    }
                    if (b & 1) x -= r/p-(l+p-1)/p+1;
                    else x += r/p-(l+p-1)/p+1;
                }
                int e = (n % g)*max(i-n/g-1,1)+(g-(n % g))*max(i-n/g,1);
                ans += ((LLI) x*modPow(K,e)) % MOD,ans %= MOD;
            }
        }
    }
    ans = ((LLI) ans*modPow(K,(LLI) (MOD-2)*n)) % MOD;
    printf("%d\n",ans);

    return 0;
}