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
const int BLOCK = 300;
int n, v[100005], f[100005], fa[20][100005], q, st[100005], ed[100005], tim, dfn[200005], depth[100005], ans[100005];
int res, app[2][100005];
std::vector<int> to[100005];
bool in[100005];
std::vector<int> num;
void dfs(int now)
{
    dfn[st[now] = ++tim] = now;
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (auto i : to[now])
    {
        if (i == fa[0][now])
            continue;
        fa[0][i] = now;
        depth[i] = depth[now] + 1;
        dfs(i);
    }
    dfn[ed[now] = ++tim] = now;
}
struct query
{
    int l, r, p, lca;
    friend bool operator<(const query &A, const query &B) { return A.l / BLOCK == B.l / BLOCK ? A.r < B.r : A.l < B.l; }
} a[100005];
int LCA(int A, int B)
{
    if (depth[A] < depth[B])
        std::swap(A, B);
    for (int i = 19; i >= 0; --i)
        if (depth[A] - depth[B] >= 1 << i)
            A = fa[i][A];
    if (A == B)
        return A;
    for (int i = 19; i >= 0; --i)
        if (fa[i][A] != fa[i][B])
            A = fa[i][A], B = fa[i][B];
    return fa[0][A];
}
void add(int pos)
{
    if (in[pos])
    {
        in[pos] = false;
        res -= app[!v[pos]][f[pos]];
        --app[v[pos]][f[pos]];
    }
    else
    {
        in[pos] = true;
        res += app[!v[pos]][f[pos]];
        ++app[v[pos]][f[pos]];
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> f[i], num.push_back(f[i]);
    std::sort(num.begin(), num.end());
    num.erase(std::unique(num.begin(), num.end()), num.end());
    for (int i = 1; i <= n; ++i)
        f[i] = std::lower_bound(num.begin(), num.end(), f[i]) - num.begin();
    for (int i = 1; i < n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(1);
    // for (int i = 1; i <= n + n; ++i)
    //     std::cout << dfn[i] << " \n"[i == n + n];
    // for (int i = 1; i <= n; ++i)
    //     std::cout << st[i] << ' ' << ed[i] << std::endl;
    std::cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        static int A, B;
        std::cin >> A >> B;
        a[i].p = i;
        if (st[A] < st[B] && ed[B] < ed[A])
        {
            // std::cout << st[A] << " " << st[B] << std::endl;
            a[i].lca = 0;
            a[i].l = st[A];
            a[i].r = st[B] + 1;
        }
        else if (st[B] < st[A] && ed[A] < ed[B])
        {
            a[i].lca = 0;
            a[i].l = st[B];
            a[i].r = st[A] + 1;
        }
        else
        {
            a[i].lca = LCA(A, B);
            a[i].l = std::min(ed[A], ed[B]);
            a[i].r = std::max(st[A], st[B]) + 1;
        }
    }
    std::sort(a + 1, a + 1 + q);
    for (int i = 1, l = 1, r = 1; i <= q; ++i)
    {
        // std::cout << a[i].l << ' ' << a[i].r << ' ' << a[i].p << std::endl;
        while (l < a[i].l)
            add(dfn[l++]);
        while (l > a[i].l)
            add(dfn[--l]);
        while (r < a[i].r)
            add(dfn[r++]);
        while (r > a[i].r)
            add(dfn[--r]);
        if (a[i].lca)
            add(a[i].lca);
        ans[a[i].p] = res;
        if (a[i].lca)
            add(a[i].lca);
    }
    for (int i = 1; i <= q; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}