#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, mod = 998244353;

int n, ans, dp[max_n][max_n][3][3], cnt[max_n], pw[max_n];
string s;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int get(int l, int r) {
    if (l == 0) {
        return cnt[r];
    }
    return cnt[r] - cnt[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (pw[i - 1] * 2) % mod;
    }
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) {
        cnt[i] = s[i] == '?';
        if (i) {
            cnt[i] += cnt[i - 1];
        }
    }
    dp[0][n - 1][0][0] = 1;
    for (int len = n; len >= 2; --len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            for (int f1 = 0; f1 < 3; ++f1) {
                for (int f2 = 0; f2 < 3; ++f2) {
                    for (int f3 = 1; f3 < 3; ++f3) {
                        for (int f4 = 1; f4 < 3; ++f4) {
                            if ((f1 == 0 || f1 == f3) && (f2 == 0 || f2 == f4) && (f1 == 0 || f2 == 0)) {
                                dp[l][r][f3][f4] += dp[l][r][f1][f2];
                                dp[l][r][f3][f4] %= mod;
                            }
                        }
                    }
                }
            }
            for (char c = '('; c <= ')'; ++c) {
                if (c != s[l] && s[l] != '?') {
                    continue;
                }
                for (char c2 = '('; c2 <= ')'; ++c2) {
                    if (c2 != s[r] && s[r] != '?') {
                        continue;
                    }
                    if (c != '(') {
                        dp[l + 1][r][0][c2 - '(' + 1] += dp[l][r][c - '(' + 1][c2 - '(' + 1];
                        dp[l + 1][r][0][c2 - '(' + 1] %= mod;
                    } else if (c2 != ')') {
                        dp[l][r - 1][c - '(' + 1][0] += dp[l][r][c - '(' + 1][c2 - '(' + 1];
                        dp[l][r - 1][c - '(' + 1][0] %= mod;
                    } else {
                        ans += mul(pw[get(l + 1, r - 1)], dp[l][r][c - '(' + 1][c2 - '(' + 1]);
                        ans %= mod;
                        dp[l + 1][r - 1][0][0] += dp[l][r][c - '(' + 1][c2 - '(' + 1];
                        dp[l + 1][r - 1][0][0] %= mod;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}