// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, a, b, c;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> s;
        a = std::count(s.begin(), s.end(), 'A');
        b = std::count(s.begin(), s.end(), 'B');
        c = std::count(s.begin(), s.end(), 'C');
        std::cout << (b == a + c ? "YES" : "NO") << std::endl;
    }
    return 0;
}