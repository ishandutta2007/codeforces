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
int n, m, ans, l[1005][1005], r[1005][1005], d[1005][1005], u[1005][1005], odd,cnt;
bool c[1005][1005];
bool notconnect()
{
    int sx = 1, sy = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (c[i][j])
                sx = i, sy = j;
    std::queue<std::pair<int, int>> que;
    que.push({sx, sy});
    c[sx][sy] = false;
    while (!que.empty())
    {
        const int xx[] = {0, +1, 0, -1}, yy[] = {+1, 0, -1, 0};
        std::pair<int, int> now = que.front();
        que.pop();
        for (int i = 0; i != 4; ++i)
        {
            if (c[now.first + xx[i]][now.second + yy[i]])
            {
                c[now.first + xx[i]][now.second + yy[i]] = false;
                que.push({now.first + xx[i], now.second + yy[i]});
            }
        }
    }
    // for (int i = 1; i <= n; ++i, std::cout << std::endl)
    //     for (int j = 1; j <= m; ++j)
    //         std::cout << c[i][j] << ' ';
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (c[i][j])
                return true;
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> c[i][j], cnt += c[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            l[i][j] = c[i][j] && c[i][j - 1] ? l[i][j - 1] : j;
    for (int i = 1; i <= n; ++i)
        for (int j = m; j; --j)
            r[i][j] = c[i][j] && c[i][j + 1] ? r[i][j + 1] : j;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            u[i][j] = c[i][j] && c[i - 1][j] ? u[i - 1][j] : i;
    for (int i = n; i; --i)
        for (int j = 1; j <= m; ++j)
            d[i][j] = c[i][j] && c[i + 1][j] ? d[i + 1][j] : i;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            bool isodd = (l[i][j] != j) ^ (r[i][j] != j) ^ (d[i][j] != i) ^ (u[i][j] != i);
            odd += isodd;
            if (((l[i][j] != j || r[i][j] != j) && (d[i][j] != i || u[i][j] != i)) || isodd)
                ans = std::__gcd(std::__gcd(std::__gcd(j - l[i][j], r[i][j] - j),
                                            std::__gcd(i - u[i][j], d[i][j] - i)),
                                 ans);
        }
    if (ans == 1 || notconnect() || (odd != 0 && odd != 2) || (cnt == 1))
        std::cout << -1 << std::endl;
    else
        for (int i = 2; i <= ans; ++i)
            if (ans % i == 0)
                std::cout << i << " \n"[i == ans];
    return 0;
}