// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, k, a[1005], match[1005], vis[1005], tim;
std::vector<int> edge[1005];
bool work(int now)
{
    if (tim == vis[now])
        return false;
    vis[now] = tim;
    while (!edge[now].empty())
    {
        int t = edge[now].back();
        edge[now].pop_back();
        if (!~match[t] || work(match[t]))
            return match[match[t] = now] = t, true;
    }
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    std::sort(a, a + n);
    std::reverse(a, a + n);
    k = std::find_if(a, a + n, [&](const int &X)
                     { return X < (m + 2) / 3; }) -
        a;
    for (int i = 0; i != k; ++i)
        for (int j = k; j != n; ++j)
            if (a[i] % a[j] == 0 && 2ll * a[i] + a[j] <= m)
                edge[i].push_back(j);
    std::memset(match, -1, sizeof(match));
    for (int i = 0; i != k; ++i)
        if (!~match[i] && ++tim && !work(i))
            return std::cout << -1 << std::endl, 0;
    std::cout << n - k << std::endl;
    for (int i = 0; i != k; ++i)
        std::cout << 2 * a[i] + a[match[i]] << ' ' << a[i] + a[match[i]] << std::endl;
    for (int i = k; i != n; ++i)
        if (!~match[i])
            std::cout << 3 * a[i] << ' ' << 2 * a[i] << std::endl;
    return 0;
}