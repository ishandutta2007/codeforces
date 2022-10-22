// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int c[2000005], n, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, v; i <= n; ++i)
        std::cin >> v, ++c[v];
    for (int i = 0; i <= 2000000; ++i)
    {
        c[i + 1] += c[i] / 2;
        ans += c[i] & 1;
    }
    std::cout << ans << std::endl;
    return 0;
}