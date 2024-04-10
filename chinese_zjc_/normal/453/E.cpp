// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MAX = 100001;
int n, q, s[100005], m[100005], k[100005], root[100005], cnt, lson[2000005], rson[2000005];
#define mid ((l + r) >> 1)
struct node
{
    long long m, k;
} sum[2000005];
int build(int l = 0, int r = MAX)
{
    int now = cnt++;
    if (r - l > 1)
    {
        lson[now] = build(l, mid);
        rson[now] = build(mid, r);
    }
    return now;
}
int add(int pos, int m, int k, int old, int l = 0, int r = MAX)
{
    int now = cnt++;
    sum[now] = sum[old];
    sum[now].m += m;
    sum[now].k += k;
    if (r - l > 1)
    {
        lson[now] = lson[old];
        rson[now] = rson[old];
        if (pos < mid)
            lson[now] = add(pos, m, k, lson[now], l, mid);
        else
            rson[now] = add(pos, m, k, rson[now], mid, r);
    }
    return now;
}
template <long long node::*T>
long long query(int L, int R, int now, int l = 0, int r = MAX)
{
    if (r <= L || R <= l)
        return 0;
    if (L <= l && r <= R)
        return sum[now].*T;
    return query<T>(L, R, lson[now], l, mid) + query<T>(L, R, rson[now], mid, r);
}
std::map<int, int> g;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    root[0] = build();
    for (int i = 0; i != n; ++i)
    {
        std::cin >> s[i] >> m[i] >> k[i];
        root[i + 1] = k[i] ? add(m[i] / k[i], m[i], k[i], root[i]) : root[i];
    }
    std::cin >> q;
    g.insert({0, -1});
    for (int i = 0, t, l, r; i != q; ++i)
    {
        long long ans = 0;
        std::cin >> t >> l >> r;
        --l;
        for (std::map<int, int>::iterator fir = g.insert({l, std::prev(g.upper_bound(l))->second}).first,
                                          las = g.insert({r, std::prev(g.upper_bound(r))->second}).first;
             fir != las; g.erase(fir++))
        {
            int e = std::next(fir)->first;
            if (~fir->second)
            {
                ans += query<&node::m>(0, t - fir->second, root[e]) -
                       query<&node::m>(0, t - fir->second, root[fir->first]) +
                       (t - fir->second) * (query<&node::k>(t - fir->second, MAX, root[e]) -
                                            query<&node::k>(t - fir->second, MAX, root[fir->first]));
            }
            else
                for (int j = fir->first; j != e; ++j)
                    ans += std::min(static_cast<long long>(m[j]), s[j] + static_cast<long long>(k[j]) * t);
        }
        g.insert({l, t});
        std::cout << ans << '\n';
    }
    return 0;
}