#include <bits/stdc++.h>

using namespace std;

const int max_n = 3033, mod = 998244353;

int n, m, dp[max_n][max_n];
string s, t;

bool ok(char c, int pos) {
    return pos >= m || c == t[pos];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> t;
    n = s.length();
    m = t.length();
    for (int i = 0; i < n; ++i) {
        if (ok(s[0], i)) {
            dp[1][i] = 2;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int l = 0; l + i <= n; ++l) {
            if (l && ok(s[i], l - 1)) {
                dp[i + 1][l - 1] += dp[i][l];
                dp[i + 1][l - 1] %= mod;
            }
            if (l + i < n && ok(s[i], l + i)) {
                dp[i + 1][l] += dp[i][l];
                dp[i + 1][l] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = m; i <= n; ++i) {
        ans += dp[i][0];
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}