#include <bits/stdc++.h>
const int N = 505;
int f[N][N][N], a[N];

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int k = 0; k <= n; ++k)
            {
                f[i][j][k] = -1e9;
            }
        }
    }
    f[0][0][1] = 0;

    for (int i = 1; i <= n; ++i)
    {

        for (int j = 0; j < i; ++j)
        {
            for (int k = i - j - 1; k <= n; ++k)
            {
                f[i][j + 1][k - i + j + 2] = std::max(f[i][j + 1][k - i + j + 2], f[i - 1][j][k] + a[i]);
            }
        }

        for (int j = 0; j <= n; ++j)
        {
            for (int k = 0; k <= n; ++k)
            {
                f[i][j + 1][k] = std::max(f[i][j + 1][k], f[i][j][k] + a[i]);
            }
        }

        for (int j = 0; j <= n; ++j)
        {
            for (int k = 0; k <= n; ++k)
            {
                f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][k]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans = std::max(ans, f[n][n][i]);
    }

    std::cout << ans << '\n';
    return 0;
}