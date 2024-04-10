// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int n, a[300005];
long long dp[300005][3], x, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = std::max(dp[i - 1][0] + a[i], 0ll);
        dp[i][1] = std::max(std::max(dp[i - 1][1], dp[i - 1][0]) + a[i] * x, 0ll);
        dp[i][2] = std::max(std::max(dp[i - 1][1], dp[i - 1][2]) + a[i], 0ll);
        ans = std::max(ans, *std::max_element(dp[i], dp[i] + 3));
    }
    std::cout << ans << std::endl;
    return 0;
}