// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string t[64], n;
int T, ans;
int work(const std::string &x, const std::string &y)
{
    std::size_t i = 0, j = 0;
    while (j != y.size())
    {
        while (i != x.size() && x[i] != y[j])
            ++i;
        if (i == x.size())
            break;
        ++i;
        ++j;
    }
    return (x.size() - j) + (y.size() - j);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i != 64; ++i)
        t[i] = std::to_string(1llu << i);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        ans = INT_MAX;
        for (int i = 0; i != 64; ++i)
            ans = std::min(ans, work(n, t[i]));
        std::cout << ans << std::endl;
    }
    return 0;
}