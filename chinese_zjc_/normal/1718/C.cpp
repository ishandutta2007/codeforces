// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, q, a[200005];
bool is[200005];
std::vector<int> d;
std::vector<long long> s[20];
std::multiset<long long> t[20];
long long query()
{
    long long res = 0;
    for (std::size_t i = 0; i != d.size(); ++i)
        res = std::max(res, d[i] * *t[i].rbegin());
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::fill(is + 2, is + 1 + 200000, true);
    for (int i = 2; i <= 200000; ++i)
        for (int j = 2; i * j <= 200000; ++j)
            is[i * j] = false;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> q;
        d.clear();
        for (int i = 1; i <= n; ++i)
            if (n % i == 0 && is[n / i])
                s[d.size()].assign(i, 0), t[d.size()].clear(), d.push_back(i);
        for (int i = 0; i != n; ++i)
        {
            std::cin >> a[i];
            for (std::size_t j = 0; j != d.size(); ++j)
                s[j][i % d[j]] += a[i];
        }
        for (std::size_t i = 0; i != d.size(); ++i)
            for (int j = 0; j != d[i]; ++j)
                t[i].insert(s[i][j]);
        std::cout << query() << '\n';
        for (int i = 0, p, x; i != q; ++i)
        {
            std::cin >> p >> x;
            --p;
            for (std::size_t i = 0; i != d.size(); ++i)
            {
                t[i].erase(t[i].find(s[i][p % d[i]]));
                s[i][p % d[i]] -= a[p];
                s[i][p % d[i]] += x;
                t[i].insert(s[i][p % d[i]]);
            }
            a[p] = x;
            std::cout << query() << '\n';
        }
    }
    return 0;
}