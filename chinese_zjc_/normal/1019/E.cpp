// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, fa[200005], cnt, siz[200005];
struct edge
{
    int t, a, b;
    edge &swap(int x) { return std::swap(x, t), *this; }
};
std::vector<edge> to[200005];
bool del[200005];
void init1(int now)
{
    for (std::size_t i = 0; i != to[now].size(); ++i)
    {
        if (to[now][i].t == fa[now])
        {
            std::swap(to[now][i--], to[now].back());
            to[now].pop_back();
            continue;
        }
        fa[to[now][i].t] = now;
        init1(to[now][i].t);
    }
}
void init2(int now)
{
    for (auto i : to[now])
    {
        fa[i.t] = now;
        init2(i.t);
        to[i.t].emplace_back(edge(i).swap(now));
    }
}
struct segment
{
    long long k, b;
    long long y(int x) { return k * x + b; }
    friend bool operator<(const segment &A, const segment &B) { return A.k == B.k ? A.b > B.b : A.k < B.k; }
    friend bool operator==(const segment &A, const segment &B) { return A.k == B.k; }
    friend segment operator+(const segment &A, const segment &B) { return {A.k + B.k, A.b + B.b}; }
    friend double operator*(const segment &A, const segment &B) { return -1.0 * (A.b - B.b) / (A.k - B.k); }
};
struct tubao
{
    std::vector<segment> g;
    void build()
    {
        std::sort(g.begin(), g.end());
        g.erase(std::unique(g.begin(), g.end()), g.end());
        std::vector<segment> res;
        for (auto i : g)
        {
            while (res.size() >= 2 && res.end()[-2] * res.end()[-1] >= res.end()[-1] * i)
                res.pop_back();
            res.push_back(i);
        }
        g.swap(res);
    }
    tubao &operator+=(const tubao &X) { return g.insert(g.end(), X.g.begin(), X.g.end()), *this; }
    friend tubao operator+(const tubao &A, const tubao &B)
    {
        tubao res;
        std::vector<segment>::const_iterator Ai = A.g.begin(), Bi = B.g.begin();
        while (std::next(Ai) != A.g.end() && std::next(Bi) != B.g.end())
            if (*Ai * Ai[1] < *Bi * Bi[1])
                res.g.push_back(*Ai++ + *Bi);
            else if (*Ai * Ai[1] > *Bi * Bi[1])
                res.g.push_back(*Ai + *Bi++);
            else
                res.g.push_back(*Ai++ + *Bi++);
        while (std::next(Ai) != A.g.end())
            res.g.push_back(*Ai++ + *Bi);
        while (std::next(Bi) != B.g.end())
            res.g.push_back(*Ai + *Bi++);
        res.g.push_back(*Ai++ + *Bi++);
        return res;
    }
} ans;
int find_root(int now, int tot)
{
    siz[now] = 1;
    int res = -1;
    for (auto i : to[now])
    {
        if (i.t == fa[now] || del[i.t])
            continue;
        int tmp = find_root(i.t, tot);
        if (~tmp && (!~res || std::max(siz[tmp], tot - siz[tmp]) < std::max(siz[res], tot - siz[res])))
            res = tmp;
        siz[now] += siz[i.t];
    }
    if (!~res || std::max(siz[now], tot - siz[now]) < std::max(siz[res], tot - siz[res]))
        res = now;
    return res;
}
void dfs(int now, int from, long long k, long long b, tubao &X)
{
    X.g.push_back({k, b});
    for (auto i : to[now])
    {
        if (i.t == from || del[i.t == fa[now] ? now : i.t])
            continue;
        dfs(i.t, now, k + i.a, b + i.b, X);
    }
}
void solve(int now, int tot)
{
    if (tot == 1)
        return;
    int root = find_root(now, tot);
    tubao A, B;
    B.g.push_back({0, 0});
    for (auto i : to[root])
    {
        if (del[i.t == fa[root] ? root : i.t])
            continue;
        dfs(i.t, root, i.a, i.b, i.t == fa[root] ? A : B);
    }
    A.build();
    B.build();
    ans += A + B;
    del[root] = true;
    solve(now, tot - siz[root]);
    solve(root, siz[root]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1, u, v, a, b; i != n; ++i)
    {
        std::cin >> u >> v >> a >> b;
        to[u].push_back({v, a, b});
        to[v].push_back({u, a, b});
    }
    init1(1);
    cnt = n;
    for (int i = 1; i <= n; ++i)
        while (to[i].size() > 2)
        {
            to[++cnt].assign(to[i].end() - 2, to[i].end());
            to[i].pop_back();
            to[i].pop_back();
            to[i].push_back({cnt, 0, 0});
        }
    init2(1);
    solve(1, cnt);
    ans.g.push_back({0, 0});
    ans.build();
    std::vector<segment>::iterator iter = ans.g.begin();
    for (int i = 0; i != m; ++i)
    {
        while (std::next(iter) != ans.g.end() && iter->y(i) <= iter[1].y(i))
            ++iter;
        std::cout << iter->y(i) << " \n"[i + 1 == m];
    }
    return 0;
}