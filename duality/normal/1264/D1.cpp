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

int inv(LLI n) {
    LLI r = 1;
    int e = MOD-2;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
int INV2 = inv(2);
int INV4 = inv(4);
LLI dp[2000][2000];
int main() {
    string s;
    cin >> s;

    int i,j,k;
    int n = s.size();
    for (i = 2; i <= n; i++) {
        for (j = 0; j <= n-i; j++) {
            k = j+i-1;
            vi v;
            if ((s[j] != '?') && (s[k] != '?')) {
                string x;
                x += s[j],x += s[k];
                if (x == "()") dp[j][k] = dp[j+1][k-1]+1;
                else if (x == "((") dp[j][k] = dp[j][k-1];
                else if (x == "))") dp[j][k] = dp[j+1][k];
                else dp[j][k] = dp[j+1][k-1];
            }
            else if ((s[j] == '?') && (s[k] != '?')) {
                if (s[k] == '(') dp[j][k] = dp[j][k-1];
                else dp[j][k] = (dp[j+1][k-1]+dp[j+1][k]+1)*INV2;
            }
            else if ((s[j] != '?') && (s[k] == '?')) {
                if (s[j] == ')') dp[j][k] = dp[j+1][k];
                else dp[j][k] = (dp[j+1][k-1]+dp[j][k-1]+1)*INV2;
            }
            else {
                dp[j][k] = ((2*dp[j+1][k]+2*dp[j][k-1]+1) % MOD)*INV4;
            }
            dp[j][k] %= MOD;
            if (dp[j][k] < 0) dp[j][k] += MOD;
        }
    }
    LLI ans = dp[0][n-1];
    for (i = 0; i < n; i++) {
        if (s[i] == '?') ans *= 2,ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}