// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[1005][5];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        bool ans = false;
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != 5; ++j)
                std::cin >> a[i][j];
        for (int i = 0; i != 5; ++i)
        {
            for (int j = i + 1; j != 5; ++j)
            {
                int s[4];
                memset(s, 0, sizeof(s));
                for (int k = 0; k != n; ++k)
                    ++s[a[k][i] << 1 | a[k][j]];
                if (!s[0] && s[1] <= n / 2 && s[2] <= n / 2)
                    ans = true;
            }
        }
        std::cout << (ans && !(n & 1) ? "YES" : "NO") << std::endl;
    }
    return 0;
}