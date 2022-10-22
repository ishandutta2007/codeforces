// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, ans;
long long sum[100005];
std::vector<int> dp[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> sum[i], sum[i] += sum[i - 1];
        dp[0].assign(1, 100002);
        for (int i = 1; true; ++i)
        {
            for (int j = i, k = 0; j <= n; ++j)
            {
                while (k != int(dp[i - 1].size()) && j > dp[i - 1][k] - i + 1)
                    ++k;
                if (k == int(dp[i - 1].size()))
                    break;
                if (sum[j] - sum[j - i] < (i == 1 ? LLONG_MAX : sum[dp[i - 1][k]] - sum[dp[i - 1][k] - i + 1]))
                {
                    while (!dp[i].empty() && sum[dp[i].back()] - sum[dp[i].back() - i] <= sum[j] - sum[j - i])
                        dp[i].pop_back();
                    dp[i].push_back(j);
                }
            }
            dp[i - 1].clear();
            if (dp[i].empty())
            {
                std::cout << i - 1 << std::endl;
                break;
            }
        }
    }
    return 0;
}