// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, p[200005], fa[400005], cnt, siz[400005], num, beg[200005], end[200005], ver[200005];
std::vector<std::pair<int, int>> to[400005];
bool del[400005];
struct twin
{
    int way;
    long long sum;
    twin(int way_ = 0, long long sum_ = 0) : way(way_), sum(sum_) {}
    twin &operator+=(const twin &x) { return way += x.way, sum += x.sum, *this; }
    twin &operator-=(const twin &x) { return way -= x.way, sum -= x.sum, *this; }
    friend twin operator+(const twin &A, const twin &B) { return twin(A) += B; }
    friend long long operator*(const twin &A, const twin &B) { return A.sum * B.way + A.way * B.sum; }
    friend std::ostream &operator<<(std::ostream &A, const twin &B) { return A << '(' << B.way << ',' << B.sum << ')'; }
    long long operator()(const long long &x) const { return sum + x * way; }
};
struct node
{
    int son[2];
    twin v;
} t[19260817];
void init1(int now)
{
    for (std::size_t i = 0; i != to[now].size(); ++i)
    {
        if (to[now][i].first == fa[now])
        {
            std::swap(to[now][i--], to[now].back());
            to[now].pop_back();
            continue;
        }
        fa[to[now][i].first] = now;
        init1(to[now][i].first);
    }
}
void init2(int now)
{
    for (auto i : to[now])
    {
        init2(i.first);
        fa[i.first] = now;
        to[i.first].push_back({now, i.second});
    }
}
int find_root(int now, int tot)
{
    siz[now] = 1;
    int res = 0;
    for (auto i : to[now])
    {
        if (i.first == fa[now] || del[i.first])
            continue;
        int tmp = find_root(i.first, tot);
        if (!res || std::max(siz[tmp], tot - siz[tmp]) < std::max(siz[res], tot - siz[res]))
            res = tmp;
        siz[now] += siz[i.first];
    }
    if (!res || std::max(siz[now], tot - siz[now]) < std::max(siz[res], tot - siz[res]))
        return now;
    return res;
}
void visit(int now, int from, long long val, bool side)
{
    if (now <= n)
        t[end[now] = t[end[now]].son[side] = ++num].v = twin(1, val);
    for (auto i : to[now])
    {
        if (i.first == from || del[i.first == fa[now] ? now : i.first])
            continue;
        visit(i.first, now, val + i.second, side);
    }
}
void build(int now, int tot)
{
    if (tot == 1)
        return;
    int root = find_root(now, tot);
    if (root <= n)
        t[end[root] = t[end[root]].son[0] = ++num].v = twin(1, 0);
    for (auto i : to[root])
    {
        if (del[i.first == fa[root] ? root : i.first])
            continue;
        visit(i.first, root, i.second, i.first == fa[root]);
    }
    del[root] = true;
    // std::cout << "end " << now << ' ' << root << ' ' << siz[root] << std::endl;
    build(now, tot - siz[root]);
    build(root, siz[root]);
}
int merge(int A, int B)
{
    if (!A || !B)
        return A ^ B;
    int now = ++num;
    t[now].v = t[A].v + t[B].v;
    for (int i = 0; i != 2; ++i)
        t[now].son[i] = merge(t[A].son[i], t[B].son[i]);
    return now;
}
long long calc(int A, int B)
{
    if (!A || !B)
        return 0;
    long long res = 0;
    for (int i = 0; i != 2; ++i)
        for (int j = 0; j != 2; ++j)
            res += i == j ? calc(t[A].son[i], t[B].son[j]) : t[t[A].son[i]].v * t[t[B].son[j]].v;
    return res;
}
void print(int now)
{
    if (t[now].son[0])
        std::cout << now << ' ' << t[now].son[0] << ' ' << t[t[now].son[0]].v << std::endl, print(t[now].son[0]);
    if (t[now].son[1])
        std::cout << now << ' ' << t[now].son[1] << ' ' << t[t[now].son[1]].v << std::endl, print(t[now].son[1]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i];
    for (int i = 1, x, y, w; i != n; ++i)
        std::cin >> x >> y >> w, to[x].push_back({y, w}), to[y].push_back({x, w});
    init1(1);
    cnt = n;
    for (int i = 1; i <= n; ++i)
        while (to[i].size() > 2)
        {
            to[++cnt].assign(to[i].end() - 2, to[i].end());
            to[i].pop_back();
            to[i].pop_back();
            to[i].push_back({cnt, 0});
        }
    init2(1);
    // for (int i = 1; i <= cnt; ++i)
    //     for (auto j : to[i])
    //         std::cout << i << ' ' << j.first << ' ' << j.second << std::endl;
    for (int i = 1; i <= n; ++i)
        beg[i] = end[i] = ++num;
    build(1, cnt);
    for (int i = 1; i <= n; ++i)
        ver[i] = merge(ver[i - 1], beg[p[i]]);
    for (int i = 1, opt, l, r, x; i <= q; ++i)
    {
        static long long ans;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> l >> r >> x;
            l ^= ans;
            r ^= ans;
            x ^= ans;
            // print(ver[r]);
            // print(ver[l - 1]);
            // print(beg[x]);
            std::cout << (ans = calc(ver[r], beg[x]) - calc(ver[l - 1], beg[x])) << std::endl;
            ans %= 1 << 30;
            break;
        case 2:
            std::cin >> x;
            x ^= ans;
            std::swap(p[x], p[x + 1]);
            ver[x] = merge(ver[x - 1], beg[p[x]]);
            break;
        }
    }
    return 0;
}