// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, k;
std::string d;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k >> d;
        int f = d.find('1'), l = d.find_last_of('1'), c = std::count(d.begin(), d.end(), '1');
        if (c == 0)
            std::cout << 0 << std::endl;
        else if (f == l)
        {
            if (n - 1 - l <= k)
                std::cout << 1 << std::endl;
            else if (f <= k)
                std::cout << 10 << std::endl;
            else
                std::cout << 11 << std::endl;
        }
        else
        {
            int ans = c * 11;
            if (n - 1 - l <= k)
                ans -= 10, k -= n - 1 - l;
            if (f <= k)
                ans -= 1, k -= f;
            std::cout << ans << std::endl;
        }
    }
    return 0;
}