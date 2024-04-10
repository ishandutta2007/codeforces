#include <bits/stdc++.h>

using namespace std;

int mod;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int power(int a, int b) {
    int res = 1 % mod;
    while (b) {
        if (b % 2) {
            res = mul(res, a);
        }
        b /= 2;
        a = mul(a, a);
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

const int max_f = 505;

int f[max_f], rf[max_f];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_f; ++i) {
        f[i] = mul(i, f[i - 1]);
    }
    rf[max_f - 1] = inv(f[max_f - 1]);
    for (int i = max_f - 2; i > 0; --i) {
        rf[i] = mul(i + 1, rf[i + 1]);
    }
}

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    return mul(f[n], mul(rf[k], rf[n - k]));
}

const int max_n = 505;

int n, m, ways[max_n], sum[max_n];
int dp[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> mod;
    get_all_f();
    ways[0] = 1;
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int a = 0; a < i; ++a) {
            const int b = i - 1 - a;
            int cnt = mul(ways[a], mul(ways[b], get_c(i - 1, a)));
            inc(ways[i], mul(cnt, i + 1));
            inc(sum[i], mul(cnt, get_c(a + 1, 2) + get_c(b + 1, 2)));
            inc(sum[i], mul(i + 1, mul(get_c(i - 1, a), mul(ways[b], sum[a]))));
            inc(sum[i], mul(i + 1, mul(get_c(i - 1, a), mul(ways[a], sum[b]))));
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = ways[i];
        for (int tot = 0; tot < i; ++tot) {
            dp[i][tot] = dp[i - 1][tot];
            for (int len = 1; len <= tot; ++len) {
                inc(dp[i][tot], mul(ways[len], mul(dp[i - len - 1][tot - len], get_c(tot, len))));
            }
        }
    }
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            const int a = max(0, l - 1), b = max(0, n - 2 - r), len = r - l + 1;
            for (int c1 = 0; c1 + len <= m && c1 <= a; ++c1) {
                const int c2 = m - c1 - len;
                if (c2 <= b) {
                    inc(ans, mul(sum[len], mul(dp[a][c1], mul(dp[b][c2], mul(f[m], mul(rf[c1], mul(rf[c2], rf[len])))))));
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}