// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const std::string ss[] = {"00", "52", "05", "57"};
int T;
std::size_t ans;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> s;
        std::reverse(s.begin(), s.end());
        ans = INT_MAX;
        for (int i = 0; i != 4; ++i)
        {
            std::size_t pos = 0;
            pos = s.find(ss[i][0], pos);
            if (pos == std::string::npos)
                continue;
            pos = s.find(ss[i][1], pos + 1);
            if (pos == std::string::npos)
                continue;
            ans = std::min(ans, pos - 1);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}