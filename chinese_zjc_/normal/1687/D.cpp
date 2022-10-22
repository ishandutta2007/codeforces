// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[1000005], low[2000005];
long long sqr(long long x) { return x * x; }
int G(long long x) { return x <= 2000000 ? low[x] : n; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], low[a[i]] = i;
    for (int i = 1; i <= 2000000; ++i)
        if (!low[i])
            low[i] = low[i - 1];
    for (int i = 1; i <= 2000000; ++i)
    {
        long long l = std::max(0ll, sqr(i) - a[1]), r = sqr(i) + i - a[1];
        for (int j = 0, lst = 1; l <= r && lst <= n; ++j, ++lst)
        {
            l = std::max(l, sqr(i + j) - a[lst]);
            int nxt = G(sqr(i + j) + i + j - l);
            r = std::min(r, sqr(i + j) + i + j - a[nxt]);
            lst = nxt;
        }
        if (l <= r)
            return std::cout << l << std::endl, 0;
    }
    return 0;
}