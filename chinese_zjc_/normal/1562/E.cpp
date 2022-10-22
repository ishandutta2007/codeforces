// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int lcp[5005][5005], dp[5005], T, n;
char c[5005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> (c + 1);
        for (int i = 1; i <= n + 1; ++i)
            lcp[i][n + 1] = lcp[n + 1][i] = 0;
        for (int i = n; i; --i)
            for (int j = n; j; --j)
                lcp[i][j] = c[i] == c[j] ? lcp[i + 1][j + 1] + 1 : 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = n - i + 1;
            for (int j = 1; j < i; ++j)
                if (c[i + lcp[i][j]] > c[j + lcp[i][j]])
                    dp[i] = std::max(dp[i], dp[j] + n - i + 1 - lcp[i][j]);
            ans = std::max(dp[i], ans);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}