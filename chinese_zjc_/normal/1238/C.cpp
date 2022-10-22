// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, h, n, x[200005], dp[600005];
bool a[600005];
std::vector<int> app;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> h >> n;
        app.clear();
        for (int i = 1; i <= n; ++i)
            std::cin >> x[i], app.push_back(x[i]), app.push_back(x[i] + 1), app.push_back(x[i] - 1);
        app.push_back(0);
        app.push_back(1);
        app.push_back(2);
        std::sort(app.begin(), app.end());
        app.erase(std::unique(app.begin(), app.end()), app.end());
        std::fill(a, a + app.size(), false);
        for (int i = 1; i <= n; ++i)
            a[std::lower_bound(app.begin(), app.end(), x[i]) - app.begin()] = true;
        std::fill(dp, dp + app.size(), INT_MAX / 2);
        dp[h = std::lower_bound(app.begin(), app.end(), h) - app.begin()] = 0;
        for (int i = h - 1; i >= 0; --i)
            if (a[i])
                dp[i] = std::min(dp[i + 1] + 1, dp[i + 2] + !a[i + 1]);
            else
                dp[i] = dp[i + 1];
        // std::cout << dp[3] << ' ' << dp[2] << std::endl;
        std::cout << std::min(dp[1], dp[2]) << std::endl;
    }
    return 0;
}