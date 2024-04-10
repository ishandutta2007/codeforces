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
int n, a[1000005], once[1000005], twice[1000005], d, r[4], ans = INF, Noback;
struct node
{
    int min, add;
} t[1 << 21];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    t[now].min = std::min(t[lson].min, t[rson].min);
}
void pushdown(int now)
{
    if (t[now].add)
    {
        t[lson].min += t[now].add;
        t[rson].min += t[now].add;
        t[lson].add += t[now].add;
        t[rson].add += t[now].add;
        t[now].add = 0;
    }
}
void add(int L, int R, int v, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
    {
        t[now].min += v;
        t[now].add += v;
        return;
    }
    pushdown(now);
    add(L, R, v, lson, l, lmid);
    add(L, R, v, rson, rmid, r);
    pushup(now);
}
int min(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return INF;
    if (L <= l && r <= R)
        return t[now].min;
    pushdown(now);
    return std::min(min(L, R, lson, l, lmid), min(L, R, rson, rmid, r));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> r[1] >> r[2] >> r[3] >> d;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        twice[i] = std::min(once[i] = a[i] * r[1] + r[3], std::min(r[1] + r[2], r[1] * (a[i] + 2)));
#ifdef debug
        std::cout << once[i] << " " << twice[i] << std::endl;
#endif
    }
    once[n] = std::min(once[n], twice[n] + d * 2);
#ifdef debug
    std::cout << once[n] << std::endl;
#endif
    Noback = once[1];
    add(1, 1, twice[1]);
#ifdef debug
    for (int j = 1; j <= n; ++j)
        std::cout << min(j, j) << ' ';
    std::cout << Noback << std::endl;
#endif
    for (int i = 2; i < n; ++i)
    {
        add(1, i - 1, d * 3);
        Noback += d;
        add(i, i, Noback + twice[i]);
        Noback += once[i];
        add(1, i - 1, twice[i]);
        Noback = std::min(Noback, min(1, i - 1));
#ifdef debug
        for (int j = 1; j <= n; ++j)
            std::cout << min(j, j) << ' ';
        std::cout << Noback << std::endl;
#endif
    }
    for (int i = 1; i < n; ++i)
        add(i, i, -d * (n - i - 1) + 2 * d);
    Noback += d + once[n];
#ifdef debug
    for (int j = 1; j <= n; ++j)
        std::cout << min(j, j) << ' ';
    std::cout << Noback << std::endl;
#endif
    std::cout << std::min(min(n - 1, n - 1) + twice[n] + d, std::min(Noback, min(1, n - 1) + once[n])) << std::endl;
    return 0;
}