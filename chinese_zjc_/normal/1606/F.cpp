// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, dfn[200005], idfn[200005], siz[200005], heavy[200005], depth[200005], fa[200005], F[200005], top[200005],
    ans[200005];
std::pair<int, int> v[200005];
std::vector<int> son[200005];
std::vector<std::pair<int, int>> query[200005];
double P(std::pair<int, int> x) { return (x.second - 1.0) / (x.first + 1.0); }
std::priority_queue<std::pair<double, int>> que;
int find(int now) { return F[now] == now ? now : F[now] = find(F[now]); }
void init1(int now)
{
    siz[now] = 1;
    for (int v = 0; v != (int)son[now].size(); ++v)
    {
        int i = son[now][v];
        if (i == fa[now])
        {
            std::swap(son[now][v--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[i] = now;
        depth[i] = depth[now] + 1;
        init1(i);
        siz[now] += siz[i];
        if (siz[i] > siz[heavy[now]])
            heavy[now] = i;
    }
}
void init2(int now)
{
    static int tim;
    dfn[idfn[now] = ++tim] = now;
    if (heavy[now])
        top[heavy[now]] = top[now], init2(heavy[now]);
    for (auto i : son[now])
    {
        if (i == heavy[now])
            continue;
        top[i] = i;
        init2(i);
    }
}
struct BIT
{
    int sum[200005];
    void add(int pos, int val)
    {
        while (pos <= n)
        {
            sum[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos)
    {
        int res = 0;
        while (pos)
        {
            res += sum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    void add(int l, int r, int val)
    {
        add(l, val);
        add(r + 1, -val);
    }
} A, B;
void del(int now)
{
    F[now] = find(fa[now]);
    static int i;
    for (i = fa[now]; top[i] != top[F[now]]; i = fa[top[i]])
    {
        A.add(idfn[top[i]], idfn[i], v[now].first + 1);
        B.add(idfn[top[i]], idfn[i], v[now].second - 1);
    }
    A.add(idfn[F[now]], idfn[i], v[now].first + 1);
    B.add(idfn[F[now]], idfn[i], v[now].second - 1);
    v[F[now]].first += v[now].first + 1;
    v[F[now]].second += v[now].second - 1;
    que.push({P(v[F[now]]), F[now]});
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, x, y; i != n; ++i)
        std::cin >> x >> y, son[x].push_back(y), son[y].push_back(x);
    init1(1);
    top[1] = 1;
    init2(1);
    std::cin >> m;
    for (int i = 1, x, y; i <= m; ++i)
        std::cin >> x >> y, query[y].emplace_back(x, i);
    for (int i = 1; i <= n; ++i)
        F[i] = i, v[i].first = 0, v[i].second = son[i].size(), que.push({P(v[i]), i}),
        B.add(idfn[i], idfn[i], son[i].size());
    for (int i = 200000; i >= 0; --i)
    {
        while (!que.empty() && que.top().first >= i)
        {
            int now = que.top().second;
            que.pop();
            if (find(now) != now || now == 1)
                continue;
#ifdef debug
            std::cout << now << ' ' << P(v[now]) << std::endl;
#endif
            del(now);
        }
        for (auto j : query[i])
            ans[j.second] = B.query(idfn[j.first]) - A.query(idfn[j.first]) * i;
#ifdef debug
        if (i <= 10)
        {
            for (int j = 1; j <= n; ++j)
                std::cout << '(' << A.query(idfn[j]) << ',' << B.query(idfn[j]) << ')';
            std::cout << std::endl;
        }
#endif
    }
    for (int i = 1; i <= m; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}