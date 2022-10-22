// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], b[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        for (int i = 0; i != n; ++i)
            std::cin >> b[i];
        bool flag = true;
        for (int i = 0; i != n; ++i)
            flag &= a[i] == b[i] || (a[i] <= b[i] && b[i] <= b[(i + 1) % n] + 1);
        std::cout << (flag ? "YES" : "NO") << std::endl;
    }
    return 0;
}