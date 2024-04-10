// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, x, a[100005], b[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> x;
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            b[i] = a[i];
        }
        std::sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; ++i)
            if (i - x < 1 && i + x > n && b[i] != a[i])
                flag = false;
        std::cout << (flag ? "YES" : "NO") << std::endl;
    }
    return 0;
}