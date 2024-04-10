// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[105], v[2000005];
bool ans, good[2000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], a[i] += 1000000;
        std::sort(a + 1, a + 1 + n);
        if (std::count(a + 1, a + 1 + n, a[n / 2]) >= n / 2 || std::count(a + 1, a + 1 + n, a[n / 2 + 1]) >= n / 2)
        {
            std::cout << -1 << std::endl;
            continue;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j < i; ++j)
                if (a[i] != a[j])
                    for (int k = 1, p = a[i] - a[j]; k * k <= p; ++k)
                        if (p % k == 0)
                            good[k] = good[p / k] = true;
        for (int i = 2000000; i >= 1; --i)
            if (good[i])
            {
                for (int j = 1; j <= n; ++j)
                    ++v[a[j] % i];
                for (int j = 1; j <= n; ++j)
                {
                    if (v[a[j] % i] >= n / 2)
                        ans = true;
                    --v[a[j] % i];
                }
                if (ans)
                {
                    std::cout << i << std::endl;
                    ans = false;
                    break;
                }
            }
        memset(good, false, sizeof(good));
    }
    return 0;
}