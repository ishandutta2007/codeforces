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
int n, v[1005], lim;
bool did[1005][1005];
int dfn[1005][1005];
void work(int a, int b)
{
    did[a][b] = did[b][a] = true;
    dfn[a][b] = dfn[b][a] = -1;
    std::cout << a << ' ' << b << std::endl;
}
void work4(int a, int b, int c, int d)
{
    work(a, b);
    work(a, c);
    work(b, d);
    work(a, d);
    work(b, c);
    work(c, d);
}
void work5(int a, int b, int c, int d, int e)
{
    work(a, b);
    work(a, c);
    work(a, d);
    work(b, c);
    work(b, e);
    work(c, e);
    work(a, e);
    work(c, d);
    work(b, d);
    work(d, e);
}
void work2_4(int a, int b, int c, int d, int e, int f, int g, int h)
{
    work(a, e);
    work(a, f);
    work(a, g);
    work(b, e);
    work(b, h);
    work(a, h);
    work(b, g);
    work(c, e);
    work(d, f);
    work(c, f);
    work(b, f);
    work(c, g);
    work(d, e);
    work(d, h);
    work(c, h);
    work(d, g);
}
void dfs(int tim, int good)
{
    for (int i = 1; i <= n; ++i)
    {
        if (v[i] != i)
        {
            bool can = false;
            for (int j = 1; j < i; ++j)
                can |= !dfn[j][i];
            for (int j = i + 1; j <= n; ++j)
                can |= !dfn[i][j];
            if (!can)
                return;
        }
    }
    if (tim == lim && good == n)
    {
        for (int t = 1; t <= tim; ++t)
            for (int i = 1; i <= n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (dfn[i][j] == t)
                        std::cout << i << ' ' << j << std::endl;
        exit(0);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (!dfn[i][j])
            {
                dfn[i][j] = tim + 1;
                good -= (i == v[i]);
                good -= (j == v[j]);
                std::swap(v[i], v[j]);
                good += (i == v[i]);
                good += (j == v[j]);
                dfs(tim + 1, good);
                good -= (i == v[i]);
                good -= (j == v[j]);
                std::swap(v[i], v[j]);
                good += (i == v[i]);
                good += (j == v[j]);
                dfn[i][j] = 0;
            }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        v[i] = i;
    // work4(1, 2, 3, 4);
    // work4(5, 6, 7, 8);
    // work4(9, 10, 11, 12);
    // for (int i = 1; i <= n; ++i)
    //     for (int j = i + 1; j <= n; ++j)
    //         if (!dfn[i][j])
    //             ++lim;
    // dfs(0, n);
    // return 0;
    switch (n % 4)
    {
    case 0:
        std::cout << "YES" << std::endl;
        for (int i = 4; i <= n; i += 4)
            work4(i - 3, i - 2, i - 1, i);
        for (int i = 4; i <= n; i += 4)
            for (int j = i + 4; j <= n; j += 4)
                work2_4(i - 3, i - 2, i - 1, i, j - 3, j - 2, j - 1, j);
        break;
    case 1:
        std::cout << "YES" << std::endl;
        for (int i = 4; i <= n; i += 4)
            work5(i - 3, i - 2, i - 1, i, n);
        for (int i = 4; i <= n; i += 4)
            for (int j = i + 4; j <= n; j += 4)
                work2_4(i - 3, i - 2, i - 1, i, j - 3, j - 2, j - 1, j);
        break;
    case 2:
    case 3:
        std::cout << "NO" << std::endl;
        break;
    }
    return 0;
}