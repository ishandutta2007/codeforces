// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, ans;
bool a[505][505];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            static char c;
            std::cin >> c;
            a[i][j] = c == 'B';
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ans += a[i][j] ^= a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            if (a[i][j] && a[i][m] && a[n][j] && a[n][m])
            {
                std::cout << ans - 1 << std::endl;
                return 0;
            }
    std::cout << ans << std::endl;
    return 0;
}