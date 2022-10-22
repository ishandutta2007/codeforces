// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n + n; ++j)
            {
                if (j < n)
                    std::cout << '(';
                else if (j == n + n)
                    std::cout << ')';
                else if (j == n + i - 1)
                    std::cout << '(';
                else
                    std::cout << ')';
            }
            std::cout << std::endl;
        }
    }
    return 0;
}