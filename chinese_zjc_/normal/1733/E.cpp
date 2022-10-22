// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, x, y;
long long has[121][121], cnt;
bool is[121][121];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> cnt >> x >> y;
        std::memset(has, 0, sizeof(has));
        std::memset(is, false, sizeof(is));
        cnt -= x + y;
        has[0][0] = cnt + 1;
        is[0][0] = cnt >= 0;
        for (int i = 0; i != 120; ++i)
            for (int j = 0; j != 120; ++j)
            {
                if (has[i][j] & 1)
                    is[i][j + 1] |= is[i][j];
                else
                    is[i + 1][j] |= is[i][j];
                has[i][j + 1] += (has[i][j] + 1) >> 1;
                has[i + 1][j] += has[i][j] >> 1;
            }
        std::cout << (is[x][y] ? "YES" : "NO") << std::endl;
    }
    return 0;
}