// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[100005];
bool check()
{
    if (std::count(a + 1, a + 1 + n, 1) == 0)
        return true;
    for (int i = 1; i < n; ++i)
        if (a[i] != a[i + 1] && a[i + 1] - a[i] == 1)
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
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::sort(a + 1, a + 1 + n);
        std::cout << (check() ? "YES" : "NO") << std::endl;
    }
    return 0;
}