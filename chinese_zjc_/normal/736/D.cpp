// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, x[500005], y[500005];
std::bitset<2000> a[2000], b[2000];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != m; ++i)
    {
        std::cin >> x[i] >> y[i];
        a[--x[i]].set(--y[i]);
    }
    for (int i = 0; i != n; ++i)
        b[i].set(i);
    for (int i = 0; i != n; ++i)
    {
        for (int j = i; j != n; ++j)
            if (a[j][i])
            {
                std::swap(a[i], a[j]);
                std::swap(b[i], b[j]);
                break;
            }
        for (int j = 0; j != n; ++j)
            if (i != j && a[j][i])
                a[j] ^= a[i], b[j] ^= b[i];
    }
    for (int i = 0; i != m; ++i)
        std::cout << (b[y[i]][x[i]] ? "NO" : "YES") << '\n';
    return 0;
}