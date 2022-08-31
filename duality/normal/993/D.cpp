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

pii p[50];
int a[50],b[50];
long double dp[55][55][55];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&p[i].first);
    for (i = 0; i < n; i++) scanf("%d",&p[i].second),p[i].second *= -1;
    sort(p,p+n,greater<pii>());
    for (i = 0; i < n; i++) a[i] = p[i].first,b[i] = -p[i].second;

    int j,k;
    long double l = 0,r = 2e8;
    while (abs(l-r) > 1e-9) {
        long double m = (l+r) / 2;
        for (i = 0; i < n+5; i++) {
            for (j = 0; j < n+5; j++) {
                for (k = 0; k < n+5; k++) dp[i][j][k] = 1e99;
            }
        }
        dp[0][1][0] = a[0]-m*b[0];
        for (i = 0; i < n-1; i++) {
            for (j = 0; j <= i+1; j++) {
                for (k = 0; k <= i; k++) {
                    dp[i+1][j+1][i+1] = min(dp[i+1][j+1][i+1],dp[i][j][k]+a[i+1]-m*b[i+1]);
                    if ((j > 0) && (a[i+1] < a[k])) dp[i+1][j-1][k] = min(dp[i+1][j-1][k],dp[i][j][k]);
                }
            }
        }
        for (i = 0; i <= n; i++) {
            for (j = 0; j < n; j++) {
                if (dp[n-1][i][j] < 1e-9) break;
            }
            if (j < n) break;
        }
        if (i <= n) r = m;
        else l = m;
    }
    printf("%I64d\n",(LLI) (ceil(l*1000)+1e-9));

    return 0;
}