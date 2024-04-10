//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#define y1 WHATTHEFUCK
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
int n, m, t, h[305][305], tp, tu, td,
    ru[305][305], rd[305][305], rp[305][305],
    lu[305][305], ld[305][305], lp[305][305],
    du[305][305], dd[305][305], dp[305][305],
    uu[305][305], ud[305][305], up[305][305],
    ans = INF, x1, x2, y1, y2;
int calc(int x1, int y1, int x2, int y2)
{
    int d = rd[x1][y2] - rd[x1][y1] +
            dd[x2][y2] - dd[x1][y2] +
            ld[x2][y1] - ld[x2][y2] +
            ud[x1][y1] - ud[x2][y1],
        u = ru[x1][y2] - ru[x1][y1] +
            du[x2][y2] - du[x1][y2] +
            lu[x2][y1] - lu[x2][y2] +
            uu[x1][y1] - uu[x2][y1],
        p = rp[x1][y2] - rp[x1][y1] +
            dp[x2][y2] - dp[x1][y2] +
            lp[x2][y1] - lp[x2][y2] +
            up[x1][y1] - up[x2][y1];
    // std::cout << d << ' ' << u << ' ' << p << std::endl;
    return d * td + u * tu + p * tp;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> t >> tp >> tu >> td;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> h[i][j];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ru[i][j] = ru[i][j - 1] + (h[i][j] > h[i][j - 1]);
            rd[i][j] = rd[i][j - 1] + (h[i][j] < h[i][j - 1]);
            rp[i][j] = rp[i][j - 1] + (h[i][j] == h[i][j - 1]);
        }
        for (int j = m; j; --j)
        {
            lu[i][j] = lu[i][j + 1] + (h[i][j] > h[i][j + 1]);
            ld[i][j] = ld[i][j + 1] + (h[i][j] < h[i][j + 1]);
            lp[i][j] = lp[i][j + 1] + (h[i][j] == h[i][j + 1]);
        }
    }
    for (int j = 1; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            du[i][j] = du[i - 1][j] + (h[i][j] > h[i - 1][j]);
            dd[i][j] = dd[i - 1][j] + (h[i][j] < h[i - 1][j]);
            dp[i][j] = dp[i - 1][j] + (h[i][j] == h[i - 1][j]);
        }
        for (int i = n; i; --i)
        {
            uu[i][j] = uu[i + 1][j] + (h[i][j] > h[i + 1][j]);
            ud[i][j] = ud[i + 1][j] + (h[i][j] < h[i + 1][j]);
            up[i][j] = up[i + 1][j] + (h[i][j] == h[i + 1][j]);
        }
    }
    /*
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = i + 2; k <= n; ++k)
                for (int l = j + 2; l <= m; ++l)
                {
                    int tmp = calc(i, j, k, l);
                    if (llabs(t - tmp) < llabs(t - ans))
                    {
                        ans = tmp;
                        x1 = i;
                        y1 = j;
                        x2 = k;
                        y2 = l;
                    }
                }
    */
    for (int i = 1; i <= n; ++i)
        for (int j = i + 2; j <= n; ++j)
        {
            std::map<int, int> map;
            for (int k = 3; k <= m; ++k)
            {
                // int d = rd[x1][y2] - rd[x1][y1] +
                //         dd[x2][y2] - dd[x1][y2] +
                //         ld[x2][y1] - ld[x2][y2] +
                //         ud[x1][y1] - ud[x2][y1],
                //     u = ru[x1][y2] - ru[x1][y1] +
                //         du[x2][y2] - du[x1][y2] +
                //         lu[x2][y1] - lu[x2][y2] +
                //         uu[x1][y1] - uu[x2][y1],
                //     p = rp[x1][y2] - rp[x1][y1] +
                //         dp[x2][y2] - dp[x1][y2] +
                //         lp[x2][y1] - lp[x2][y2] +
                //         up[x1][y1] - up[x2][y1];
                map.insert({(-rd[i][k - 2] + ld[j][k - 2] + ud[i][k - 2] - ud[j][k - 2]) * td +
                                (-ru[i][k - 2] + lu[j][k - 2] + uu[i][k - 2] - uu[j][k - 2]) * tu +
                                (-rp[i][k - 2] + lp[j][k - 2] + up[i][k - 2] - up[j][k - 2]) * tp,
                            k - 2});
                int now = (rd[i][k] + dd[j][k] - dd[i][k] - ld[j][k]) * td +
                          (ru[i][k] + du[j][k] - du[i][k] - lu[j][k]) * tu +
                          (rp[i][k] + dp[j][k] - dp[i][k] - lp[j][k]) * tp;
                std::map<int, int>::iterator tmp = map.lower_bound(t - now);
                if (tmp != map.end() && llabs(tmp->first + now - t) < llabs(ans - t))
                    x1 = i, x2 = j, y1 = tmp->second, y2 = k, ans = tmp->first + now;
                if (tmp != map.begin() && llabs((--tmp)->first + now - t) < llabs(ans - t))
                    x1 = i, x2 = j, y1 = tmp->second, y2 = k, ans = tmp->first + now;
            }
        }
    // std::cout << calc(1, 1, 4, 4) << ' ' << ans << std::endl;
    std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << std::endl;
    return 0;
}