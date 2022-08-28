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

int a[5001];
LLI dp[5001][5001][2];
LLI findAns(int i,int k,int l) {
    if ((i < 0) || (k < 0)) return 1e10;
    if (dp[i][k][l] != -1) return dp[i][k][l];

    if (l) {
        dp[i][k][l] = 1e10;
        if (i >= 2) {
            dp[i][k][l] = findAns(i-2,k-1,1)+max(0,a[i-1]-min(a[i-2],a[i])+1);
            dp[i][k][l] = min(dp[i][k][l],findAns(i-2,k-1,0)+max(0,a[i-1]-a[i]+1));
        }
        else if (i == 1) {
            if (k == 1) dp[i][k][l] = max(0,a[i-1]-a[i]+1);
        }
        else {
            if (k == 1) dp[i][k][l] = 0;
        }
    }
    else {
        dp[i][k][l] = 1e10;
        if (i >= 1) {
            dp[i][k][l] = findAns(i-1,k,0);
            dp[i][k][l] = min(dp[i][k][l],findAns(i-1,k,1)+max(0,a[i]-a[i-1]+1));
        }
        else if (k == 0) dp[i][k][l] = 0;
    }
    //cout<<i<<","<<k<<","<<l<<": "<<dp[i][k][l]<<endl;
    return dp[i][k][l];
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    for (i = 1; i <= (n+1)/2; i++) printf("%I64d%c",min(findAns(n-1,i,0),findAns(n-1,i,1)),(i == (n+1)/2) ? '\n':' ');

    return 0;
}