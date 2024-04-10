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
int min[1 << 18], n, k, ans[100005], tim;
std::queue<int> que;
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    min[now] = std::min(min[lson], min[rson]);
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        std::cin >> min[now];
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
void modify(int pos, int val = INF, int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        min[now] = val;
        return;
    }
    if (pos <= lmid)
        modify(pos, val, lson, l, lmid);
    else
        modify(pos, val, rson, rmid, r);
    pushup(now);
}
int query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return INF;
    if (L <= l && r <= R)
        return min[now];
    return std::min(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    build();
    while (query(1, n) != INF)
    {
        tim = std::max(tim, query(1, n));
        int l = 1, r = n;
        while (l < r)
        {
            if (query(1, lmid) <= tim)
                r = lmid;
            else
                l = rmid;
        }
        modify(l);
        que.push(l);
        for (int tmp = query(l = 1, r); tmp <= tim + (int)que.size() * k; tmp = query(l = 1, r))
        {
            while (l < r)
            {
                if (query(1, lmid) <= tmp)
                    r = lmid;
                else
                    l = rmid;
            }
            modify(l);
            que.push(l);
        }
        while (!que.empty())
        {
            ans[que.front()] = tim += k;
            que.pop();
        }
    }
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " \n"[i == n];
    return 0;
}