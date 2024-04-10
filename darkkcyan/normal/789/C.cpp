#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for(int i = -1; ++i < n; )

namespace Sol {

#define maxn 101010
int n;
long a[maxn];
long dp[maxn][2];

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n - 1) a[i] = abs(a[i] - a[i + 1]);
    --n;

    rep(i, n) dp[i][0] = dp[i][1] = a[i];
    long ans = dp[n - 1][0];
    for (int i = n - 1; i--; ) {
        dp[i][0] = max(dp[i][0], a[i] - dp[i + 1][1]);
        dp[i][1] = min(dp[i][1], a[i] - dp[i + 1][0]);
        ans = max(ans, dp[i][0]);
    }

    cout << ans;
    return 0;
}}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return Sol::main();
}