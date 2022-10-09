#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n;)
#define rep1(i,n) for (int i = 0; ++i <= n;) 

int n, m;
string s[20];
llong dp[20][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = n; i > 0; --i) cin >> s[i];
    while (n > 0 and s[n] == string(m + 2, '0')) --n;
    dp[0][0] = -1;
    dp[0][1] = inf(int);
    llong ans = 0;
    rep1(i, n) {
        int l = m + 1, r = m + 1;
        while (l >= 1 and s[i][l] == '0') --l;
        while (r >= 1 and s[i][m + 1 - r] == '0') --r;
        ans = min(dp[i - 1][0] + 1 + l, dp[i - 1][1] + 1 + r);
        dp[i][0] = min(dp[i - 1][0] + 1 + 2 * l, dp[i - 1][1] + m + 2);
        dp[i][1] = min(dp[i - 1][1] + 1 + 2 * r, dp[i - 1][0] + m + 2);
    }
    cout << ans;
    return 0;
}