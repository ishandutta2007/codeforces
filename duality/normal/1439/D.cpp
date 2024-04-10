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

int C[1000][1000];
LLI dp[501],ways[501];
LLI dp2[501][501],ways2[501][501];
int main() {
    int n,m,p;
    cin >> n >> m >> p;

    int i,j,k;
    for (i = 0; i < 1000; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1]+C[i-1][j]) % p;
    }
    dp[0] = 0,ways[0] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) {
            LLI c = ((((LLI) ways[j]*ways[i-j-1]) % p)*C[i-1][j]) % p;
            ways[i] += c,ways[i] %= p;
            dp[i] += c*(j*(j+1)/2+(i-j-1)*(i-j)/2);
            dp[i] += (((((LLI) dp[j]*ways[i-j-1]) % p)*C[i-1][j]) % p)*(i+1);
            dp[i] += (((((LLI) dp[i-j-1]*ways[j]) % p)*C[i-1][j]) % p)*(i+1);
            dp[i] %= p;
        }
        ways[i] *= i+1,ways[i] %= p;
    }
    ways2[0][0] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= min(i,m); j++) {
            for (k = 0; k <= j; k++) {
                if (k == i) {
                    dp2[i][j] += dp[k],ways2[i][j] += ways[k];
                    dp2[i][j] %= p,ways2[i][j] %= p;
                }
                else {
                    LLI c = ((((LLI) ways[k]*ways2[i-k-1][j-k]) % p)*C[j][k]) % p;
                    ways2[i][j] += c,ways2[i][j] %= p;
                    dp2[i][j] += ((((LLI) dp2[i-k-1][j-k]*ways[k]) % p)*C[j][k]) % p;
                    dp2[i][j] += ((((LLI) dp[k]*ways2[i-k-1][j-k]) % p)*C[j][k]) % p;
                    dp2[i][j] %= p;
                }
            }
        }
    }
    cout << dp2[n][m] << endl;

    return 0;
}