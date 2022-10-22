// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, ans;
std::vector<int> g;
int solve(std::vector<int> &x)
{
    int res = x.size();
    std::vector<int> sum;
    std::set<int> set;
    set.insert(0);
    sum.push_back(0);
    for (std::size_t i = 0; i != x.size(); ++i)
    {
        sum.push_back(sum.back() ^ x[i]);
        if (set.count(sum.back()))
            --res, set.clear();
        set.insert(sum.back());
    }
    x.clear();
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        ans = 0;
        for (int i = 1, x; i <= n; ++i)
        {
            std::cin >> x;
            if (x)
                g.push_back(x);
            else
                ans += solve(g);
        }
        ans += solve(g);
        std::cout << ans << std::endl;
    }
    return 0;
}