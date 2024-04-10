// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, m;
long long n, k, v, L0, R0;
std::vector<long long> a, b;
inline long long down(long long A, long long B) { return A / B; }
inline long long up(long long A, long long B) { return (A - 1) / B + 1; }
void binl()
{
    long long l = 1, r = *std::min_element(b.begin(), b.end());
    auto check = [&](const long long &x)
    {
        long long tot = -int(b.size());
        for (auto i : b)
            tot += down(i, x);
        return k <= tot;
    };
    while (l < r)
    {
        long long mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    L0 = l;
}
void binr()
{
    long long l = 1, r = *std::max_element(b.begin(), b.end());
    auto check = [&](const long long &x)
    {
        long long tot = -int(b.size());
        for (auto i : b)
            tot += up(i, x);
        return tot <= k;
    };
    while (l < r)
    {
        long long mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    R0 = l;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> k;
        a.clear();
        a.push_back(0);
        for (int i = 1; i <= m; ++i)
            std::cin >> v, a.push_back(v);
        a.push_back(n);
        b.clear();
        for (std::size_t i = 1; i != a.size(); ++i)
            b.push_back(a[i] - a[i - 1]);
        binl();
        binr();
        if (R0 <= L0)
            std::cout << 0 << std::endl;
        else
        {
            std::priority_queue<std::pair<long long, long long>> que;
            que.push({R0, LLONG_MIN / 2});
            long long L = L0, ans = LLONG_MAX;
            for (auto i : b)
                que.push({up(i, down(i, L0)), down(i, up(i, R0))}) /* ,
                     std::cout << ":" << i << ' ' << L0 << ' ' << R0 << ' ' << up(i, down(i, L0)) << ' ' << down(i, up(i, R0)) << std::endl
                               << down(i, L0) - up(i, R0) << std::endl
                               << down(i, L0) - up(i, up(i, down(i, L0))) << std::endl
                               << down(i, down(i, up(i, R0))) - up(i, R0) << std::endl */
                    ;
            while (!que.empty())
            {
                ans = std::min(ans, que.top().first - L);
                L = std::min(L, que.top().second);
                que.pop();
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}