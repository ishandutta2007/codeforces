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

char grid[1000000];
int MOD[3] = {1000000007,1000000009,1000000013};
int dp[1000000][3],dp2[1000000][3];
int main() {
    int i,j;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf(" %c",&grid[i*m+j]);
    }

    int k;
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (((i > 0) || (j > 0)) && (grid[i*m+j] == '.')) {
                if (j > 0) {
                    for (k = 0; k < 3; k++) dp[i*m+j][k] += dp[i*m+j-1][k];
                }
                if (i > 0) {
                    for (k = 0; k < 3; k++) dp[i*m+j][k] += dp[(i-1)*m+j][k];
                }
                for (k = 0; k < 3; k++) dp[i*m+j][k] %= MOD[k];
            }
        }
    }
    dp2[n*m-1][0] = dp2[n*m-1][1] = dp2[n*m-1][2] = 1;
    for (i = n-1; i >= 0; i--) {
        for (j = m-1; j >= 0; j--) {
            if (((i < n-1) || (j < m-1)) && (grid[i*m+j] == '.')) {
                if (j < m-1) {
                    for (k = 0; k < 3; k++) dp2[i*m+j][k] += dp2[i*m+j+1][k];
                }
                if (i < n-1) {
                    for (k = 0; k < 3; k++) dp2[i*m+j][k] += dp2[(i+1)*m+j][k];
                }
                for (k = 0; k < 3; k++) dp2[i*m+j][k] %= MOD[k];
            }
        }
    }
    if ((dp[n*m-1][0] == 0) && (dp[n*m-1][1] == 0) && (dp[n*m-1][2] == 0)) printf("0\n");
    else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if ((i == 0) && (j == 0)) continue;
                if ((i == n-1) && (j == m-1)) continue;
                for (k = 0; k < 3; k++) {
                    if ((((LLI) dp[i*m+j][k]*dp2[i*m+j][k]) % MOD[k]) != dp[n*m-1][k]) break;
                }
                if (k == 3) {
                    printf("1\n");
                    return 0;
                }
            }
        }
        printf("2\n");
    }

    return 0;
}