// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
std::vector<int> to[100005], p;
std::vector<std::vector<int>> app;
int n, q, from[10000005], ans[100005], v[100005], fa[20][100005], depth[100005];
std::vector<std::pair<int, int>> t[100005];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        B >>= 1;
        A = 1ll * A * A % MOD;
    }
    return res;
}
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (auto i : to[now])
    {
        if (i == fa[0][now])
            continue;
        fa[0][i] = now;
        depth[i] = depth[now] + 1;
        init(i);
    }
}
int LCA(int A, int B)
{
    if (depth[A] < depth[B])
        std::swap(A, B);
    for (int i = 20; i--;)
        if (depth[A] - depth[B] >= 1 << i)
            A = fa[i][A];
    if (A == B)
        return A;
    for (int i = 20; i--;)
        if (fa[i][A] != fa[i][B])
            A = fa[i][A], B = fa[i][B];
    return fa[0][A];
}
void dfs(int now)
{
    for (int i = v[now]; i > 1;)
    {
        int x = from[i], y = 0;
        while (i % p[x] == 0)
            i /= p[x], ++y;
        ++app[x][y];
    }
    for (auto i : t[now])
    {
        bool s = i.second < 0;
        i.second = std::abs(i.second);
        while (i.first > 1)
        {
            int x = from[i.first], y = 0, z = 0;
            while (i.first % p[x] == 0)
                i.first /= p[x], ++y;
            for (int j = 1; j < (int)app[x].size(); ++j)
                z += app[x][j] * std::min(j, y);
            ans[i.second] = 1ll * ans[i.second] * power(p[x], s ? MOD - 1 - z * 2 : z) % MOD;
        }
    }
    for (auto i : to[now])
    {
        if (i == fa[0][now])
            continue;
        dfs(i);
    }
    for (int i = v[now]; i > 1;)
    {
        int x = from[i], y = 0;
        while (i % p[x] == 0)
            i /= p[x], ++y;
        --app[x][y];
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(from, -1, sizeof(from));
    for (int i = 2; i <= 10000000; ++i)
    {
        if (!~from[i])
        {
            from[i] = p.size();
            p.push_back(i);
        }
        for (auto j = 0; j != (int)p.size(); ++j)
        {
            if (i * p[j] > 10000000)
                break;
            from[i * p[j]] = j;
            if (i % p[j] == 0)
                break;
        }
    }
    app.resize(p.size());
    std::cin >> n;
    for (int i = 1, x, y; i < n; ++i)
    {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        for (int tmp = v[i]; tmp > 1;)
        {
            int x = from[tmp], y = 1;
            while (tmp % p[x] == 0)
                tmp /= p[x], ++y;
            if (int(app[x].size()) < y)
                app[x].resize(y);
        }
    }
    init(1);
    std::cin >> q;
    for (int i = 1, a, b, c; i <= q; ++i)
    {
        std::cin >> a >> b >> c;
        int lca = LCA(a, b);
        ans[i] = std::__gcd(c, v[lca]);
        t[a].push_back({c, i});
        t[b].push_back({c, i});
        t[lca].push_back({c, -i});
    }
    dfs(1);
    for (int i = 1; i <= q; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}