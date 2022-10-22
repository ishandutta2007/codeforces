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
        std::vector<int> app[26];
        for (int i = 0; i != int(s.size()); ++i)
            app[s[i] - 'a'].push_back(i);
        for (int i = 0; i != int(s.size()); ++i)
            if (app[s[i] - 'a'].back() == i)
            {
                std::cout << s.substr(i) << '\n';
                break;
            }
    }
    return 0;
}