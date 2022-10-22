// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
int a[200005], b[200005], t[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::fill(t + 1, t + 1 + n, 0);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
            std::cin >> b[i];
        bool flag = true;
        for (int i = 1, j = 0; i <= n; ++i)
        {
            while (j <= n && (a[j] != b[i] || !t[b[i]]))
                ++t[a[++j]];
            if (j > n)
                flag = false;
            --t[b[i]];
        }
        std::cout << (flag ? "YES" : "NO") << std::endl;
    }
    return 0;
}