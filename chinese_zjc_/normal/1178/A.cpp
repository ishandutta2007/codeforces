// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[105], sum;
bool vis[105];
int SUM()
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += a[i];
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    sum = a[1];
    vis[1] = true;
    for (int i = 1; i <= n; ++i)
        if (!vis[i] && a[1] >= a[i] * 2)
            vis[i] = true, sum += a[i];
    if (sum * 2 <= SUM())
        std::cout << 0 << std::endl;
    else
    {
        std::cout << std::count(vis + 1, vis + 1 + n, true) << std::endl;
        for (int i = 1; i <= n; ++i)
            if (vis[i])
                std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}