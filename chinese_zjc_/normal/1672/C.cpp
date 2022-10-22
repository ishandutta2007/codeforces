// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        int fir = -1, las = -1;
        for (int i = 1; i < n; ++i)
            if (a[i] == a[i + 1])
            {
                fir = i;
                break;
            }
        for (int i = n; --i;)
            if (a[i] == a[i + 1])
            {
                las = i;
                break;
            }
        if (fir == las)
            std::cout << 0 << std::endl;
        else
            std::cout << std::max(1, las - fir - 1) << std::endl;
    }
    return 0;
}