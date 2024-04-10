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

int xa[14],ya[14],xb[100],yb[100],t[100];
int close[100];
int dp[1 << 14][101],dp2[1 << 14][101];
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d %d",&xa[i],&ya[i]);
    for (i = 0; i < m; i++) scanf("%d %d %d",&xb[i],&yb[i],&t[i]);

    int j,k,l,ans = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < m-1; j++) {
            if (t[j] > t[j+1]) {
                swap(xb[j],xb[j+1]);
                swap(yb[j],yb[j+1]);
                swap(t[j],t[j+1]);
            }
        }
    }
    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j <= m; j++) dp[i][j] = -1e9,dp2[i][j] = 2e9;
    }
    for (i = 0; i < m; i++) dp[0][i] = 1;
    for (i = 0; i < n; i++) dp2[1 << i][0] = 0;
    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < m; j++) {
            close[j] = 2e9;
            for (k = 0; k < n; k++) {
                if (i & (1 << k)) close[j] = min(close[j],abs(xa[k]-xb[j])+abs(ya[k]-yb[j]));
            }
        }
        for (j = 0; j <= m; j++) {
            if (dp2[i][j] == 2e9) continue;
            for (k = 0; k < m; k++) {
                if (dp2[i][j]+close[k] <= t[k]) dp[i][k] = max(dp[i][k],j+1);
            }
        }
        for (j = 0; j < m; j++) {
            if (dp[i][j] < 0) continue;
            for (k = 0; k < n; k++) {
                if (i & (1 << k)) dp2[i][dp[i][j]] = min(dp2[i][dp[i][j]],t[j]);
                else dp2[i|(1 << k)][dp[i][j]] = min(dp2[i|(1 << k)][dp[i][j]],t[j]+abs(xa[k]-xb[j])+abs(ya[k]-yb[j]));
            }
            for (k = j+1; k < m; k++) {
                if (t[j]+min(close[k],abs(xb[j]-xb[k])+abs(yb[j]-yb[k])) <= t[k]) dp[i][k] = max(dp[i][k],dp[i][j]+1);
            }
        }
        for (j = 0; j <= m; j++) {
            if (dp2[i][j] == 2e9) continue;
            for (k = 0; k < n; k++) {
                if (i & (1 << k)) {
                    for (l = 0; l < n; l++) {
                        if (!(i & (1 << l))) dp2[i|(1 << l)][j] = min(dp2[i|(1 << l)][j],dp2[i][j]+abs(xa[k]-xa[l])+abs(ya[k]-ya[l]));
                    }
                }
            }
        }
        for (j = 0; j < m; j++) ans = max(ans,dp[i][j]);
    }
    printf("%d\n",ans);

    return 0;
}