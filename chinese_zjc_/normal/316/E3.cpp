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
const int MOD = 1000000000;
int n, m, f[200005], pre[200005];
struct bit
{
    int sum[200005];
    void add(int now, int val)
    {
        while (now <= n)
        {
            sum[now] = (sum[now] + val) % MOD;
            now += now & -now;
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
        return res % MOD;
    }
} a;
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
int F(int x)
{
    return x < 0 ? 0 : f[x];
}
struct fib
{
    struct node
    {
        int sum0, sum1, add;
    } t[1 << 19];
    void pushdown(int now, int l, int r)
    {
        if (t[now].add)
        {
            t[lson].sum0 = (t[lson].sum0 + pre[lmid - l + 1] * t[now].add) % MOD;
            t[lson].sum1 = (t[lson].sum1 + (pre[lmid - l + 2] - 1) * t[now].add) % MOD;
            t[lson].add += t[now].add;
            t[rson].sum0 = (t[rson].sum0 + pre[r - rmid + 1] * t[now].add) % MOD;
            t[rson].sum1 = (t[rson].sum1 + (pre[r - rmid + 2] - 1) * t[now].add) % MOD;
            t[rson].add += t[now].add;
            t[now].add = 0;
        }
    }
    void add(int L, int R, int val, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return;
        t[now].sum0 = (t[now].sum0 + (pre[std::min(r, R) - l + 1] - pre[std::max(l, L) - l + 0] + MOD) * val) % MOD;
        t[now].sum1 = (t[now].sum1 + (pre[std::min(r, R) - l + 2] - pre[std::max(l, L) - l + 1] + MOD) * val) % MOD;
        if (L <= l && r <= R)
            return void(t[now].add += val);
        pushdown(now, l, r);
        add(L, R, val, lson, l, lmid);
        add(L, R, val, rson, rmid, r);
    }
    int query(int L, int R, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return 0;
        if (L <= l && r <= R)
            switch (l - L)
            {
            case 0:
                return t[now].sum0;
            case 1:
                return t[now].sum1;
            default:
                return (F(l - L - 2) * t[now].sum0 + F(l - L - 1) * t[now].sum1) % MOD;
            }
        pushdown(now, l, r);
        return (query(L, R, lson, l, lmid) + query(L, R, rson, rmid, r)) % MOD;
    }
} sum;
#undef lson
#undef rson
#undef lmid
#undef rmid
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> x;
        a.add(i, (x - a.query(i - 1) + MOD) % MOD);
    }
    f[0] = f[1] = 1;
    for (int i = 2; i <= n + 2; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    for (int i = 1; i <= n + 2; ++i)
        pre[i] = (pre[i - 1] + f[i - 1]) % MOD;
    // for (int i = 0; i <= n; ++i)
    //     std::cout << f[i] << " \n"[i == n];
    for (int i = 1; i <= n; ++i)
        sum.add(i, i, a.query(i));
    for (int i = 1; i <= m; ++i)
    {
        static int opt, l, r, x, v;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> x >> v;
            l = (v - a.query(x) + MOD) % MOD;
            sum.add(x, x, l);
            a.add(x, l);
            a.add(x + 1, MOD - l);
            break;
        case 2:
            std::cin >> l >> r;
            std::cout << sum.query(l, r) << std::endl;
            break;
        case 3:
            std::cin >> l >> r >> v;
            a.add(l, v);
            a.add(r + 1, MOD - v);
            sum.add(l, r, v);
            break;
        }
        // for (int i = 1; i <= n; ++i)
        //     std::cout << sum.query(i, i) << " \n"[i == n];
        // for (int i = 1; i <= n; ++i)
        //     std::cout << a.query(i) << " \n"[i == n];
    }
    return 0;
}