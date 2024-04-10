// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long a, b, c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b >> c;
    std::cout << std::max(0ll, c * (c + 1) / 2 * a - b) << std::endl;
    return 0;
}