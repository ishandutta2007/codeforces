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

int l[100],r[100];
int main() {
    int i,j;
    int n,b,s = 0,q,x;
    scanf("%d",&n);
    LLI ways = 1;
    for (i = 0; i < n; i++) scanf("%d",&r[i]),ways = (ways*(r[i]+1)) % MOD;
    for (i = 0; i < n-1; i++) scanf("%d",&b),s += b,l[i+1] -= s,r[i+1] -= s;
    scanf("%d",&q);
    while (q--) {
        scanf("%d",&x);
        if (x > r[0]) printf("0\n");
        else {
            for (i = 0; i < n; i++) {
                if (l[i]-x < 0) break;
            }
            if (i == n) printf("%I64d\n",ways);
            else {
                int sum = 0;
                for (i = 0; i < n; i++) sum += max(r[i]-x,0);
                vi dp(sum+1);
                dp[0] = 1;
                for (i = 0; i < n; i++) {
                    for (j = 1; j <= sum; j++) {
                        dp[j] += dp[j-1];
                        if (dp[j] >= MOD) dp[j] -= MOD;
                    }
                    vi dp2(sum+1);
                    int ll = l[i]-x,rr = r[i]-x;
                    for (j = 0; j <= sum; j++) {
                        int e = min(j-ll,sum),s = max(j-rr,0);
                        if (s > e) dp2[j] = 0;
                        else dp2[j] = dp[e]-((s == 0) ? 0:dp[s-1])+MOD;
                        if (dp2[j] >= MOD) dp2[j] -= MOD;
                    }
                    dp = dp2;
                }
                int ans = 0;
                for (i = 0; i <= sum; i++) ans = (ans+dp[i]) % MOD;
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}