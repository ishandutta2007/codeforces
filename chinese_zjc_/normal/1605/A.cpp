// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, a[3];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> a[0] >> a[1] >> a[2];
        int sum = std::accumulate(a, a + 3, 0);
        if (sum % 3 == 0)
            std::cout << 0 << std::endl;
        else
            std::cout << 1 << std::endl;
    }
    return 0;
}