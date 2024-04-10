// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, fa[200005], rk[200005], v[200005], root;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> fa[i], root = i == fa[i] ? i : root;
        for (int i = 1; i <= n; ++i)
            std::cin >> rk[i];
        if (rk[1] != root)
        {
            std::cout << -1 << std::endl;
            continue;
        }
        bool flag = true;
        for (int i = 1; i <= n; ++i)
            v[rk[i]] = i - 1;
        for (int i = 1; i <= n; ++i)
            flag &= v[i] - v[fa[i]] >= 0;
        if (!flag)
        {
            std::cout << -1 << std::endl;
            continue;
        }
        for (int i = 1; i <= n; ++i)
            std::cout << v[i] - v[fa[i]] << " \n"[i == n];
    }
    return 0;
}