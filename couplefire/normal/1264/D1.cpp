#include <bits/stdc++.h>
using namespace std;

const int MOD = 119 << 23 | 1;

int fpow(int a, int k) {
    int r = 1, t = a;
    while (k) {
        if (k & 1) r = (long long) r * t % MOD;
        t = (long long) t * t % MOD;
        k >>= 1;
    }
    return r;
}

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        f[i + 1] = f[i];
        f[i + 1] += s[i] == '?';
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] != '(') {
                dp[i][j] += dp[i + 1][j];
                dp[i][j] %= MOD;
            }
            if (s[j] != ')') {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
            if (s[i] != '(' && s[j] != ')') {
                dp[i][j] -= dp[i + 1][j - 1];
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
            if (s[i] != ')' && s[j] != '(') {
                dp[i][j] += dp[i + 1][j - 1];
                dp[i][j] %= MOD;
                dp[i][j] += fpow(2, f[j] - f[i + 1]);
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}