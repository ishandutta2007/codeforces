// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MAXN = 200000, B = 400;
int n, q, p[MAXN + 5], cnt;
long long a[MAXN + 5], sum[MAXN / B + 5];
int in(int x) { return (x + B - 1) / B; }
int Llim(int x) { return (x - 1) * B + 1; }
int Rlim(int x) { return std::min(n, x * B); }
struct block
{
    long long tag;
    int pre[MAXN / B + 5], st, ed;
    block() : tag(), pre(), st(), ed() {}
};
block *to[MAXN + 5];
std::vector<block *> bks;
void pushdown(block &x)
{
    if (x.tag)
    {
        int now = x.st;
        do
        {
            a[now] += x.tag;
            sum[in(now)] += x.tag;
            now = p[now];
        } while (now != x.ed);
        x.tag = 0;
    }
}
void update(block &x)
{
    std::fill(x.pre, x.pre + 1 + cnt, 0);
    int now = x.st;
    do
    {
        to[now] = &x;
        ++x.pre[in(now)];
        now = p[now];
    } while (now != x.ed);
    for (int i = 1; i <= cnt; ++i)
        x.pre[i] += x.pre[i - 1];
}
void build(int beg, int end)
{
    bks.push_back(new block);
    bks.back()->st = beg;
    bks.back()->ed = end;
    update(*bks.back());
}
void remove(block &x)
{
    pushdown(x);
    int now = x.st;
    do
    {
        to[now] = 0;
        now = p[now];
    } while (now != x.ed);
    x.st = x.ed = -1;
}
int get_size(block &x)
{
    int cnt = 0, now = x.st;
    do
    {
        ++cnt;
        now = p[now];
    } while (now != x.ed);
    return cnt;
}
void init(int x)
{
    if (!to[x])
    {
        int now = x;
        std::vector<int> t;
        do
        {
            t.push_back(now);
            now = p[now];
        } while (now != x);
        while (t.size() >= 2 * B)
            build(*(t.end() - B), p[t.back()]), t.erase(t.end() - B, t.end());
        if (t.size() >= B)
            build(t.front(), p[t.back()]);
    }
}
void merge(block &x)
{
    if (get_size(x) < B)
    {
        if (x.st == x.ed)
        {
            remove(x);
        }
        else
        {
            pushdown(x);
            pushdown(*to[x.ed]);
            int tmp = to[x.ed]->ed;
            remove(*to[x.ed]);
            x.ed = tmp;
            update(x);
        }
    }
}
void split(block &x)
{
    if (get_size(x) >= B * 2)
    {
        pushdown(x);
        int cnt = 0, now = x.st;
        do
        {
            ++cnt;
            now = p[now];
        } while (cnt < B);
        std::swap(x.st, now);
        update(x);
        build(now, x.st);
    }
}
long long get(int x) { return a[x] + (to[x] ? to[x]->tag : 0); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], sum[in(i)] += a[i];
    cnt = in(n);
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i];
    for (int i = 1; i <= n; ++i)
        init(i);
    std::cin >> q;
    for (int i = 1, opt, x, y; i <= q; ++i)
    {
        std::cin >> opt >> x >> y;
        switch (opt)
        {
        case 1:
        {
            long long res = 0;
            if (in(x) != in(y))
            {
                int bl = in(x) + 1, br = in(y)-1;
                for (int j = bl; j <= br; ++j)
                    res += sum[j];
                for (std::size_t j = 0; j != bks.size(); ++j)
                    if (!~bks[j]->st)
                    {
                        std::swap(bks[j--], bks.back());
                        delete bks.back();
                        bks.pop_back();
                        continue;
                    }
                for (auto j : bks)
                    res += j->tag * (j->pre[br] - j->pre[bl - 1]);
                for (int i = Rlim(bl - 1); i >= x; --i)
                    res += get(i);
                for (int i = Llim(br + 1); i <= y; ++i)
                    res += get(i);
            }
            else
                for (int i = x; i <= y; ++i)
                    res += get(i);
            std::cout << res << std::endl;
        }
        break;
        case 2:
        {
            if (to[x])
            {
                int now = x;
                do
                {
                    to[now]->tag += y;
                    now = to[now]->ed;
                } while (now != to[x]->st);
            }
            else
            {
                int now = x;
                do
                {
                    a[now] += y;
                    sum[in(now)] += y;
                    now = p[now];
                } while (now != x);
            }
        }
        break;
        case 3:
        {
            if (to[x] && to[y])
            {
                if (to[x] == to[y])
                {
                    block &z = *to[x];
                    pushdown(z);
                    int now = z.st;
                    do
                    {
                        to[now] = 0;
                        now = p[now];
                    } while (now != z.ed);
                    std::swap(p[x], p[y]);
                    update(z);
                }
                else
                {
                    pushdown(*to[x]);
                    pushdown(*to[y]);
                    std::swap(p[x], p[y]);
                    std::swap(to[x]->ed, to[y]->ed);
                    update(*to[x]);
                    update(*to[y]);
                    if (to[x])
                        merge(*to[x]);
                    if (to[y])
                        merge(*to[y]);
                    if (to[x])
                        split(*to[x]);
                    if (to[y])
                        split(*to[y]);
                }
            }
            else if (to[x] || to[y])
            {
                if (to[y])
                    std::swap(x, y);
                pushdown(*to[x]);
                std::swap(p[x], p[y]);
                update(*to[x]);
            }
            else
            {
                std::swap(p[x], p[y]);
                init(x);
                init(y);
            }
        }
        break;
        }
    }
    return 0;
}