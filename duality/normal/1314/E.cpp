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

int n,k;
int dp[2100][2100];
int ans = 0;
int check(vi v) {
    int i,j,kk;
    vi vv = v;
    for (i = 0; i < k; i++) {
        vi vv2;
        int sum = 0;
        for (j = 0; j < vv.size(); j++) {
            sum += vv[j]*(vv.size()-j);
            if (sum > n) return 0;
        }
        for (j = vv.size()-1; j >= 0; j--) {
            for (kk = 0; kk < vv[j]; kk++) vv2.pb(vv.size()-j);
        }
        vv = vv2;
    }
    return 1;
}
int findPoss(vi v,int sum) {
    if (sum*(sum+1)/2 > n) return 0;
    if (!v.empty()) ans++;
    int i;
    if (v.empty()) {
        for (i = 1; i <= n; i++) {
            if ((sum+i)*(sum+i+1)/2 > n) break;
            v.pb(i);
            if (!check(v)) {
                v.pop_back();
                return 0;
            }
            else {
                findPoss(v,sum+i);
                v.pop_back();
            }
        }
    }
    else {
        for (i = v.back(); i <= n; i++) {
            if ((sum+i)*(sum+i+1)/2 > n) break;
            v.pb(i);
            if (!check(v)) {
                v.pop_back();
                return 0;
            }
            else {
                findPoss(v,sum+i);
                v.pop_back();
            }
        }
    }
    return 1;
}
int main() {
    cin >> n >> k;

    if (k == 1) {
        int i,j,ans = 0;
        dp[0][0] = 1;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) dp[i][j] = (dp[i-1][j-1]+dp[i-j][j]) % MOD,ans += dp[i][j],ans %= MOD;
        }
        cout << ans << endl;
    }
    else if (k == 2) {
        int i,j,ans = 0;
        dp[0][0] = 1;
        for (i = 1; i <= n; i++) {
            for (j = 1; j*(j+1)/2 <= i; j++) dp[i][j] = (dp[i-j][j-1]+dp[i-j*(j+1)/2][j]) % MOD,ans += dp[i][j],ans %= MOD;
        }
        cout << ans << endl;
    }
    else {
        vi v;
        k--;
        findPoss(v,0);
        cout << ans << endl;
    }

    return 0;
}