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
int n, m, a[200005], dp[200005][15], app[5100000][15];
std::vector<int> p[200005];
struct segmenttree
{
    int t[1 << 19];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
    void pushup(int now)
    {
        t[now] = std::max(t[lson], t[rson]);
    }
    template <class T>
    void build(T fun, int now = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            t[now] = fun(l);
            return;
        }
        build(fun, lson, l, lmid);
        build(fun, rson, rmid, r);
        pushup(now);
    }
    int max(int L, int R, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return 0;
        if (L <= l && r <= R)
            return t[now];
        return std::max(max(L, R, lson, l, lmid), max(L, R, rson, rmid, r));
    }
#undef lson
#undef rson
#undef lmid
#undef rmid
} tree[15];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        for (int j = 2; j * j <= a[i]; ++j)
        {
            while (a[i] % (j * j) == 0)
                a[i] /= j * j;
            if (a[i] % j == 0)
                p[i].push_back(j), a[i] /= j;
        }
        if (a[i] > 1)
            p[i].push_back(a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j != 1 << p[i].size(); ++j)
        {
            int v = 1, t = 0;
            for (int k = 0; k != (int)p[i].size(); ++k)
                if (j & 1 << k)
                    v *= p[i][k];
                else
                    ++t;
            for (int k = 0; t + k < 15; ++k)
                dp[i][t + k] = std::max(dp[i][t + k], app[v][k]);
            for (int k = t; k < 15; ++k)
                app[v][k] = i;
        }
        // for (int j = 0; j != 15; ++j)
        //     std::cout << dp[i][j] << ' ';
        // std::cout << std::endl;
    }
    // for (int i = 1; i <= n; ++i, std::cout << std::endl)
    //     for (auto j : p[i])
    //         std::cout << j << ' ';
    for (int i = 0; i < 15; ++i)
        tree[i].build([&](const int &X)
                      { return dp[X][i]; });
    std::stringstream res;
    for (int i = 1; i <= m; ++i)
    {
        static int l, r;
        std::cin >> l >> r;
        for (int j = 0; j < 15; ++j)
            if (tree[j].max(l, r) >= l)
            {
                res << j << std::endl;
                break;
            }
    }
    std::cout << res.str();
    return 0;
}