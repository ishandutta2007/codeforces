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
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        unsigned ans = -1;
        for (int i = 0; i != n; ++i)
            if (i != a[i])
                ans &= i & a[i];
        std::cout << ans << std::endl;
    }
    return 0;
}