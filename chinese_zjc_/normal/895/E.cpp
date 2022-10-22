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
    double sum, multag, addtag;
} t[1 << 18];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushdown(int now, int l, int r)
{
    if (t[now].multag != 1)
    {
        t[lson].sum *= t[now].multag;
        t[rson].sum *= t[now].multag;
        t[lson].multag *= t[now].multag;
        t[rson].multag *= t[now].multag;
        t[lson].addtag *= t[now].multag;
        t[rson].addtag *= t[now].multag;
        t[now].multag = 1;
    }
    if (t[now].addtag)
    {
        t[lson].sum += t[now].addtag * (rmid - l);
        t[rson].sum += t[now].addtag * (r - lmid);
        t[lson].addtag += t[now].addtag;
        t[rson].addtag += t[now].addtag;
        t[now].addtag = 0;
    }
}
void pushup(int now)
{
    t[now].sum = t[lson].sum + t[rson].sum;
}
void build(int now = 1, int l = 1, int r = n)
{
    t[now].multag = 1;
    t[now].addtag = 0;
    if (l == r)
    {
        std::cin >> t[now].sum;
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
void modify(int L, int R, double mul, double add, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
    {
        t[now].sum *= mul;
        t[now].multag *= mul;
        t[now].addtag *= mul;
        t[now].sum += add * (r - l + 1);
        t[now].addtag += add;
        return;
    }
    pushdown(now, l, r);
    modify(L, R, mul, add, lson, l, lmid);
    modify(L, R, mul, add, rson, rmid, r);
    pushup(now);
}
double query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return 0;
    if (L <= l && r <= R)
        return t[now].sum;
    pushdown(now, l, r);
    return query(L, R, lson, l, lmid) + query(L, R, rson, rmid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    std::cout << std::fixed << std::setprecision(7);
    build();
    for (int i = 1; i <= m; ++i)
    {
        static int opt, l1, r1, l2, r2;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> l1 >> r1 >> l2 >> r2;
            {
                double s1 = query(l1, r1), s2 = query(l2, r2);
                modify(l1, r1, 1 - 1 / (r1 - l1 + 1.0), s2 / (r1 - l1 + 1) / (r2 - l2 + 1));
                modify(l2, r2, 1 - 1 / (r2 - l2 + 1.0), s1 / (r2 - l2 + 1) / (r1 - l1 + 1));
            }
            break;
        case 2:
            std::cin >> l1 >> r1;
            std::cout << query(l1, r1) << std::endl;
            break;
        }
        // for (int i = 1; i <= n; ++i)
        //     std::cout << query(i, i) << " \n"[i == n];
    }
    return 0;
}