// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int r, x, y, xx, yy;
long long sqr(long long x) { return x * x; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> r >> x >> y >> xx >> yy;
    std::cout << std::ceil(std::sqrt(sqr(x - xx) + sqr(y - yy)) / r / 2) << std::endl;
    return 0;
}