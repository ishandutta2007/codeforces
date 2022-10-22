// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
char c[80][80];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        n = 8;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                std::cin >> c[i][j];
        for (int i = 1; i <= n; ++i)
        {
            int cnt[128];
            std::memset(cnt, 0, sizeof(cnt));
            for (int j = 1; j <= n; ++j)
                ++cnt[(int)c[i][j]];
            if (cnt['R'] == 8)
            {
                std::cout << 'R' << std::endl;
                goto next;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            int cnt[128];
            std::memset(cnt, 0, sizeof(cnt));
            for (int j = 1; j <= n; ++j)
                ++cnt[(int)c[j][i]];
            if (cnt['B'] == 8)
            {
                std::cout << 'B' << std::endl;
                goto next;
            }
        }
    next:;
    }
    return 0;
}