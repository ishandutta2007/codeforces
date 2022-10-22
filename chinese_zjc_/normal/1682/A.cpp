// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> s;
        int l = n / 2, r = n / 2;
        while (l && s[l - 1] == s[r])
            --l;
        while (r < n && s[l] == s[r])
            ++r;
        std::cout << r - l << std::endl;
    }
    return 0;
}