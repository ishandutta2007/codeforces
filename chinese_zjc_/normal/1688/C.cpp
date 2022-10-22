// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
bool app[26];
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i <= n + n; ++i)
        {
            std::cin >> s;
            for (auto j : s)
                app[j - 'a'] ^= true;
        }
        bool *ans = std::find(app, app + 26, true);
        std::cout << char(ans - app + 'a') << std::endl;
        *ans = false;
    }
    return 0;
}