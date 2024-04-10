// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int a[4];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a[0] >> a[1] >> a[2] >> a[3];
    std::sort(a, a + 4);
    std::cout << a[3] - a[0] << ' ' << a[3] - a[1] << ' ' << a[3] - a[2] << std::endl;
    return 0;
}