// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, pre[2][1000005], T, q, l, r;
char c[1000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> (c + 1);
        n = strlen(c + 1);
        for (int i = 1; i <= n; ++i)
        {
            pre[0][i] = pre[0][i - 1];
            pre[1][i] = pre[1][i - 1];
            if (c[i] == '[' || c[i] == ']')
                ++pre[i & 1][i];
        }
        std::cin >> q;
        while (q--)
        {
            std::cin >> l >> r;
            --l;
            std::cout << std::abs(pre[1][r] - pre[1][l] - pre[0][r] + pre[0][l]) << std::endl;
        }
    }
    return 0;
}