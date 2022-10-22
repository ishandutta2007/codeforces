// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[100005];
bool ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        bool ans = !(n & 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], ans |= a[i] <= a[i - 1];
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }
    return 0;
}