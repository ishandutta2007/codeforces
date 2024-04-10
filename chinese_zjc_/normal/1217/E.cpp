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
int a[200005], n, m;
std::pair<int, int> min[1 << 19][9];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
std::pair<int, int> operator+(const std::pair<int, int> &A, const std::pair<int, int> &B)
{
    return A.first < B.first
               ? std::make_pair(A.first, std::min(A.second, B.first))
               : std::make_pair(B.first, std::min(A.first, B.second));
}
void pushup(int now)
{
    for (int i = 0; i != 9; ++i)
        min[now][i] = min[lson][i] + min[rson][i];
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        for (int i = 0, j = a[l]; i != 9; ++i, j /= 10)
            if (j % 10)
                min[now][i] = std::make_pair(a[l], INF);
            else
                min[now][i] = std::make_pair(INF, INF);
        return;
    }
    build(lson, l, lmid);
    build(rson, rmid, r);
    pushup(now);
}
void modify(int pos, int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        for (int i = 0, j = a[l]; i != 9; ++i, j /= 10)
            if (j % 10)
                min[now][i] = std::make_pair(a[l], INF);
            else
                min[now][i] = std::make_pair(INF, INF);
        return;
    }
    if (pos <= lmid)
        modify(pos, lson, l, lmid);
    else
        modify(pos, rson, rmid, r);
    pushup(now);
}
std::pair<int, int> query(int L, int R, int pos, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return std::make_pair(INF, INF);
    if (L <= l && r <= R)
        return min[now][pos];
    return query(L, R, pos, lson, l, lmid) + query(L, R, pos, rson, rmid, r);
}
int sum(const std::pair<int, int> &x)
{
    return x.first + x.second;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    build();
    for (int i = 1; i <= m; ++i)
    {
        static int opt, l, r, ans;
        std::cin >> opt >> l >> r;
        switch (opt)
        {
        case 1:
            a[l] = r;
            modify(l);
            break;
        case 2:
            ans = INF;
            // for (int i = 1; i <= n; ++i)
            //     for (int j = 0; j != 9; ++j)
            //         std::cout << query(i, i, j).first << " \n"[j + 1 == 9];
            for (int i = 0; i != 9; ++i)
                ans = std::min(ans, sum(query(l, r, i)));
            std::cout << (ans == INF ? -1 : ans) << std::endl;
            break;
        }
    }
    return 0;
}