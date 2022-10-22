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
int sum[1 << 21], tag[1 << 21], n, q, l[300005], r[300005], opt[300005];
std::stringstream res;
std::vector<int> p;
#define lson (now << 1)
#define rson (lson | 1)
#define mid ((l + r) >> 1)
void pushdown(int now, int l, int r)
{
    if (~tag[now])
    {
        sum[lson] = (tag[lson] = tag[now]) ? p[mid] - p[l] : 0;
        sum[rson] = (tag[rson] = tag[now]) ? p[r] - p[mid] : 0;
        tag[now] = -1;
    }
}
void pushup(int now)
{
    sum[now] = sum[lson] + sum[rson];
}
void build(int now = 1, int l = 0, int r = p.size() - 1)
{
    tag[now] = -1;
    if (r - l == 1)
        return void(sum[now] = p[r] - p[l]);
    build(lson, l, mid);
    build(rson, mid, r);
    pushup(now);
}
void modify(int L, int R, int val, int now = 1, int l = 0, int r = p.size() - 1)
{
    if (R <= l || r <= L)
        return;
    if (L <= l && r <= R)
        return void(sum[now] = (tag[now] = val) ? p[r] - p[l] : 0);
    pushdown(now, l, r);
    modify(L, R, val, lson, l, mid);
    modify(L, R, val, rson, mid, r);
    pushup(now);
}
int query(int L, int R, int now = 1, int l = 0, int r = p.size() - 1)
{
    if (R <= l || r <= L)
        return 0;
    if (L <= l && r <= R)
        return sum[now];
    pushdown(now, l, r);
    return query(L, R, lson, l, mid) + query(L, R, rson, mid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    p.push_back(0);
    p.push_back(n);
    for (int i = 1; i <= q; ++i)
    {
        std::cin >> l[i] >> r[i] >> opt[i];
        --opt[i];
        --l[i];
        p.push_back(l[i]);
        p.push_back(r[i]);
    }
    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(), p.end()), p.end());
    build();
    // for (auto i : p)
    //     std::cout << i << ' ';
    // std::cout << std::endl;
    for (int i = 1; i <= q; ++i)
    {
        l[i] = std::lower_bound(p.begin(), p.end(), l[i]) - p.begin();
        r[i] = std::lower_bound(p.begin(), p.end(), r[i]) - p.begin();
        modify(l[i], r[i], opt[i]);
        res << query(0, p.size() - 1) << std::endl;
    }
    std::cout << res.str();
    return 0;
}