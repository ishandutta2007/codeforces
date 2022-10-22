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
char c[100005];
struct segmenttree
{
    struct node
    {
        int sum, tag;
    } t[1 << 18];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
    void pushup(int now)
    {
        t[now].sum = t[lson].sum + t[rson].sum;
    }
    void pushdown(int now, int l, int r)
    {
        if (~t[now].tag)
        {
            t[lson].sum = t[now].tag * (lmid - l + 1);
            t[rson].sum = t[now].tag * (r - rmid + 1);
            t[lson].tag = t[rson].tag = t[now].tag;
            t[now].tag = -1;
        }
    }
    template <class T>
    void build(T fun, int now = 1, int l = 1, int r = n)
    {
        t[now].tag = -1;
        if (l == r)
            return void(t[now].sum = fun(l));
        build(fun, lson, l, lmid);
        build(fun, rson, rmid, r);
        pushup(now);
    }
    void fill(int L, int R, int val, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
        {
            t[now].tag = val;
            t[now].sum = val * (r - l + 1);
            return;
        }
        pushdown(now, l, r);
        fill(L, R, val, lson, l, lmid);
        fill(L, R, val, rson, rmid, r);
        pushup(now);
    }
    int sum(int L, int R, int now = 1, int l = 1, int r = n)
    {
        if (R < l || r < L)
            return 0;
        if (L <= l && r <= R)
            return t[now].sum;
        pushdown(now, l, r);
        return sum(L, R, lson, l, lmid) + sum(L, R, rson, rmid, r);
    }
#undef lson
#undef rson
#undef lmid
#undef rmid
} t[26];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i];
    for (int i = 0; i != 26; ++i)
        t[i].build([&](const int &x)
                   { return c[x] == 'a' + i; });
    for (int i = 1; i <= m; ++i)
    {
        static int l, r, v;
        std::cin >> l >> r >> v;
        int c[26];
        for (int j = 0; j != 26; ++j)
            c[j] = t[j].sum(l, r), t[j].fill(l, r, 0);
        // for (int j = 0; j != 26; ++j)
        //     std::cout << c[j] << " \n"[j + 1 == 26];
        if (v)
        {
            for (int j = 0, pos = l; j != 26; ++j)
            {
                t[j].fill(pos, pos + c[j] - 1, 1);
                pos += c[j];
            }
        }
        else
        {
            for (int j = 26, pos = l; j--;)
            {
                t[j].fill(pos, pos + c[j] - 1, 1);
                pos += c[j];
            }
        }
        // for (int i = 1; i <= n; ++i)
        //     for (int j = 0; j != 26; ++j)
        //         if (t[j].sum(i, i))
        //             std::cout << char(j + 'a');
        // std::cout << std::endl;
        // for (int j = 0; j != 26; ++j)
        //     std::cout << t[j].sum(1, n) << " \n"[j + 1 == 26];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j != 26; ++j)
            if (t[j].sum(i, i))
                std::cout << char(j + 'a');
    std::cout << std::endl;
    return 0;
}