//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
std::vector<int> son[100005], d[100005];
int n, r, q, fa[100005], depth[100005], dfn[100005], in[100005], out[100005],
    tim, root[100005], rk[100005], v[100005], cnt, maxdepth;
void init(int now)
{
    dfn[in[now] = ++tim] = now;
    d[depth[now]].push_back(now);
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        depth[son[now][i]] = depth[now] + 1;
        init(son[now][i]);
    }
    out[now] = tim;
}
struct node
{
    int lson, rson, min;
    node() : lson(-1), rson(-1), min(INF) {}
} t[1 << 22];
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
int build(int l = 1, int r = n)
{
    int now = cnt++;
    if (l == r)
        return now;
    t[now].lson = build(l, lmid);
    t[now].rson = build(rmid, r);
    return now;
}
int modify(int pos, int val, int old, int l = 1, int r = n)
{
    int now = cnt++;
    if (l == r)
    {
        t[now].min = val;
        return now;
    }
    t[now].lson = pos <= lmid ? modify(pos, val, t[old].lson, l, lmid) : t[old].lson;
    t[now].rson = pos >= rmid ? modify(pos, val, t[old].rson, rmid, r) : t[old].rson;
    t[now].min = std::min(t[t[now].lson].min, t[t[now].rson].min);
    return now;
}
int query(int L, int R, int now, int l = 1, int r = n)
{
    if (R < l || r < L)
        return INF;
    if (L <= l && r <= R)
        return t[now].min;
    return std::min(query(L, R, t[now].lson, l, lmid), query(L, R, t[now].rson, rmid, r));
}
#undef lmid
#undef rmid
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> r;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 1; i < n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    init(r);
    root[0] = build();
    maxdepth = *std::max_element(depth + 1, depth + 1 + n);
    for (int i = 0; i <= maxdepth; ++i)
    {
        root[i] = root[i - 1];
        for (auto j : d[i])
            root[i] = modify(in[j], v[j], root[i]);
    }
    std::cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        static int x, d, ans;
        std::cin >> x >> d;
        x = (x + ans) % n + 1;
        d = (d + ans) % n;
        std::cout << (ans = query(in[x], out[x], root[std::min(maxdepth, depth[x] + d)])) << std::endl;
    }
    return 0;
}