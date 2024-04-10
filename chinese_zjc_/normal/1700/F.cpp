// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[2][200005], b[2][200005], h[2];
long long ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int k = 0; k != 2; ++k)
        for (int i = 0; i != n; ++i)
            std::cin >> a[k][i];
    for (int k = 0; k != 2; ++k)
        for (int i = 0; i != n; ++i)
            std::cin >> b[k][i], a[k][i] -= b[k][i];
    for (int i = 0; i != n; ++i, ans += std::abs(h[0] + h[1]))
    {
        h[0] += a[0][i];
        h[1] += a[1][i];
        while (h[0] > 0 && h[1] < 0)
            --h[0], ++h[1], ++ans;
        while (h[0] < 0 && h[1] > 0)
            ++h[0], --h[1], ++ans;
    }
    if (h[0] || h[1])
        return std::cout << -1 << std::endl, 0;
    std::cout << ans << std::endl;
    return 0;
}