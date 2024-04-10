// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#define int long long
int n, m, s, a[300005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 2; i <= n; ++i)
        s = std::__gcd(s, a[i] - a[i - 1]);
    for (int i = 1, t; i <= m; ++i)
    {
        std::cin >> t;
        if (s % t == 0)
            return std::cout << "YES" << std::endl
                             << a[1] << ' ' << i << std::endl,
                   0;
    }
    std::cout << "NO" << std::endl;
    return 0;
}