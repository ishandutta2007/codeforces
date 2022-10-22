// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
const double eps = 1e-7;
const double PI = acos(-1);
// #define debug
int n, k;
struct node
{
    int x, y;
    double l, r;
} p[100005];
long long sqr(int x) { return 1ll * x * x; }
bool check(double r)
{
    int cnt = 0, ans = 0;
    std::map<double, int> map;
    for (int i = 1; i <= n; ++i)
        if (sqrt(sqr(p[i].x) + sqr(p[i].y)) / 2 <= r)
        {
            double c = atan2(p[i].x, p[i].y);
            double d = acos(sqrt(sqr(p[i].x) + sqr(p[i].y)) / 2 / r);
            p[i].l = c - d - eps;
            p[i].r = c + d + eps;
            // std::cout << p[i].l << ' ' << p[i].r << ' ' << c << ' ' << d << ' ' << sqrt(sqr(p[i].x) + sqr(p[i].y)) / 2 / r << ' ' << r << std::endl;
            if (p[i].l <= 0 && 0 <= p[i].r)
                ++cnt;
            if (p[i].l < 0)
                p[i].l += 2 * PI;
            if (p[i].r < 0)
                p[i].r += 2 * PI;
            ++map[p[i].l];
            --map[p[i].r];
        }
    ans = std::max(ans, cnt);
    for (auto i : map)
        ans = std::max(ans, cnt += i.second);
    return ans >= k;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i].x >> p[i].y;
    double l = 0, r = 200000;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    std::cout << std::fixed << std::setprecision(10) << l << std::endl;
    return 0;
}