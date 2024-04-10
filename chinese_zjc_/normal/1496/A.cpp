// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, k;
char a[105];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        bool ans = 2 * k < n;
        for (int i = 1; i <= k; ++i)
            ans &= a[i] == a[n - i + 1];
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }
    return 0;
}