// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
bool app[26];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::fill(app, app + 26, false);
        for (int i = 0; i != 4; ++i)
        {
            static char c;
            std::cin >> c;
            app[c - 'a'] = true;
        }
        std::cout << (std::count(app, app + 26, true) - 1) << std::endl;
    }
    return 0;
}