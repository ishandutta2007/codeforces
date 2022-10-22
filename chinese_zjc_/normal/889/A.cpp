// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int f, n;
bool has[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> f, has[f] = true;
    std::cout << std::count(has, has + 1 + n, false) << std::endl;
    return 0;
}