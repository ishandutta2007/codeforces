// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], c[30];
bool check(int x)
{
    for (int i = 0; i != 30; ++i)
        if (c[i] % x)
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            for (int j = 0; j != 30; ++j)
                if (a[i] >> j & 1)
                    ++c[j];
        }
        for (int i = 1; i <= n; ++i)
            if (check(i))
                std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}