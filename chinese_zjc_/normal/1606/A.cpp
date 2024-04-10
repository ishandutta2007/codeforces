// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> s;
        std::cout << s.back() << s.substr(1, s.size() - 1) << std::endl;
    }
    return 0;
}