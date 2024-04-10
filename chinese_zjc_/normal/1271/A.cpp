// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int a, b, c, d, e, f, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b >> c >> d >> e >> f;
    for (int i = 0; i <= std::min(a, d); ++i)
        ans = std::max(ans, i * e + std::min({b, c, d - i}) * f);
    std::cout << ans << std::endl;
    return 0;
}