// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
long long a, b, x;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> a >> b >> x;
        bool flag = false;
        while (b)
        {
            if (a >= x && (a - x) % b == 0)
                flag = true;
            a %= b;
            if (b > x && (a + x) % b == 0)
                flag = true;
            std::swap(a, b);
        }
        std::cout << (flag ? "YES" : "NO") << std::endl;
    }
    return 0;
}