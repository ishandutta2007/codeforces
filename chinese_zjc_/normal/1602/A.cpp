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
        std::string::iterator min = std::min_element(s.begin(), s.end());
        std::cout << *min << ' ' << s.substr(0, min - s.begin()) << s.substr(min - s.begin() + 1) << std::endl;
    }
    return 0;
}