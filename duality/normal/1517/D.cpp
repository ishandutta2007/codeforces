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

int r[500][500],L[500][500],u[500][500],d[500][500];
int dp[20][500][500];
int main() {
    int i,j;
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m-1; j++) scanf("%d",&r[i][j]),L[i][j+1] = r[i][j];
    }
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < m; j++) scanf("%d",&d[i][j]),u[i+1][j] = d[i][j];
    }

    if (k & 1) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) printf("-1 ");
            printf("\n");
        }
        return 0;
    }

    int l;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) dp[0][i][j] = 0;
    }
    for (i = 1; i <= k/2; i++) {
        for (j = 0; j < n; j++) {
            for (l = 0; l < m; l++) {
                dp[i][j][l] = 1e9;
                if (j > 0) dp[i][j][l] = min(dp[i][j][l],u[j][l]+dp[i-1][j-1][l]);
                if (j < n-1) dp[i][j][l] = min(dp[i][j][l],d[j][l]+dp[i-1][j+1][l]);
                if (l > 0) dp[i][j][l] = min(dp[i][j][l],L[j][l]+dp[i-1][j][l-1]);
                if (l < m-1) dp[i][j][l] = min(dp[i][j][l],r[j][l]+dp[i-1][j][l+1]);
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) printf("%d ",dp[k/2][i][j]*2);
        printf("\n");
    }

    return 0;
}