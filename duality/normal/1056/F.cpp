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

pii prob[100];
double dp[101][1001][101];
int main() {
    int i,j,k;
    int tc,n;
    double C,T;
    scanf("%d",&tc);
    while (tc--) {
        scanf("%d",&n);
        scanf("%lf %lf",&C,&T);
        for (i = 0; i < n; i++) scanf("%d %d",&prob[i].first,&prob[i].second);
        sort(prob,prob+n);

        double s = 1;
        for (i = 0; i <= 1000; i++) {
            for (j = 0; j <= n; j++) dp[0][i][j] = 1e99;
        }
        dp[0][0][0] = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j <= 1000; j++) {
                for (k = 0; k <= n; k++) {
                    dp[i+1][j][k] = dp[i][j][k];
                    if ((j >= prob[i].second) && (k > 0)) dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j-prob[i].second][k-1]/0.9+prob[i].first);
                }
            }
        }
        int ans = 0;
        for (i = 0; i <= n; i++) {
            for (j = 1000; j >= 0; j--) {
                if (dp[n][j][i] > 1e50) continue;
                double x = dp[n][j][i]/0.9;
                double t = sqrt(x/C)-s/C;
                t = max(t,0.0);
                if (x/(s+t*C)+t <= T-i*10) {
                    ans = max(ans,j);
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}