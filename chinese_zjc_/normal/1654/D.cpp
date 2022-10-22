// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
const int MOD = 998244353;
// #define debug
int T, n, fa[200005], g[200005], dfn[200005], idfn[200005], end[200005], tim;
long long ans;
struct edge
{
    int v, x, y;
};
std::vector<int> p;
std::vector<edge> to[200005];
std::vector<std::pair<int, int>> app[200005];
void init(int now)
{
    idfn[dfn[now] = ++tim] = now;
    for (auto i : to[now])
    {
        if (i.v == fa[now])
            continue;
        fa[i.v] = now;
        init(i.v);
    }
    end[now] = tim;
}
long long power(long long A, int B)
{
    long long res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
void work(int now, long long v)
{
    ans = (ans + v) % MOD;
    for (auto i : to[now])
    {
        if (i.v == fa[now])
            continue;
        work(i.v, v * i.y % MOD * power(i.x, MOD - 2) % MOD);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 2; i <= 200000; ++i)
    {
        if (!g[i])
            g[i] = i, p.push_back(i);
        for (auto j : p)
        {
            if (i * j > 200000)
                break;
            g[i * j] = j;
            if (i % j == 0)
                break;
        }
    }
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            to[i].clear(), app[i].clear();
        for (int i = 1, a, b, x, y; i != n; ++i)
        {
            std::cin >> a >> b >> x >> y;
            to[a].push_back({b, x, y});
            to[b].push_back({a, y, x});
        }
        init(1);
        long long t = 1;
        for (int i = 1; i <= n; ++i)
            for (auto j : to[i])
            {
                if (j.v == fa[i])
                    continue;
                while (j.x > 1)
                {
                    app[g[j.x]].push_back({dfn[j.v], +1});
                    app[g[j.x]].push_back({end[j.v] + 1, -1});
                    // if (g[j.x] == 2)
                    //     std::cout << g[j.x] << ' ' << dfn[j.v] << ' ' << end[j.v] << ' ' << +1 << std::endl;
                    j.x /= g[j.x];
                }
                while (j.y > 1)
                {
                    app[g[j.y]].push_back({dfn[j.v], -1});
                    app[g[j.y]].push_back({end[j.v] + 1, +1});
                    // if (g[j.y] == 2)
                    //     std::cout << g[j.y] << ' ' << dfn[j.v] << ' ' << end[j.v] << ' ' << -1 << std::endl;
                    j.y /= g[j.y];
                }
            }
        for (auto i : p)
        {
            if (i > n)
                break;
            std::sort(app[i].begin(), app[i].end());
            int lst = -1, v = 0, max = 0;
            for (auto j : app[i])
            {
                if (j.first != lst)
                    max = std::max(max, v);
                v += j.second;
                lst = j.first;
            }
            if (lst != n + 1)
                max = std::max(max, v);
            // std::cout << i << ' ' << max << std::endl;
            t = t * power(i, max) % MOD;
        }
        work(1, t);
        std::cout << ans << std::endl;
        ans = 0;
        tim = 0;
    }
    return 0;
}