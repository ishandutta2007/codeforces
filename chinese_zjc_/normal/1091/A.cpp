// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int a, b, c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b >> c;
    std::cout << std::min({a + 1, b, c - 1}) * 3 << std::endl;
    return 0;
}