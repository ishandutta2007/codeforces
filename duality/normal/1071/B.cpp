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

char grid[2000][2000];
int dp[2000][2000];
vpii best,best2;
int seen[2000][2000];
int main() {
    int i,j;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf(" %c",&grid[i][j]);
    }

    int l = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dp[i][j] = 1e9;
            if ((i == 0) && (j == 0)) dp[i][j] = 0;
            if (i > 0) dp[i][j] = min(dp[i][j],dp[i-1][j]);
            if (j > 0) dp[i][j] = min(dp[i][j],dp[i][j-1]);
            dp[i][j] += (grid[i][j] != 'a');
            if (dp[i][j] <= k) {
                if ((i+j+1) > l) best.clear(),l = i+j+1;
                if ((i+j+1) >= l) best.pb(mp(i,j));
            }
        }
    }
    string ans;
    for (i = 0; i < l; i++) ans += 'a';
    if (best.empty()) {
        ans += grid[0][0];
        best.pb(mp(0,0));
    }
    while (ans.size() < 2*n-1) {
        char s = 'z';
        for (i = 0; i < best.size(); i++) {
            int r = best[i].first,c = best[i].second;
            if (r+1 < n) s = min(s,grid[r+1][c]);
            if (c+1 < n) s = min(s,grid[r][c+1]);
        }
        for (i = 0; i < best.size(); i++) {
            int r = best[i].first,c = best[i].second;
            if ((r+1 < n) && (grid[r+1][c] == s) && !seen[r+1][c]) best2.pb(mp(r+1,c)),seen[r+1][c] = 1;
            if ((c+1 < n) && (grid[r][c+1] == s) && !seen[r][c+1]) best2.pb(mp(r,c+1)),seen[r][c+1] = 1;
        }
        best.clear(),best = best2,best2.clear();
        ans += s;
    }
    cout << ans << endl;

    return 0;
}