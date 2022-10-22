//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
std::vector<int> app;
int n, m, a[200005], t[200005], v[200005];
struct node
{
    unsigned int sum[3];
    int rk;
} tree[1 << 20];
#define lson (now << 1)
#define rson (lson | 1)
#define mid ((l + r) >> 1)
void pushdown(int now)
{
    if (tree[now].rk)
    {
        tree[lson].rk += tree[now].rk;
        tree[lson].sum[2] += tree[lson].sum[1] * tree[now].rk;
        tree[rson].rk += tree[now].rk;
        tree[rson].sum[2] += tree[rson].sum[1] * tree[now].rk;
        tree[now].rk = 0;
    }
}
void pushup(int now)
{
    tree[now].sum[0] = tree[lson].sum[0] + tree[rson].sum[0];
    tree[now].sum[1] = tree[lson].sum[1] + tree[rson].sum[1];
    tree[now].sum[2] = tree[lson].sum[2] + tree[rson].sum[2];
}
void addrk(int L, int R, int val, int now = 1, int l = 0, int r = app.size())
{
    if (R <= l || r <= L)
        return;
    if (L <= l && r <= R)
    {
        tree[now].rk += val;
        tree[now].sum[2] += tree[now].sum[1] * val;
        return;
    }
    pushdown(now);
    addrk(L, R, val, lson, l, mid);
    addrk(L, R, val, rson, mid, r);
    pushup(now);
}
void insert(int pos, int rk, int now = 1, int l = 0, int r = app.size())
{
    if (r - l == 1)
    {
        tree[now].sum[0] = 1;
        tree[now].sum[2] = (tree[now].sum[1] = app[pos]) * (tree[now].rk = rk);
        return;
    }
    pushdown(now);
    if (pos < mid)
        insert(pos, rk, lson, l, mid);
    else
        insert(pos, rk, rson, mid, r);
    pushup(now);
}
void erase(int pos, int now = 1, int l = 0, int r = app.size())
{
    if (r - l == 1)
    {
        tree[now].sum[0] = 0;
        tree[now].sum[2] = (tree[now].sum[1] = 0) * (tree[now].rk = 0);
        return;
    }
    pushdown(now);
    if (pos < mid)
        erase(pos, lson, l, mid);
    else
        erase(pos, rson, mid, r);
    pushup(now);
}
int sum(int L, int R, int pos, int now = 1, int l = 0, int r = app.size())
{
    if (R <= l || r <= L)
        return 0;
    if (L <= l && r <= R)
        return tree[now].sum[pos];
    pushdown(now);
    return sum(L, R, pos, lson, l, mid) + sum(L, R, pos, rson, mid, r);
}
int query_pre(int num, int now = 1, int l = 0, int r = app.size())
{
    if (num <= 0)
        return 0;
    if (num >= (int)tree[now].sum[0])
        return tree[now].sum[1];
    return query_pre(std::min(num, (int)tree[lson].sum[0]), lson, l, mid) +
           query_pre(num - tree[lson].sum[0], rson, mid, r);
}
int query_suf(int num, int now = 1, int l = 0, int r = app.size())
{
    if (num <= 0)
        return 0;
    if (num >= (int)tree[now].sum[0])
        return tree[now].sum[1];
    return query_suf(num - tree[rson].sum[0], lson, l, mid) +
           query_suf(std::min(num, (int)tree[rson].sum[0]), rson, mid, r);
}
int find_rk(int rk, int now = 1, int l = 0, int r = app.size())
{
    if (r - l == 1)
        return l;
    if ((int)tree[lson].sum[0] <= rk)
        return find_rk(rk - tree[lson].sum[0], rson, mid, r);
    else
        return find_rk(rk, lson, l, mid);
}
void print(int now = 1, int l = 0, int r = app.size())
{
    if (r - l == 1)
    {
        std::cout << tree[now].sum[1] << " ";
        return;
    }
    pushdown(now);
    print(lson, l, mid);
    print(rson, mid, r);
}
#undef lson
#undef rson
#undef mid
unsigned int work()
{
    unsigned int res = 0, siz = sum(0, app.size(), 0), cnt = 0;
    if (siz == 0)
        return 0;
    if (siz == 1)
        return 0;
    int l = 0, r = (siz - 1) / 2;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (query_suf(mid) <= query_pre(mid + 1))
            l = mid;
        else
            r = mid - 1;
    }
    // print();
    // std::cout << std::endl;
    if (l == 0)
        return sum(0, app.size(), 1) - sum(find_rk(0), find_rk(0) + 1, 1) * 2;
    cnt = l;
    l = find_rk(cnt - 1);
    r = find_rk(siz - cnt);
    // std::cout << l << ' ' << r << std::endl;
    // for (int i = 0; i != app.size(); ++i)
    //     std::cout << sum(0, i, 2) << " \n"[i + 1 == app.size()];
    res += 2 * ((sum(r, app.size(), 2) - (siz - cnt) * sum(r, app.size(), 1)) -
                ((cnt + 1) * sum(0, l + 1, 1) - sum(0, l + 1, 2)));
    if (cnt * 2 < siz - 1)
        res += sum(find_rk(cnt + 1), app.size(), 1) - sum(0, find_rk(cnt + 1), 1);
    // std::cout << find_rk(cnt) << ' ' << find_rk(siz - cnt - 1) << std::endl;
    // (sum(l + 1, app.size(), 1) * cnt + sum(0, l + 1, 2)) -
    //     (sum(0, app.size(), 1) * cnt -);
    return res;
}
int force()
{
    std::vector<std::pair<int, int>> s;
    for (int i = 1; i < sum(0, app.size(), 0); ++i)
    {
        std::pair<int, int> now = std::make_pair(query_pre(i), query_suf(i));
        std::cout << '[' << now.first << ',' << now.second << ')';
        if (!s.empty() && s.back().second >= now.first)
            s.back().second = now.second;
        else
            s.push_back(now);
    }
    std::cout << std::endl;
    int ans = 0;
    for (auto i : s)
        ans += i.second - i.first, std::cout << '[' << i.first << ',' << i.second << ')';
    std::cout << std::endl;
    print();
    std::cout << std::endl;
    return ans;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        app.push_back(a[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> t[i] >> v[i];
        app.push_back(v[i]);
    }
    std::sort(app.begin(), app.end());
    app.erase(std::unique(app.begin(), app.end()), app.end());
    for (int i = 1; i <= n; ++i)
        a[i] = std::lower_bound(app.begin(), app.end(), a[i]) - app.begin();
    for (int i = 1; i <= m; ++i)
        v[i] = std::lower_bound(app.begin(), app.end(), v[i]) - app.begin();
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
        insert(a[i], i);
    std::cout << work() << std::endl;
    // std::cout << force() << std::endl;
    for (int i = 1; i <= m; ++i)
    {
        if (t[i] == 1)
        {
            insert(v[i], sum(0, v[i], 0));
            addrk(v[i], app.size(), 1);
        }
        else
        {
            erase(v[i]);
            addrk(v[i], app.size(), -1);
        }
        std::cout << work() << std::endl;
    }
    return 0;
}