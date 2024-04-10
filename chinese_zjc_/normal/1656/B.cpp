// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
long long k, a[200005];
bool check()
{
    for (int i = 1; i <= n; ++i)
        if (std::binary_search(a + 1, a + 1 + n, a[i] + k))
            return true;
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::sort(a + 1, a + 1 + n);
        std::cout << (check() ? "YES" : "NO") << std::endl;
    }
    return 0;
}