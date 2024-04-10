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
int n, d1, d2, x[100005], y[100005], px[100005], py[100005], ans;
bool good = true;
int dian(int Ax, int Ay, int Bx, int By) { return Ax * Bx + Ay * By; }
int cha(int Ax, int Ay, int Bx, int By) { return Ax * By - Bx * Ay; }
int dis(int x, int y) { return x * x + y * y; }
int sqr(int x) { return x * x; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> d1 >> d2;
    d1 *= d1;
    d2 *= d2;
    for (int i = 1; i <= n; ++i)
    {
        static int sx, sy, tx, ty;
        std::cin >> sx >> sy >> tx >> ty;
        px[i] = tx - sx;
        py[i] = ty - sy;
        // std::cout << px[i] << ' ' << py[i] << std::endl;
        if (i == 1)
            continue;
        x[i] = px[i] - px[i - 1];
        y[i] = py[i] - py[i - 1];
        if (dian(-px[i - 1], -py[i - 1], x[i], y[i]) >= 0 &&
            dian(-px[i - 1], -py[i - 1], x[i], y[i]) <= dis(x[i], y[i]))
        {
            if (dis(px[i - 1], py[i - 1]) >= d2)
                good = true;
            if (good && sqr(cha(-px[i - 1], -py[i - 1], x[i], y[i])) <= dis(x[i], y[i]) * d1)
            {
                // std::cout << llabs(cha(-px[i - 1], -py[i - 1], x[i], y[i])) << std::endl;
                // std::cout << i << std::endl;
                good = false;
                ++ans;
            }
            if (dis(px[i], py[i]) >= d2)
                good = true;
        }
        else
        {
            if (dis(px[i - 1], py[i - 1]) >= d2)
                good = true;
            if (good && dis(px[i - 1], py[i - 1]) <= d1)
            {
                good = false;
                ++ans;
            }
            if (dis(px[i], py[i]) >= d2)
                good = true;
            if (good && dis(px[i], py[i]) <= d1)
            {
                good = false;
                ++ans;
            }
        }
        // std::cout << ans << std::endl;
    }
    std::cout << ans << std::endl;
    return 0;
}