// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
char c[205];
int n;
std::vector<int> ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i];
    for (int i = 1; i < n; ++i)
        if (c[i] != 'W')
            c[i] ^= 'W' ^ 'B', c[i + 1] ^= 'W' ^ 'B', ans.push_back(i);
    if (c[n] != 'W')
    {
        for (int i = 1; i < n; ++i)
            if (c[i] != 'B')
                c[i] ^= 'W' ^ 'B', c[i + 1] ^= 'W' ^ 'B', ans.push_back(i);
    }
    if (c[1] != c[n])
        std::cout << -1 << std::endl;
    else
    {
        std::cout << ans.size() << std::endl;
        for (auto i : ans)
            std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}