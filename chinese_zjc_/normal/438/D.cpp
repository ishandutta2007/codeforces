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
int n, m;
struct node
{
    int sum, max;
} t[1 << 18];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    t[now].sum = t[lson].sum + t[rson].sum;
    t[now].max = std::max(t[lson].max, t[rson].max);
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        std::cin >> t[now].sum;
        t[now].max = t[now].sum;
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
void modify(int pos, int val, int now = 1, int l = 1, int r = n)
{
    if (r < pos || pos < l)
        return;
    if (l == r)
    {
        t[now].sum = t[now].max = val;
        return;
    }
    modify(pos, val, lson, l, lmid);
    modify(pos, val, rson, rmid, r);
    pushup(now);
}
void mod(int L, int R, int val, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L || t[now].max < val)
        return;
    if (l == r)
    {
        t[now].max %= val;
        t[now].sum %= val;
        return;
    }
    mod(L, R, val, lson, l, lmid);
    mod(L, R, val, rson, rmid, r);
    pushup(now);
}
int sum(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return 0;
    if (L <= l && r <= R)
        return t[now].sum;
    return sum(L, R, lson, l, lmid) + sum(L, R, rson, rmid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    build();
    for (int i = 1; i <= m; ++i)
    {
        static int opt, l, r, x;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> l >> r;
            std::cout << sum(l, r) << std::endl;
            break;
        case 2:
            std::cin >> l >> r >> x;
            mod(l, r, x);
            break;
        case 3:
            std::cin >> l >> x;
            modify(l, x);
            break;
        }
        // for (int j = 1; j <= n; ++j)
        //     std::cout << sum(j, j) << " \n"[j == n];
    }
    return 0;
}