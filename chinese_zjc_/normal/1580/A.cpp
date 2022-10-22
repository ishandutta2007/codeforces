// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, ans, sum[2][405][405];
char a[405][405];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                std::cin >> a[i][j];
                sum[0][i][j] = sum[0][i - 1][j] + (a[i][j] == '0');
                sum[1][i][j] = sum[1][i - 1][j] + (a[i][j] == '1');
            }
        ans = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 4; j <= n; ++j)
            {
                for (int k = 1, min = INT_MAX / 2; k + 3 <= m; ++k)
                {
                    min = std::min(min + sum[1][j - 1][k] - sum[1][i][k] + (a[i][k] != '1') + (a[j][k] != '1'),
                                   sum[0][j - 1][k] - sum[0][i][k]);
                    ans = std::min(ans, min + sum[1][j - 1][k + 2] - sum[1][i][k + 2] +
                                            (a[i][k + 1] != '1') + (a[j][k + 1] != '1') +
                                            sum[1][j - 1][k + 1] - sum[1][i][k + 1] +
                                            (a[i][k + 2] != '1') + (a[j][k + 2] != '1') +
                                            sum[0][j - 1][k + 3] - sum[0][i][k + 3]);
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}