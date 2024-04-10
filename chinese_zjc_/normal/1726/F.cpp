// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int n, t, g[200005], c[200005], d[200005];
long long v;
std::map<std::pair<int, int>, long long> map;
template <class T>
void cmin(T &A, T B) { A = std::min(A, B); }
template <class T>
void cmax(T &A, T B) { A = std::max(A, B); }
void insert(std::pair<int, int> pos, long long val)
{
    std::pair<std::map<std::pair<int, int>, long long>::iterator, bool> tmp = map.insert({pos, val});
    if (!tmp.second)
        cmin(tmp.first->second, val);
}
int dis(int A, int B)
{
    return A <= B ? B - A : B + t - A;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        std::cin >> g[i] >> c[i], c[i] = t - c[i];
    for (int i = 2; i <= n; ++i)
        std::cin >> d[i], v += d[i], d[i] = (d[i] + d[i - 1]) % t;
    for (int i = 1; i <= n; ++i)
        c[i] = (c[i] - d[i] + t) % t;
    map.insert({{0, t - 1}, v});
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] + g[i] <= t)
        {
            while (map.rbegin()->first.second >= c[i] + g[i])
            {
                std::pair<std::pair<int, int>, long long> now = *map.rbegin();
                map.erase(--map.end());
                insert({c[i], c[i]}, now.second + dis(now.first.second, c[i]));
                if (now.first.first < c[i] + g[i])
                    insert({now.first.first, c[i] + g[i] - 1}, now.second);
            }
            while (map.begin()->first.first < c[i])
            {
                std::pair<std::pair<int, int>, long long> now = *map.begin();
                map.erase(map.begin());
                insert({c[i], c[i]}, now.second + dis(now.first.second, c[i]));
                if (now.first.second >= c[i])
                    insert({c[i], now.first.second}, now.second);
            }
        }
        else
        {
            int Rp = c[i] + g[i] - t;
            std::map<std::pair<int, int>, long long>::iterator iter;
            while (iter = map.lower_bound({c[i], c[i]}), iter != map.begin() && (--iter)->first.second >= Rp)
            {
                std::pair<std::pair<int, int>, long long> now = *iter;
                map.erase(iter);
                insert({c[i], c[i]}, now.second + dis(now.first.second, c[i]));
                if (now.first.first < Rp)
                    insert({now.first.first, Rp - 1}, now.second);
                if (c[i] <= now.first.second)
                    insert({c[i], now.first.second}, now.second);
            }
        }
        // for (auto i : map)
        //     std::cout << i.first.first << ' ' << i.first.second << ' ' << i.second << std::endl;
        // std::cout << std::endl;
    }
    long long ans = LLONG_MAX;
    for (auto i : map)
        cmin(ans, i.second);
    std::cout << ans << std::endl;
    return 0;
}