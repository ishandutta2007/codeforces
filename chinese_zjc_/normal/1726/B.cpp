// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, m;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        if ((n % 2 == 0 && m % 2) || n > m)
            std::cout << "NO" << std::endl;
        else
        {
            std::cout << "YES" << std::endl;
            int k = n & 1 ? n - 1 : n - 2;
            for (int i = 1; i <= k; ++i)
                std::cout << 1 << ' ';
            if (n & 1)
                std::cout << m - n + 1 << std::endl;
            else
                std::cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << std::endl;
        }
    }
    return 0;
}