// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, x, y;
long long get(long long x, long long y)
{
    if (x <= y)
    {
        if (x * 3 <= y)
            return y - (y % x + x) / 2;
        else
            return (x + y) / 2;
    }
    else
        return x + y;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> x >> y;
        std::cout << get(x, y) << std::endl;
        // for (int x = 2; x <= 20000; x += 2)
        //     for (int y = 2; y <= 20000; y += 2)
        //     {
        //         int tmp = get(x, y);
        //         if (tmp % x != y % tmp)
        //             std::cout << x << ' ' << y << ' ' << tmp << std::endl;
        //     }
    }
    return 0;
}