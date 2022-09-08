#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 55, inf = 1111111111;

int t, n, m, k, dp[max_n][max_n][max_n];

int get_dp(int n, int m, int k) {
    if (dp[n][m][k] != -1) {
        return dp[n][m][k];
    }
    if (n * m < k) {
        dp[n][m][k] = inf;
        return inf;
    }
    if (n * m == k || k == 0) {
        dp[n][m][k] = 0;
        return 0;
    }
    dp[n][m][k] = inf;
    for (int i = 1; i < n; ++i) {
        for (int k1 = 0; k1 <= k; ++k1) {
            dp[n][m][k] = min(dp[n][m][k], get_dp(i, m, k1) + get_dp(n - i, m, k - k1) + m * m);
        }
    }
    for (int i = 1; i < m; ++i) {
        for (int k1 = 0; k1 <= k; ++k1) {
            dp[n][m][k] = min(dp[n][m][k], get_dp(n, i, k1) + get_dp(n, m - i, k - k1) + n * n);
        }
    }
    return dp[n][m][k];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        printf("%d\n", get_dp(n, m, k));
    }
    return 0;
}