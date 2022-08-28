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

char s[100001];
int dp[100001][2][2];
int main() {
    int i,j,k,l;
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%s",s);
        int n = strlen(s);
        if (n == 1) {
            printf("0\n");
            continue;
        }
        else if (n == 2) {
            printf("%d\n",(s[0] == s[1]));
            continue;
        }

        dp[1][0][0] = (s[0] == s[1]) ? 1e9:0;
        dp[1][0][1] = dp[1][1][0] = 1,dp[1][1][1] = 2;
        for (i = 2; i < n; i++) {
            for (j = 0; j < 2; j++) {
                for (k = 0; k < 2; k++) {
                    dp[i][j][k] = 1e9;
                    for (l = 0; l < 2; l++) {
                        if (!k && ((!l && (s[i] == s[i-2])) || (!j && (s[i] == s[i-1])))) continue;
                        dp[i][j][k] = min(dp[i][j][k],dp[i-1][l][j]+k);
                    }
                }
            }
        }
        printf("%d\n",min(min(dp[n-1][0][0],dp[n-1][0][1]),min(dp[n-1][1][0],dp[n-1][1][1])));
    }

    return 0;
}