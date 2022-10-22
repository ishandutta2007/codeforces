// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, rk[100005], cnt;
long long c[100005];
std::vector<int> add, sub;
std::stringstream res;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1, a, b, d; i <= m; ++i)
    {
        std::cin >> a >> b >> d;
        c[a] -= d;
        c[b] += d;
    }
    for (int i = 1; i <= n; ++i)
        if (c[i] > 0)
            add.push_back(i);
        else if (c[i] < 0)
            sub.push_back(i);
    while (!add.empty() && !sub.empty())
    {
        long long min = std::min(c[add.back()], -c[sub.back()]);
        res << sub.back() << ' ' << add.back() << ' ' << min << std::endl;
        c[add.back()] -= min;
        c[sub.back()] += min;
        if (!c[add.back()])
            add.pop_back();
        if (!c[sub.back()])
            sub.pop_back();
        ++cnt;
    }
    std::cout << cnt << std::endl
              << res.str();
    return 0;
}