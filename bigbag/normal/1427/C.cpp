#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int r, n, t[max_n], x[max_n], y[max_n], dp[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &r, &n);
    x[0] = 1;
    y[0] = 1;
    ++n;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &t[i], &x[i], &y[i]);
    }
    for (int i = 1; i < n; ++i) {
        dp[i] = -inf;
        for (int j = max(0, i - 2022); j < i; ++j) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                //cout << dp[i] << ", p = " << j << endl;
            }
        }
    }
    printf("%d\n", *max_element(dp, dp + n));
    return 0;
}