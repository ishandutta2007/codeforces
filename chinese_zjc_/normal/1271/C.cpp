// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, sx, sy, x[200005], y[200005], ans, X, Y;
void work(int px, int py)
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (std::min(x[i], sx) <= px && px <= std::max(x[i], sx) &&
            std::min(y[i], sy) <= py && py <= std::max(y[i], sy))
            ++res;
    if (res > ans)
    {
        ans = res;
        X = px;
        Y = py;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> sx >> sy;
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i] >> y[i];
    work(sx + 1, sy);
    work(sx, sy + 1);
    work(sx - 1, sy);
    work(sx, sy - 1);
    std::cout << ans << std::endl
              << X << ' ' << Y << std::endl;
    return 0;
}