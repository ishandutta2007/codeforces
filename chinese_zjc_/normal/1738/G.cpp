// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, k, lst[2005], dp[1005][1005];
bool a[1005][1005], b[1005][1005];
void del(int x, int left)
{
    if (left < 0)
        return;
    for (int i = std::max(lst[x + 1] + 1, lst[x - 1]); i <= n; ++i)
        if (x + i - n >= 1 && x + i - n <= n && a[x + i - n][i])
        {
            lst[x] = i;
            b[x + i - n][i] = true;
            break;
        }
    if (x >= n)
        del(x + 1, left - 1);
    if (x <= n)
        del(x - 1, left - 1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                static char c;
                std::cin >> c;
                a[i][j] = c == '1';
            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                if (!a[i][j])
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        if (dp[n][n] >= k)
            std::cout << "NO" << '\n';
        else
        {
            std::cout << "YES" << '\n';
            for (int i = 1; i <= 2 * n; ++i)
                lst[i] = 0;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    b[i][j] = false;
            for (int i = 1; i <= n - k + 1; ++i)
                del(n, n - k + 1 - i);
            for (int i = 1; i <= n; ++i, std::cout << '\n')
                for (int j = 1; j <= n; ++j)
                    std::cout << !b[i][j];
        }
    }
    return 0;
}