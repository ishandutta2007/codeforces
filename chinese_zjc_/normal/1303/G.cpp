// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[150005], siz[150005];
long long ans;
std::vector<int> to[150005];
bool del[150005];
struct line
{
    long long k, b;
    long long y(long long x) { return k * x + b; }
    friend double cross(const line &A, const line &B) { return -(A.b - B.b) / (A.k - B.k); }
};
struct segment
{
    int size;
    long long sum1, sum2, sum3;
};
struct node
{
    line min;
    int son[2];
    node() : min(), son() {}
} t[150005];
int cnt, root;
void clear() { std::fill(t + 1, t + 1 + cnt, node()), cnt = root = 0; }
#define mid ((l + r) >> 1)
void insert(line v, int &now = root, long long l = 0, long long r = n)
{
    if (!now)
    {
        now = ++cnt;
        t[now].min = v;
        return;
    }
    if (t[now].min.y(mid) < v.y(mid))
        std::swap(t[now].min, v);
    if (t[now].min.y(l) < v.y(l))
        insert(v, t[now].son[0], l, mid);
    if (t[now].min.y(r) < v.y(r))
        insert(v, t[now].son[1], mid, r);
}
long long query(long long pos, int now = root, long long l = 0, long long r = n)
{
    if (!now)
        return 0;
    long long res = t[now].min.y(pos);
    if (pos < mid)
        res = std::max(res, query(pos, t[now].son[0], l, mid));
    else
        res = std::max(res, query(pos, t[now].son[1], mid, r));
    return res;
}
void dfs(int now, int fa, segment v, std::vector<segment> &res)
{
    ++v.size;
    v.sum1 += a[now];
    v.sum2 += 1ll * a[now] * v.size;
    v.sum3 += v.sum1;
    bool down = false;
    for (auto i : to[now])
    {
        if (del[i] || i == fa)
            continue;
        down = true;
        dfs(i, now, v, res);
    }
    if (!down)
        res.push_back(v);
}
void get_size(int now, int fa = 0)
{
    siz[now] = 1;
    for (auto i : to[now])
    {
        if (del[i] || i == fa)
            continue;
        get_size(i, now);
        siz[now] += siz[i];
    }
}
int visit(int now, int tot, int fa = 0)
{
    int max = tot - siz[now];
    for (auto i : to[now])
    {
        if (del[i] || i == fa)
            continue;
        if (int k = visit(i, tot, now))
            return k;
        max = std::max(max, siz[i]);
    }
    return max * 2 <= tot ? now : 0;
}
int findroot(int now)
{
    get_size(now);
    return visit(now, siz[now]);
}
void solve(int now)
{
    now = findroot(now);
    std::vector<std::vector<segment>> vec;
    for (auto i : to[now])
    {
        if (del[i])
            continue;
        std::vector<segment> tmp;
        dfs(i, now, {0, 0, 0, 0}, tmp);
        vec.push_back(tmp);
    }
    clear();
    for (const auto &i : vec)
    {
        for (const auto &j : i)
            ans = std::max(ans, j.sum3 + a[now] * (j.size + 1ll) + query(j.size + 1ll));
        for (const auto &j : i)
            insert({j.sum1, j.sum2});
    }
    clear();
    std::reverse(vec.begin(), vec.end());
    for (const auto &i : vec)
    {
        for (const auto &j : i)
            ans = std::max(ans, j.sum3 + a[now] * (j.size + 1ll) + query(j.size + 1ll));
        for (const auto &j : i)
            insert({j.sum1, j.sum2});
    }
    for (const auto &i : vec)
        for (const auto &j : i)
            ans = std::max(ans, a[now] + j.sum3 + j.sum1);
    del[now] = true;
    for (auto i : to[now])
    {
        if (del[i])
            continue;
        solve(i);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, x, y; i != n; ++i)
        std::cin >> x >> y, to[x].push_back(y), to[y].push_back(x);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    solve(1);
    std::cout << ans << std::endl;
    return 0;
}