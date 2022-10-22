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
        int v = 0;
        bool flag = s.back() == 'B';
        for (std::size_t i = 0; i != s.size(); ++i)
        {
            v += s[i] == 'A' ? +1 : -1;
            if (v < 0)
                flag = false;
        }
        std::cout << (flag ? "YES" : "NO") << std::endl;
    }
    return 0;
}