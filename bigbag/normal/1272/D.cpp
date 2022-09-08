#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], dp[max_n][2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[i][0] = max(dp[i][0], 1);
        if (a[i] < a[i + 1]) {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + 1);
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + 1);
        }
        if (a[i] < a[i + 2]) {
            dp[i + 2][1] = max(dp[i + 2][1], dp[i][0] + 1);
        }
        ans = max(dp[i][0], ans);
        ans = max(dp[i][1], ans);
    }
    printf("%d\n", ans);
    return 0;
}