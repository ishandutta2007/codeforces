// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, k, dp[5005][5005], a[5005], b[5005], c[5005], f[5005];
std::vector<int> to[5005];
int F(int x) { return x < 0 ? -1 : x; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i] >> b[i] >> c[i], f[i] = i;
    for (int i = 1, x, y; i <= m; ++i)
        std::cin >> x >> y, f[y] = std::max(f[y], x);
    for (int i = 1; i <= n; ++i)
        to[f[i]].push_back(i);
    for (int i = 1; i <= n; ++i)
        std::sort(to[i].begin(), to[i].end(), [&](const int &x, const int &y)
                  { return c[x] > c[y]; });
    std::memset(dp, 0xf0, sizeof(dp));
    dp[0][k] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = a[i]; j <= 5000; ++j)
            if (dp[i - 1][j] >= 0)
                for (int k = 0, s = 0; true; s += c[to[i][k++]])
                {
                    dp[i][j + b[i] - k] = std::max(dp[i][j + b[i] - k], dp[i - 1][j] + s);
                    if (k == std::min(int(to[i].size()), j + b[i]))
                        break;
                }
    std::cout << F(*std::max_element(dp[n], dp[n] + 5005)) << std::endl;
    return 0;
}