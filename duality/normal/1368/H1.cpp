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

int l[100000],r[100000],u[100000],d[100000];
int dp[2],dp2[2];
int main() {
    int i;
    int n,m,q;
    char c;
    scanf("%d %d %d",&n,&m,&q);
    for (i = 0; i < n; i++) scanf(" %c",&c),l[i] = (c == 'B');
    for (i = 0; i < n; i++) scanf(" %c",&c),r[i] = (c == 'B');
    for (i = 0; i < m; i++) scanf(" %c",&c),u[i] = (c == 'B');
    for (i = 0; i < m; i++) scanf(" %c",&c),d[i] = (c == 'B');

    for (i = 0; i < n; i++) dp[!l[i]]++;
    dp[!u[0]]++,dp[!d[0]]++;
    for (i = 1; i < m; i++) {
        dp2[0] = min(dp[0],dp[1]+n)+u[i]+d[i];
        dp2[1] = min(dp[1],dp[0]+n)+!u[i]+!d[i];
        swap(dp,dp2);
    }
    for (i = 0; i < n; i++) dp[!r[i]]++;
    int ans = min(dp[0],dp[1]);
    dp[0] = dp[1] = 0;
    for (i = 0; i < m; i++) dp[!u[i]]++;
    dp[!l[0]]++,dp[!r[0]]++;
    for (i = 1; i < n; i++) {
        dp2[0] = min(dp[0],dp[1]+m)+l[i]+r[i];
        dp2[1] = min(dp[1],dp[0]+m)+!l[i]+!r[i];
        swap(dp,dp2);
    }
    for (i = 0; i < m; i++) dp[!d[i]]++;
    ans = min(ans,min(dp[0],dp[1]));
    printf("%d\n",ans);

    return 0;
}