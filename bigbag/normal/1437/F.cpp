#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, mod = 998244353;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int n, a[max_n], c_less[max_n], dp[max_n][max_n], sum[max_n][max_n];
int pr[max_n];

void calc_sum(int c) {
    for (int i = 0; i < n; ++i) {
        sum[c][i] = dp[c][i];
        if (i) {
            inc(sum[c][i], sum[c][i - 1]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        pr[i] = -1;
        for (int j = 0; j < n; ++j) {
            if (2 * a[j] <= a[i]) {
                pr[i] = j;
                ++c_less[i];
            }
        }
        dp[1][i] = 1;
    }
    for (int cnt = 1; cnt <= n; ++cnt) {
        for (int mx = 0; mx < n; ++mx) {
            if (pr[mx] != -1) {
                inc(dp[cnt][mx], sum[cnt - 1][pr[mx]]);
            }
            int add = c_less[mx] - (cnt - 1);
            if (add > 0) {
                inc(dp[cnt + 1][mx], mul(dp[cnt][mx], add));
            }
        }
        calc_sum(cnt);
    }
    printf("%d\n", dp[n][n - 1]);
    return 0;
}