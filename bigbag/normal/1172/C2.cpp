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

int n, m, a[max_n], w[max_n];
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
        scanf("%d", &w[i]);
        s[a[i]] += w[i];
    }
    calc_dp();
    e[0] = mul(e[0], inv(s[0]));
    e[1] = mul(e[1], inv(s[1]));
    for (int i = 0; i < n; ++i) {
        printf("%d\n", mul(e[a[i]], w[i]));
    }
    return 0;
}