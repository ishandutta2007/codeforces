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

int a[1000];
int dp[1001][1000],pre[1001][1000];
int main() {
    int i;
    int n,K;
    scanf("%d %d",&n,&K);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a,a+n);

    int j,k,l;
    int ans = 0;
    for (i = 1; i <= 100000/(K-1); i++) {
        for (j = 0; j < n; j++) dp[1][j] = 1,pre[1][j] = j+1;
        for (k = 2; k <= K; k++) {
            l = 0;
            for (j = 0; j < n; j++) {
                while ((a[j]-a[l]) >= i) l++;
                dp[k][j] = (l == 0) ? 0:pre[k-1][l-1];
                pre[k][j] = ((j == 0) ? 0:pre[k][j-1])+dp[k][j];
                if (pre[k][j] >= MOD) pre[k][j] -= MOD;
            }
        }
        for (j = 0; j < n; j++) {
            ans += dp[K][j];
            if (ans >= MOD) ans -= MOD;
        }
    }
    printf("%d\n",ans);

    return 0;
}