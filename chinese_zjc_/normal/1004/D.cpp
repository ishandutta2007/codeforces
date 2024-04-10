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
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int t, v[1000005], c[1000005], max, n, m, x, y, a, b;
int app[1000005];
//720720=2^4*3^2*5*7*11*13
//      =5*3*2*2*2*2
//      =240
bool check()
{
    memset(app, 0, sizeof(app));
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            ++app[llabs(i - x) + llabs(j - y)];
    for (int i = 0; i != t; ++i)
        if (app[i] != c[i])
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> t;
    for (int i = 0; i != t; ++i)
    {
        std::cin >> v[i];
        ++c[v[i]];
        max = std::max(max, v[i]);
    }
    for (int i = 1; i <= t; ++i)
        if (c[i] != i * 4)
        {
            x = i - 1;
            break;
        }
    b = max;
    for (int i = 1; i <= t; ++i)
    {
        if (t % i == 0)
        {
            n = i;
            m = t / i;
            y = n + m - x - b - 2;
            a = x + y;
            if (check())
            {
                std::cout << n << ' ' << m << std::endl
                          << x + 1 << ' ' << y + 1 << std::endl;
                return 0;
            }
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}