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

int gcd(int a,int b) {
    int t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
int a[700];
int poss[700][700];
int dp[700][700][2];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    int j,k,l;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) poss[i][j] = (gcd(a[i],a[j]) > 1);
    }
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= n-i; j++) {
            k = j+i-1;
            for (l = j; l <= k; l++) {
                if (((l-1 < j) || dp[j][l-1][1]) && ((l+1 > k) || dp[l+1][k][0])) {
                    if ((j > 0) && poss[j-1][l]) dp[j][k][0] = 1;
                    if ((k+1 < n) && poss[l][k+1]) dp[j][k][1] = 1;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (((i == 0) || dp[0][i-1][1]) && ((i == n-1) || dp[i+1][n-1][0])) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");

    return 0;
}