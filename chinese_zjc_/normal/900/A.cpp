// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int cnt[2], n, x, y;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> x >> y, ++cnt[x > 0];
    std::cout << (std::min(cnt[0], cnt[1]) <= 1 ? "YES" : "NO") << std::endl;
    return 0;
}