// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<char> c[1000005];
int n, m, q, sum[1000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i <= n; ++i)
        c[i].resize(m + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> c[i][j];
            if (c[i - 1][j] == 'X' && c[i][j - 1] == 'X')
                sum[j] += 1;
        }
    for (int i = 1; i <= m; ++i)
        sum[i] += sum[i - 1];
    std::cin >> q;
    for (int i = 1, l, r; i <= q; ++i)
    {
        std::cin >> l >> r;
        std::cout << (sum[r] - sum[l] ? "NO" : "YES") << std::endl;
    }
    return 0;
}