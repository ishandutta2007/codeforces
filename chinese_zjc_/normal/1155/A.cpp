// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int n;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s;
    for (int i = 1; i != n; ++i)
        if (s[i] < s[i - 1])
            return std::cout << "YES" << std::endl
                             << i << ' ' << i + 1 << std::endl,
                   0;
    std::cout << "NO" << std::endl;
    return 0;
}