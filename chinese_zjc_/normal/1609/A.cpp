// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long T, n, a[20], tim;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        tim = 0;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            while (a[i] % 2 == 0)
                a[i] /= 2, ++tim;
        }
        std::sort(a + 1, a + 1 + n);
        while (tim)
            a[n] *= 2, --tim;
        std::cout << std::accumulate(a + 1, a + 1 + n, 0ll) << std::endl;
    }
    return 0;
}