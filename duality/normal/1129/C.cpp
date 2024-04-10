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

int S[3000];
LLI dp[3000][3000];
int match[3000][3000];
int main() {
    int i;
    int m;
    scanf("%d",&m);
    for (i = 0; i < m; i++) scanf("%d",&S[i]);

    int j;
    for (i = 0; i < m; i++) {
        for (j = i; j < m; j++) {
            dp[i][j] = 0;
            if (j-i+1 >= 1) dp[i][j] += (j == i) ? 1:dp[i][j-1];
            if (j-i+1 >= 2) dp[i][j] += (j == i+1) ? 1:dp[i][j-2];
            if (j-i+1 >= 3) dp[i][j] += (j == i+2) ? 1:dp[i][j-3];
            if (j-i+1 >= 4) {
                int b = (S[j-3] << 3) | (S[j-2] << 2) | (S[j-1] << 1) | S[j];
                if ((b != 3) && (b != 5) && (b != 14) && (b != 15)) dp[i][j] += (j == i+3) ? 1:dp[i][j-4];
            }
            dp[i][j] %= MOD;
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j <= i; j++) {
            if (S[i] != S[j]) match[i][j] = 0;
            else match[i][j] = ((i > 0) && (j > 0)) ? match[i-1][j-1]+1:1;
        }
    }
    int ans = 0;
    for (i = 0; i < m; i++) {
        int x = 0;
        for (j = 0; j < i; j++) x = max(x,match[i][j]);
        for (j = 0; j <= i-x; j++) ans += dp[j][i],ans %= MOD;
        printf("%d\n",ans);
    }

    return 0;
}