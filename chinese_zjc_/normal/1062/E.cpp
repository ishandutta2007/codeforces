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
int n, q, dfn[100005], idfn[100005], tim, fa[20][100005], depth[100005];
std::vector<int> son[100005];
void init(int now)
{
    dfn[idfn[now] = ++tim] = now;
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (auto i : son[now])
    {
        depth[i] = depth[now] + 1;
        init(i);
    }
}
int cmax(int A, int B) { return idfn[A] > idfn[B] ? A : B; }
int cmin(int A, int B) { return idfn[A] < idfn[B] ? A : B; }
struct node
{
    int min, max;
} t[1 << 18];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    t[now].max = cmax(t[lson].max, t[rson].max);
    t[now].min = cmin(t[lson].min, t[rson].min);
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
        return void(t[now].min = t[now].max = l);
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
int max(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return dfn[1];
    if (L <= l && r <= R)
        return t[now].max;
    return cmax(max(L, R, lson, l, lmid), max(L, R, rson, rmid, r));
}
int min(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return dfn[tim];
    if (L <= l && r <= R)
        return t[now].min;
    return cmin(min(L, R, lson, l, lmid), min(L, R, rson, rmid, r));
}
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
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 2; i <= n; ++i)
        std::cin >> fa[0][i], son[fa[0][i]].push_back(i);
    init(1);
    build();
    for (int i = 1; i <= q; ++i)
    {
        static int l, r;
        std::cin >> l >> r;
        int MIN = min(l, r), MAX = max(l, r);
        int MINLCA = LCA(cmin(min(l, MIN - 1), min(MIN + 1, r)), MAX),
            MAXLCA = LCA(MIN, cmax(max(l, MAX - 1), max(MAX + 1, r)));
        if (depth[MINLCA] < depth[MAXLCA])
            std::cout << MAX << ' ' << depth[MAXLCA] << std::endl;
        else
            std::cout << MIN << ' ' << depth[MINLCA] << std::endl;
    }
    return 0;
}