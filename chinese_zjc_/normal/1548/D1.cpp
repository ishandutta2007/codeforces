// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, x[6005], y[6005], c[2][2];
long long ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> x[i] >> y[i];
        ++c[x[i] >> 1 & 1][y[i] >> 1 & 1];
    }
    for (int x1 = 0; x1 != 2; ++x1)
        for (int y1 = 0; y1 != 2; ++y1)
            for (int x2 = 0; x2 != 2; ++x2)
                for (int y2 = 0; y2 != 2; ++y2)
                    for (int x3 = 0; x3 != 2; ++x3)
                        for (int y3 = 0; y3 != 2; ++y3)
                            if (((x1 ^ x2) & (y1 ^ y2)) ^ ((x1 ^ x3) & (y1 ^ y3)) ^ ((x2 ^ x3) & (y2 ^ y3)) ^ true)
                            {
                                int x = c[x1][y1];
                                int y = c[x2][y2] - (x1 == x2 && y1 == y2);
                                int z = c[x3][y3] - (x1 == x3 && y1 == y3) - (x2 == x3 && y2 == y3);
                                // std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << std::endl;
                                ans += 1ll * x * y * z;
                            }
    // std::cout << ans << std::endl;
    std::cout << ans / 6 << std::endl;
    return 0;
}