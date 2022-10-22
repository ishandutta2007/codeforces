// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[105][105];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        if (n == 2)
        {
            std::cout << -1 << std::endl;
            continue;
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if ((i + j) & 1)
                    a[i][j] = ++cnt;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (~(i + j) & 1)
                    a[i][j] = ++cnt;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                std::cout << a[i][j] << " \n"[j == n];
    }
    return 0;
}