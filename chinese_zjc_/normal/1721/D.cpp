// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
std::vector<int> a, b;
struct range
{
    std::vector<int>::iterator l, r;
};
int solve(int pos, const std::vector<std::pair<range, range>> &x)
{
    if (pos == -1)
        return 0;
    auto g = [&](const int x)
    { return x >> pos & 1; };
    std::vector<std::pair<range, range>> y;
    for (auto i : x)
    {
        std::vector<int>::iterator mid1 = std::partition(i.first.l, i.first.r, g),
                                   mid2 = std::partition(i.second.l, i.second.r, g);
        if (mid1 - i.first.l != i.second.r - mid2)
            return solve(pos - 1, x);
        if (mid1 == i.first.l || mid1 == i.first.r)
            y.push_back(i);
        else
        {
            y.push_back({{i.first.l, mid1}, {mid2, i.second.r}});
            y.push_back({{mid1, i.first.r}, {i.second.l, mid2}});
        }
    }
    return 1 << pos | solve(pos - 1, y);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        a.clear();
        b.clear();
        for (int i = 0, x; i != n; ++i)
            std::cin >> x, a.push_back(x);
        for (int i = 0, x; i != n; ++i)
            std::cin >> x, b.push_back(x);
        std::cout << solve(29, {{{a.begin(), a.end()}, {b.begin(), b.end()}}}) << std::endl;
    }
    return 0;
}