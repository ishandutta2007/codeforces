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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, x[1005], y[1005], cntx, cnty, LOWLIM = 0, HIGHLIM = INF, fa[1005], name[1005], cnt;
const int g[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 2, 3},
    {0, 1, 0, 4, 5},
    {0, 2, 4, 0, 6},
    {0, 3, 5, 6, 0}};
int connect[1005][1005];
struct L
{
    int x, y;
} a[1005];
set<int> tmpx, tmpy;
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
int lowbit(int now)
{
    return now & (-now);
}
int has(int now)
{
    return now ? has(now ^ lowbit(now)) + 1 : 0;
}
bool check(int now)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        name[i] = 0;
    }
    memset(connect, 0, sizeof connect);
    cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (find(i) != find(j))
            {
                if (abs(x[a[i].x] - x[a[j].x]) <= now && a[i].y == a[j].y)
                {
                    fa[find(i)] = find(j);
                }
                if (a[i].x == a[j].x && abs(y[a[i].y] - y[a[j].y]) <= now)
                {
                    fa[find(i)] = find(j);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!name[find(i)])
        {
            name[find(i)] = ++cnt;
        }
    }
    if (cnt == 1)
    {
        return true;
    }
    if (cnt == 2)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (find(i) != find(j))
                {
                    if (a[i].x == a[j].x && abs(y[a[i].y] - y[a[j].y]) <= now << 1)
                    {
                        return true;
                    }
                    if (abs(x[a[i].x] - x[a[j].x]) <= now << 1 && a[i].y == a[j].y)
                    {
                        return true;
                    }
                    if (abs(x[a[i].x] - x[a[j].x]) <= now && abs(y[a[i].y] - y[a[j].y]) <= now)
                    {
                        return true;
                    }
                }
            }
        }
    }
    if (cnt == 3)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (find(i) != find(j))
                {
                    if (abs(x[a[i].x] - x[a[j].x]) <= now && abs(y[a[i].y] - y[a[j].y]) <= now)
                    {
                        connect[a[i].x][a[j].y] |= 1 << g[name[find(i)]][name[find(j)]];
                        connect[a[j].x][a[i].y] |= 1 << g[name[find(i)]][name[find(j)]];
                    }
                }
            }
        }
        for (int i = 1; i <= cntx; ++i)
        {
            for (int j = 1; j <= cnty; ++j)
            {
                if (has(connect[i][j]) >= 2)
                {
                    return true;
                }
            }
        }
    }
    if (cnt == 4)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (find(i) != find(j))
                {
                    if (abs(x[a[i].x] - x[a[j].x]) <= now && abs(y[a[i].y] - y[a[j].y]) <= now)
                    {
                        connect[a[i].x][a[j].y] |= 1 << g[name[find(i)]][name[find(j)]];
                        connect[a[j].x][a[i].y] |= 1 << g[name[find(i)]][name[find(j)]];
                    }
                }
            }
        }
        for (int i = 1; i <= cntx; ++i)
        {
            for (int j = 1; j <= cnty; ++j)
            {
                if (has(connect[i][j]) >= 4)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        tmpx.insert(a[i].x);
        tmpy.insert(a[i].y);
    }
    for (auto i : tmpx)
    {
        x[++cntx] = i;
    }
    for (auto i : tmpy)
    {
        y[++cnty] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i].x = find(x + 1, x + 1 + cntx, a[i].x) - x;
        a[i].y = find(y + 1, y + 1 + cnty, a[i].y) - y;
    }
    while (LOWLIM < HIGHLIM)
    {
        int mid = (LOWLIM + HIGHLIM) >> 1;
        if (check(mid))
        {
            HIGHLIM = mid;
        }
        else
        {
            LOWLIM = mid + 1;
        }
    }
    cout << (LOWLIM < INF ? LOWLIM : -1) << endl;
    return 0;
}