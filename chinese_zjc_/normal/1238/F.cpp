// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> to[300005];
int T, n, dp[300005][3], ans;
void dfs(int now, int fa = 0)
{
    dp[now][0] = dp[now][1] = dp[now][2] = 1;
    for (auto i : to[now])
        if (i != fa)
        {
            dfs(i, now);
            dp[now][2] = std::max(dp[now][2] + 1, dp[now][1] + dp[i][1]);
            dp[now][1] = std::max(dp[now][1] + 1, dp[now][0] + dp[i][1]);
            dp[now][0] = dp[now][0] + 1;
        }
    ans = std::max(ans, dp[now][2] + bool(fa));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1, x, y; i < n; ++i)
        {
            std::cin >> x >> y;
            to[x].push_back(y);
            to[y].push_back(x);
        }
        ans = 0;
        dfs(1);
        std::cout << ans << std::endl;
        for (int i = 1; i <= n; ++i)
            to[i].clear();
    }
    return 0;
}