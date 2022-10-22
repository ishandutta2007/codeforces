// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
bool good[26];
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> s;
        std::fill(good, good + 26, false);
        for (std::size_t i = 0, j; i != s.size(); i = j)
        {
            j = s.find_first_not_of(s[i], i);
            if (j == std::string::npos)
                j = s.size();
            if ((j - i) & 1)
                good[s[i] - 'a'] = true;
        }
        for (int i = 0; i != 26; ++i)
            if (good[i])
                std::cout << char(i + 'a');
        std::cout << std::endl;
    }
    return 0;
}