#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 998244353;
const int max_m = 3033;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int power(int a, int b) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power(mul(a, a), b / 2);
    }
    return mul(a, power(a, b - 1));
}

int inv(int x) {
    return power(x, mod - 2);
}

int n, m, a[max_n], w[2][max_n];
int s[2], dp[2][max_m], e[2];

void calc_dp() {
    int q1 = 0, q2 = 1;
    dp[q1][0] = 1;
    for (int i = 0; i < m; ++i) {
        memset(dp[q2], 0, sizeof(dp[q2]));
        for (int c0 = 0; c0 <= i; ++c0) {
            if (!dp[q1][c0]) {
                continue;
            }
            int c1 = i - c0;
            int s0 = s[0] - c0;
            int s1 = s[1] + c1;
            int tot = inv(s0 + s1);
            int p0 = mul(s0, tot);
            int p1 = mul(s1, tot);
            dp[q2][c0] += mul(dp[q1][c0], p1);
            dp[q2][c0] %= mod;
            dp[q2][c0 + 1] += mul(dp[q1][c0], p0);
            dp[q2][c0 + 1] %= mod;
        }
        swap(q1, q2);
    }
    for (int c0 = 0; c0 <= m; ++c0) {
        if (!dp[q1][c0]) {
            continue;
        }
        int c1 = m - c0;
        e[0] += mul(s[0] - c0, dp[q1][c0]);
        e[1] += mul(s[1] + c1, dp[q1][c0]);
        e[0] %= mod;
        e[1] %= mod;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[0][i]);
        s[a[i]] += w[0][i];
    }
    calc_dp();

    int q1 = 0, q2 = 1;
    for (int i = 0; i < 0; ++i) {
        int r0 = inv(s[0] - i);
        int r1 = inv(s[1] + i);
        for (int j = 0; j < n; ++j) {
            if (a[j] == 0) {
                if (i >= s[0]) {
                    w[q2][j] = w[q1][j];
                } else {
                    int p = mul(w[q1][j], r0);
                    w[q2][j] = (mul(w[q1][j] + mod - 1, p) + mul(w[q1][j], 1 + mod - p)) % mod;
                }
            } else {
                int p = mul(w[q1][j], r1);
                w[q2][j] = (mul(w[q1][j] + 1, p) + mul(w[q1][j], 1 + mod - p)) % mod;
            }
        }
        swap(q1, q2);
    }
    s[0] = s[1] = 0;
    for (int i = 0; i < n; ++i) {
        s[a[i]] += w[q1][i];
        s[a[i]] %= mod;
    }
    e[0] = mul(e[0], inv(s[0]));
    e[1] = mul(e[1], inv(s[1]));
    for (int i = 0; i < n; ++i) {
        printf("%d\n", mul(e[a[i]], w[q1][i]));
    }
    return 0;
}