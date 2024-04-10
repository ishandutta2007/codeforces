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

int modPow(int b,int e) {
    int r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*b) % MOD;
        e >>= 1;
        b = ((LLI) b*b) % MOD;
    }
    return r;
}
int dp[1000000];
int suff[1000001];
int ans[1000000];
int main() {
    int i,j;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);

        fill(dp,dp+n,0);
        dp[n-1] = 1,suff[n] = 0,suff[n-1] = ((LLI) dp[n-1]*modPow((MOD+1)/2,n-1)) % MOD;
        for (i = n-2; i >= 0; i--) {
            int x = min(n,2*i+1);
            dp[i] = ((LLI) (suff[i+1]-suff[x]+MOD)*modPow(2,i+1)) % MOD;
            dp[i] = ((LLI) dp[i]*((MOD+1)/2)) % MOD;
            suff[i] = (suff[i+1]+(LLI) dp[i]*modPow((MOD+1)/2,i)) % MOD;
        }
        for (i = 1; i < n; i++) ans[i] = ((LLI) dp[i]*modPow((MOD+1)/2,i/2)) % MOD;
        ans[0] = (n == 1);
        for (i = 0; i < n; i++) printf("%d\n",ans[i]);
    }
    
    return 0;
}