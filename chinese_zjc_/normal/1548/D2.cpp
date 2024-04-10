// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, x[6005], y[6005], sum[6005][4][4][4];
long long ans[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> x[i] >> y[i];
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            if (i != j)
                ++sum[i][(x[j] - x[i] + 10000000) % 4][(y[j] - y[i] + 10000000) % 4]
                     [std::abs(std::__gcd(x[i] - x[j], y[i] - y[j])) % 4];
    for (int i = 0; i != n; ++i)
        for (int a = 0; a != 64; ++a)
            for (int b = a; b != 64; ++b)
            {
                int x1 = a >> 0 & 3, y1 = a >> 2 & 3, b1 = a >> 4 & 3,
                    x2 = b >> 0 & 3, y2 = b >> 2 & 3, b2 = b >> 4 & 3;
                if ((x1 ^ x2 ^ 1) & 1 && (y1 ^ y2 ^ 1) & 1 && (b1 ^ b2 ^ 1) & 1)
                {
                    int A = (x1 * y2 - x2 * y1 + 16) % 4,
                        B = (b1 + b2 + (x1 == x2 && y1 == y2 ? 0 : 2)) % 4;
                    if ((A ^ 1) & 1 && A == B)
                    {
                        if (a == b)
                            ans[b1 & 1] += sum[i][x1][y1][b1] * (sum[i][x2][y2][b2] - 1) / 2;
                        else
                            ans[b1 & 1] += sum[i][x1][y1][b1] * sum[i][x2][y2][b2];
                    }
                }
            }
    std::cout << ans[0] / 3 + ans[1] << std::endl;
    return 0;
}