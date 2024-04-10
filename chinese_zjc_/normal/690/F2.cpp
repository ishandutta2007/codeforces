// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, k;
const long long base = 19260817;
const int MOD = 998244853;
std::valarray<bool> vis;
std::valarray<int> siz;
std::vector<int> center;
struct tree
{
    int m;
    std::valarray<std::vector<int>> to;
    tree() : to(n) {}
    int get(int del)
    {
        vis.resize(n);
        siz.resize(n);
        if (~del)
            vis[del] = true;
        int res = 1;
        for (int i = 0; i != n; ++i)
            if (!vis[i])
                res = 1ll * res * G(i) % MOD;
        return res;
    }
    void init(int now, int fa)
    {
        siz[now] = 1;
        for (auto i : to[now])
        {
            if (i == fa || vis[i])
                continue;
            init(i, now);
            siz[now] += siz[i];
        }
    }
    void getcenter(int now, int fa, int tot)
    {
        int max = tot - siz[now];
        for (auto i : to[now])
        {
            if (i == fa || vis[i])
                continue;
            getcenter(i, now, tot);
            max = std::max(max, siz[i]);
        }
        if (max * 2 < tot)
            center.push_back(now);
    }
    int gethash(int now, int depth, int fa)
    {
        vis[now] = true;
        int res = 1;
        for (auto i : to[now])
        {
            if (i == fa || vis[i])
                continue;
            res = res * base % MOD * (depth + gethash(i, depth + 1, now)) % MOD;
        }
        return res;
    }
    void fill(int now)
    {
        vis[now] = true;
        for (auto i : to[now])
            if (!vis[i])
                fill(i);
    }
    int G(int now)
    {
        init(now, -1);
        getcenter(now, -1, siz[now]);
        int res = 1;
        for (auto i : center)
            res = 1ll * res * gethash(i, 1, -1) % MOD;
        center.clear();
        fill(now);
        return res;
    }
};
std::vector<tree> t;
bool check(int x, int y)
{
    std::map<int, int> map;
    for (int i = 0; i != n; ++i)
        if (y != i)
            ++map[t[x].get(i)];
    for (int i = 0; i != k; ++i)
        if (x != i && !map[t[i].get(-1)]--)
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        t.resize(k);
        for (int i = 0; i != k; ++i)
        {
            std::cin >> t[i].m;
            for (int j = 0, a, b; j != t[i].m; ++j)
            {
                std::cin >> a >> b;
                --a, --b;
                t[i].to[a].push_back(b);
                t[i].to[b].push_back(a);
            }
        }
        for (int i = 0; i != k; ++i)
            if (t[i].m == n - 2)
            {
                int x = std::find_if(std::begin(t[i].to), std::end(t[i].to), [&](const std::vector<int> &y)
                                     { return y.empty(); }) -
                        std::begin(t[i].to);
                for (int j = 0; j != n; ++j)
                    if (j != x)
                    {
                        t[i].to[j].push_back(x);
                        t[i].to[x].push_back(j);
                        if (check(i, x))
                        {
                            std::cout << "YES" << std::endl;
                            for (int l = 0; l != n; ++l)
                                for (auto o : t[i].to[l])
                                    if (o < l)
                                        std::cout << o + 1 << ' ' << l + 1 << std::endl;
                            goto next;
                        }
                        t[i].to[x].pop_back();
                        t[i].to[j].pop_back();
                    }
                std::cout << "NO" << std::endl;
                goto next;
            }
    next:
        t.clear();
    }
    return 0;
}