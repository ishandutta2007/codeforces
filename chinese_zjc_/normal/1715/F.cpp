// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m;
double x, y, S;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    std::cin >> n >> m;
    std::cout << "? " << n * 2 + 2 << std::endl;
    std::cout << 0 << ' ' << -1 << std::endl;
    for (int i = 0; i != n; ++i)
    {
        std::cout << i << ' ' << 0 << std::endl;
        std::cout << i << ' ' << m << std::endl;
    }
    std::cout << n << ' ' << 0 << std::endl;
    std::cin >> y;
    y = m - 0.5 - y * m;
    std::cout << "? " << m * 2 + 2 << std::endl;
    std::cout << -1 << ' ' << 0 << std::endl;
    for (int i = 0; i != m; ++i)
    {
        std::cout << 0 << ' ' << i << std::endl;
        std::cout << n << ' ' << i << std::endl;
    }
    std::cout << 0 << ' ' << m << std::endl;
    std::cin >> x;
    x = n - 0.5 - x * n;
    std::cout << "! " << x << ' ' << y << std::endl;
    return 0;
}