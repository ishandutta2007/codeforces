// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
int T, n, c[105], t[105], g[105], tot;
signed main()
{
    std::ios::sync_with_stdio(false);
    t[0] = t[1] = 1;
    for (int i = 2; i <= 90; ++i)
        t[i] = t[i - 1] + t[i - 2];
    std::cin >> T;
    // bool tag = T == 10000;
    while (T--)
    {
        std::cin >> n;
        tot = 0;
        std::memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; ++i)
            std::cin >> c[i], tot += c[i];
        int p = 0;
        while (tot > 0)
            tot -= t[p++];
        if (tot)
        {
            std::cout << "NO" << std::endl;
            goto next;
        }
        for (int i = p, lst = 0; i--;)
        {
            int max = 0;
            for (int j = 1; j <= n; ++j)
                if (c[j] > c[max] && j != lst)
                    max = j;
            if (c[max] >= t[i])
                c[max] -= t[i], lst = max;
            else
            {
                std::cout << "NO" << std::endl;
                goto next;
            }
        }
        std::cout << "YES" << std::endl;
    next:;
    }
    return 0;
}