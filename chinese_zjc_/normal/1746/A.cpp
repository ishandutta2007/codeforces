// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, k, a[55];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        int cnt = std::count(a + 1, a + 1 + n, 1);
        std::cout << (cnt ? "YES" : "NO") << std::endl;
    }
    return 0;
}