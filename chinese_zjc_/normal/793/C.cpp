//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#define y1 nmslnmsl
#include <cmath>
#undef y1
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
int n;
double x1, x2, y1, y2, l = 0, r = INF / 2;
double dis(double st, double v, double ed, double undefined)
{
    if (st == ed)
        return 0;
    return v == 0 || (ed - st) / v < 0 ? undefined : (ed - st) / v;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    std::cout << std::fixed << std::setprecision(100);
    for (int i = 1; i <= n; ++i)
    {
        static double x, y, vx, vy;
        std::cin >> x >> y >> vx >> vy;
        // if (i > 84 && n == 100 && x1 == 283 && y1 == 340 && x2 == 640 && y2 == 883)
        //     std::cout << std::setprecision(0) << x << ' ' << y << ' ' << vx << ' ' << vy << std::endl;
        int X = x <= x1 ? -1 : x >= x2, Y = y <= y1 ? -1 : y >= y2;
        switch (X)
        {
        case -1:
            if (vx <= 0)
                l = INF;
            l = std::max(l, dis(x, vx, x1, INF));
            r = std::min(r, dis(x, vx, x2, INF));
            break;
        case 0:
            r = std::min(r, dis(x, vx, x1, INF));
            r = std::min(r, dis(x, vx, x2, INF));
            break;
        case 1:
            if (vx >= 0)
                l = INF;
            l = std::max(l, dis(x, vx, x2, INF));
            r = std::min(r, dis(x, vx, x1, INF));
            break;
        }
        switch (Y)
        {
        case -1:
            if (vy <= 0)
                l = INF;
            l = std::max(l, dis(y, vy, y1, INF));
            r = std::min(r, dis(y, vy, y2, INF));
            break;
        case 0:
            r = std::min(r, dis(y, vy, y1, INF));
            r = std::min(r, dis(y, vy, y2, INF));
            break;
        case 1:
            if (vy >= 0)
                l = INF;
            l = std::max(l, dis(y, vy, y2, INF));
            r = std::min(r, dis(y, vy, y1, INF));
            break;
        }
        // std::cout << l << ' ' << r << std::endl;
    }
    if (l >= r)
        std::cout << -1 << std::endl;
    else
        std::cout << l << std::endl;
    return 0;
}