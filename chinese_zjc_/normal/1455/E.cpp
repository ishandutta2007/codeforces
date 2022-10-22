// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
const long long INF = LLONG_MAX >> 1;
int T, x[4], y[4], c[4], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        for (int i = 0; i != 4; ++i)
            std::cin >> x[i] >> y[i], c[i] = i;
        ans = INF;
        do
        {
            int x1 = x[c[0]], y1 = y[c[0]],
                x2 = x[c[1]], y2 = y[c[1]],
                x3 = x[c[2]], y3 = y[c[2]],
                x4 = x[c[3]], y4 = y[c[3]],
                minx = std::min(x2, x4) - std::max(x1, x3), maxx = std::max(x2, x4) - std::min(x1, x3),
                miny = std::min(y3, y4) - std::max(y1, y2), maxy = std::max(y3, y4) - std::min(y1, y2),
                step = maxx - minx + maxy - miny;
            if (std::max(minx, miny) > std::min(maxx, maxy))
                step += 2 * (maxx < maxy ? miny - maxx : minx - maxy);
            ans = std::min(ans, step);
        } while (std::next_permutation(c, c + 4));
        std::cout << ans << std::endl;
    }
    return 0;
}