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
#define MOD 998244353

int dp[1000001][2];
int bal[1000001];
int findAns(int n) {
    if (n == 0) {
        dp[0][0] = dp[0][1] = 1;
        return 0;
    }
    else if (n == 1) {
        dp[1][0] = 0,dp[1][1] = 1;
        return 0;
    }
    else if (dp[n][0] != -1) return 0;

    int i;
    dp[n][0] = dp[n][1] = 0;
    for (i = 0; i <= n-1; i++) {
        assert(bal[i]+bal[n-i-1]+n >= bal[n]);
        if (bal[i]+bal[n-i-1]+n == bal[n]) {
            findAns(i),findAns(n-i-1);
            if ((i+1) & 1) {
                dp[n][1] += ((LLI) dp[i][0]*dp[n-i-1][i & 1]) % MOD;
                dp[n][1] %= MOD;
            }
            else {
                dp[n][0] += ((LLI) dp[i][1]*dp[n-i-1][(i+1) & 1]) % MOD;
                dp[n][0] %= MOD;
            }
        }
    }
    return 0;
}
int main() {
    int i,j,n;
    cin >> n;
    /*memset(dp,-1,sizeof(dp));
    bal[0] = 0,bal[1] = 1;
    for (i = 2; i <= n; i++) {
        //bal[i] = 1e9;
        //for (j = 0; j <= i-1; j++) bal[i] = min(bal[i],i+bal[j]+bal[i-j-1]);
        bal[i] = i+bal[(i-1)/2]+bal[i/2];//,cout<<bal[i]<<endl;
    }
    findAns(n);
    for (i = 1; i <= n; i++) {
        findAns(i);
        assert(dp[i][0]+dp[i][1] <=1 );
        if(dp[i][0]+dp[i][1]==1)cout<<i<<endl;
    }
    cout << (dp[n][0]+dp[n][1]) % MOD << endl;*/

    int c = 1,x = 0;
    while (1) {
        if ((n == c) || (n == c+1)) {
            cout << 1 << endl;
            return 0;
        }
        if (c > n+50) break;
        if (x & 1) c *= 2,c++,x++;
        else c *= 2,c += 2,x++;
    }
    cout << 0 << endl;

    return 0;
}