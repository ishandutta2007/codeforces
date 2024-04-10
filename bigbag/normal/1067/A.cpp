#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, mod = 998244353;
const int max_x = 201;

int n, a[max_n], q1 = 0, q2 = 1, dp[2][2][max_x], sum[2][2][max_x];

void calc_sum(int dp[max_x], int sum[max_x]) {
    sum[0] = dp[0];
    for (int i = 1; i < max_x; ++i) {
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
}

int get_sum(int q, int tp, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == 0) {
        return sum[q][tp][r];
    }
    return (sum[q][tp][r] + mod - sum[q][tp][l - 1]) % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    dp[q1][1][0] = 1;
    calc_sum(dp[q1][0], sum[q1][0]);
    calc_sum(dp[q1][1], sum[q1][1]);
    for (int i = 0; i < n; ++i) {
        memset(dp[q2], 0, sizeof(dp[q2]));
        for (int x = 1; x < max_x; ++x) {
            if (a[i] == -1 || a[i] == x) {
                dp[q2][0][x] = (get_sum(q1, 0, 0, x - 1) + get_sum(q1, 1, 0, x - 1)) % mod;
                dp[q2][1][x] = (get_sum(q1, 1, x, max_x - 1) + dp[q1][0][x]) % mod;
            }
        }
        swap(q1, q2);
        calc_sum(dp[q1][0], sum[q1][0]);
        calc_sum(dp[q1][1], sum[q1][1]);
    }
    printf("%d\n", sum[q1][1][max_x - 1]);
    return 0;
}