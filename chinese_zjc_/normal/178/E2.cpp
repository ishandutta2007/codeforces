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
const int xx[] = {0, +1, 0, -1},
          yy[] = {+1, 0, -1, 0};
int n, circle, square;
struct photo
{
    bool a[2005][2005];
    photo() { memset(a, false, sizeof(a)); }
    const bool *operator[](const int &x) const { return a[x]; }
    bool *operator[](const int &x) { return a[x]; }
} a, b;
double sqr(double x) { return x * x; }
photo down(const photo &x)
{
    photo res;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            double tot = 0, cnt = 0;
            for (int k = std::max(i - 7, 1ll); k <= std::min(i + 7, n); ++k)
                for (int l = std::max(j - 7, 1ll); l <= std::min(j + 7, n); ++l)
                    tot += 1, cnt += x[k][l];
            res[i][j] = cnt / tot >= 0.5;
        }
    return res;
}
std::pair<double, int> find(photo &p, int x, int y)
{
    std::queue<std::pair<int, int>> que;
    double res1 = 0;
    int res2 = 0;
    que.push({x, y});
    p[x][y] = false;
    while (!que.empty())
    {
        std::pair<int, int> now = que.front();
        que.pop();
        res1 = std::max(res1, (double)sqrt(sqr(x - now.first) + sqr(y - now.second)));
        for (int i = 0; i != 4; ++i)
        {
            std::pair<int, int> to = {now.first + xx[i], now.second + yy[i]};
            if (p[to.first][to.second])
            {
                p[to.first][to.second] = false;
                ++res2;
                que.push(to);
            }
        }
    }
    return {res1, res2};
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> a[i][j];
    b = a;
    // for (int i = 1; i <= n; ++i, std::cout << std::endl)
    //     for (int j = 1; j <= n; ++j)
    //         std::cout << b[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (b[i][j])
            {
                // std::cout << i << ' ' << j << std::endl;
                std::pair<double, int> tmp = find(b, i, j);
                double d = tmp.first;
                double S1 = d * d * PI * 0.25, S2 = d * d * 0.5;
                int SS = tmp.second;
                if (fabs(SS - S1) < fabs(SS - S2))
                    ++circle;
                else
                    ++square;
                // if (n == 2000 && a[1][10])
                // std::cout << d << ' ' << fabs(SS - S1) << ' ' << fabs(SS - S2) << std::endl;
            }
    std::cout << circle << ' ' << square << std::endl;
    return 0;
}