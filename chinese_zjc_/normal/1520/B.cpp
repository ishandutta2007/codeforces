// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string n;
int T;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        int ans = 0;
        for (char i = '1'; i <= '9'; ++i)
        {
            std::string s(1, i);
            while (s.size() <= n.size())
            {
                if (s.size() < n.size() || s <= n)
                    ++ans;
                s += i;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}