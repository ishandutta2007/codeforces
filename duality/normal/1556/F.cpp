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

int inv(int n) {
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
int a[14];
int prob[14][14];
int dp[1 << 14];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    int j,k,l;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) prob[i][j] = ((LLI) a[i]*inv(a[i]+a[j])) % MOD;
    }
    for (i = 1; i < (1 << n); i++) {
        int p = 1;
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (k = 0; k < n; k++) {
                    if (!(i & (1 << k))) p = ((LLI) p*prob[j][k]) % MOD;
                }
            }
        }
        int f = 1;
        dp[i] = p;
        for (j = i; j > 0; j = (j-1) & i) {
            if (!f) {
                int q = 1;
                for (k = 0; k < n; k++) {
                    if ((i^j) & (1 << k)) {
                        for (l = 0; l < n; l++) {
                            if (!(i & (1 << l))) q = ((LLI) q*prob[k][l]) % MOD;
                        }
                    }
                }
                dp[i] = (dp[i]-(LLI) dp[j]*q) % MOD;
            }
            f = 0;
        }
    }
    int ans = 0;
    for (i = 0; i < (1 << n); i++) ans = (ans+(LLI) dp[i]*__builtin_popcount(i)) % MOD;
    if (ans < 0) ans += MOD;
    printf("%d\n",ans);

    return 0;
}