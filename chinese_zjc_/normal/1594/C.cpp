// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string s;
int T, n;
char c;
bool check(int x)
{
    for (int i = x; i <= n; i += x)
        if (s[i] != c)
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> c >> s;
        if (std::count(s.begin(), s.end(), c) == n)
        {
            std::cout << 0 << std::endl;
            goto next;
        }
        s = ' ' + s;
        for (int i = 1; i <= n; ++i)
            if (check(i))
            {
                std::cout << 1 << std::endl
                          << i << std::endl;
                goto next;
            }
        std::cout << 2 << std::endl
                  << n - 1 << ' ' << n << std::endl;
    next:;
    }
    return 0;
}