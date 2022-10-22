// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, good;
long long dp[5000005];
bool has[5000005];
void add(int v)
{
    for (int i = 1; i * v <= m; ++i)
    {
        if (has[i * v])
            good -= bool(dp[i * v]);
        dp[i * v] += dp[i];
        if (has[i * v])
            good += bool(dp[i * v]);
    }
}
void del(int v)
{
    for (int i = m / v; i; --i)
    {
        if (has[i * v])
            good -= bool(dp[i * v]);
        dp[i * v] -= dp[i];
        if (has[i * v])
            good += bool(dp[i * v]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        std::fill(has, has + 1 + m, false);
        std::fill(dp, dp + 1 + m, 0);
        for (int i = 1, a; i <= n; ++i)
            std::cin >> a, has[a] = true;
        n = std::count(has + 1, has + 1 + m, true);
        good = has[1];
        dp[1] = 1;
        int ans = m;
        for (int i = has[1] ? 1 : 2, j = 2; i <= m; del(i++))
        {
            while (j <= m && good < n)
                add(j++);
            if (good == n)
                ans = std::min(ans, j - i - 1);
            if (i == 1)
                break;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}