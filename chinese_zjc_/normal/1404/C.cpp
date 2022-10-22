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
int n, m, a[300005], ans[300005];
std::vector<std::pair<int, int>> query[300005];
struct BIT
{
    int sum[300005];
    void add(int pos, int val)
    {
        while (pos <= n)
        {
            sum[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int now)
    {
        int res = 0;
        while (now)
        {
            res += sum[now];
            now -= now & -now;
        }
        return res;
    }
} sum;
struct segmenttree
{
    int min[1 << 20], add[1 << 20];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
    void pushup(int now)
    {
        min[now] = std::min(min[lson], min[rson]);
    }
    void pushdown(int now)
    {
        if (add[now])
        {
            min[lson] += add[now];
            min[rson] += add[now];
            add[lson] += add[now];
            add[rson] += add[now];
            add[now] = 0;
        }
    }
    void build(int (*F)(int), int now = 1, int l = 1, int r = n)
    {
        add[now] = 0;
        if (l == r)
            return void(min[now] = F(l));
        build(F, lson, l, lmid);
        build(F, rson, rmid, r);
        pushup(now);
    }
    void modify(int L, int R, int val, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
        {
            min[now] += val;
            add[now] += val;
            return;
        }
        pushdown(now);
        modify(L, R, val, lson, l, lmid);
        modify(L, R, val, rson, rmid, r);
        pushup(now);
    }
    int query(int L, int R, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return INF;
        if (L <= l && r <= R)
            return min[now];
        pushdown(now);
        return std::min(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
    }
    std::vector<int> res;
    void work(int L, int R, int now = 1, int l = 1, int r = n)
    {
        if (min[now] > 0 || R < l || r < L)
            return;
        if (l == r)
            return res.push_back(l);
        pushdown(now);
        work(L, R, lson, l, lmid);
        work(L, R, rson, rmid, r);
    }
#undef lson
#undef rson
#undef lmid
#undef rmid
} min;
int mininit(int x) { return x - a[x] >= 0 ? x - a[x] : INF; }
int X(int x) { return x >= INF / 2 ? -10 : x; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= m; ++i)
    {
        static int l, r;
        std::cin >> l >> r;
        query[l + 1].push_back(std::make_pair(n - r, i));
    }
    min.build(mininit);
    for (int i = n; i; --i)
    {
        // for (int j = 1; j <= n; ++j)
        //     std::cout << std::setw(3) << X(min.query(j, j)) << " \n"[j == n];
        // for (int j = 1; j <= n; ++j)
        //     std::cout << std::setw(3) << sum.query(j) - sum.query(j - 1) << " \n"[j == n];
        for (min.work(i, n); !min.res.empty(); min.res.clear(), min.work(i, n))
            for (auto j : min.res)
                sum.add(j, 1), min.modify(j, n, -1), min.modify(j, j, INF);
        for (auto j : query[i])
            ans[j.second] = sum.query(j.first);
    }
    for (int i = 1; i <= m; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}