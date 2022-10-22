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
int n, m, k, v[55][20005];
bool now = true, lst = false;
struct segmenttree
{
    struct node
    {
        int max, add;
    } t[1 << 16];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
    void build(int now = 1, int l = 1, int r = m - k + 1)
    {
        if (l == r)
        {
            t[now].max = 0;
            return;
        }
        build(lson, l, lmid);
        build(rson, rmid, r);
        t[now].add = 0;
    }
    void pushup(int now)
    {
        t[now].max = std::max(t[lson].max, t[rson].max);
    }
    void pushdown(int now)
    {
        if (t[now].add)
        {
            t[lson].max += t[now].add;
            t[rson].max += t[now].add;
            t[lson].add += t[now].add;
            t[rson].add += t[now].add;
            t[now].add = 0;
        }
    }
    void add(int L, int R, int val, int now = 1, int l = 1, int r = m - k + 1)
    {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
        {
            t[now].max += val;
            t[now].add += val;
            return;
        }
        pushdown(now);
        add(L, R, val, lson, l, lmid);
        add(L, R, val, rson, rmid, r);
        pushup(now);
    }
    int max(int L, int R, int now = 1, int l = 1, int r = m - k + 1)
    {
        if (R < l || r < L)
            return -INF;
        if (L <= l && r <= R)
            return t[now].max;
        pushdown(now);
        return std::max(max(L, R, lson, l, lmid), max(L, R, rson, rmid, r));
    }
#undef lson
#undef rson
#undef lmid
#undef rmid
} dp[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> v[i][j];
    dp[now].build();
    for (int i = 1; i <= m; ++i)
        dp[now].add(i - k + 1, i, v[1][i]);
    for (int i = 2; i <= n; ++i)
    {
        std::swap(now, lst);
        dp[now].build();
        for (int j = 1; j <= m; ++j)
            dp[lst].add(j - k + 1, j, v[i][j]);
        for (int j = 1; j < k; ++j)
            dp[lst].add(j - k + 1, j, -v[i][j]);
        for (int j = 1; j <= m - k + 1; ++j)
        {
            dp[lst].add(j, j + k - 1, -v[i][j + k - 1]);
            dp[now].add(j, j, dp[lst].max(1, m - k + 1));
            dp[lst].add(j - k + 1, j, v[i][j]);
        }
        for (int j = 1; j <= m; ++j)
            dp[now].add(j - k + 1, j, v[i][j]);
    }
    std::cout << dp[now].max(1, m - k + 1) << std::endl;
    return 0;
}