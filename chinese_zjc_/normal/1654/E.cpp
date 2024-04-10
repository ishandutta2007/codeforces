// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int B = 350;
int n, a[100005], ans, g[80000005], *map = g + 40000002;
void work()
{
    for (int i = 0; i <= B; ++i)
    {
        for (int j = 1; j <= n; ++j)
            ans = std::min(ans, n - ++map[a[j] - (i - 1) * j]);
        for (int j = 1; j <= n; ++j)
            map[a[j] - (i - 1) * j] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = std::max(1, i - B); j <= n && j - i <= B; ++j)
            if (i != j && (a[j] - a[i]) % (j - i) == 0)
                ans = std::min(ans, n - ++map[(a[j] - a[i]) / (j - i)] - 1);
        for (int j = std::max(1, i - B); j <= n && j - i <= B; ++j)
            if (i != j && (a[j] - a[i]) % (j - i) == 0)
                map[(a[j] - a[i]) / (j - i)] = 0;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    // n = 100000;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i]; // a[i] = rand();
    ans = n;
    work();
    std::reverse(a + 1, a + 1 + n);
    work();
    std::cout << ans << std::endl;
    return 0;
}