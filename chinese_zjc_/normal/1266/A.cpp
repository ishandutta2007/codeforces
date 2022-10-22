// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::string s;
        std::cin >> s;
        int s1 = 0;
        bool flag1 = false, flag2 = false;
        for (auto i : s)
        {
            if (i != '0' || flag2)
                flag1 |= i % 2 == 0;
            flag2 |= i == '0';
            s1 = (s1 + i) % 3;
        }
        if (s1 == 0 && flag1 && flag2)
            std::cout << "red" << std::endl;
        else
            std::cout << "cyan" << std::endl;
    }
    return 0;
}