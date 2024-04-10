// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const double PI = std::acos(-1);
int n, m, ans;
template <class T>
auto sqr(const T &x) { return x * x; }
struct point
{
    double x, y;
    point(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
    friend std::istream &operator>>(std::istream &A, point &B) { return A >> B.x >> B.y; }
    friend point operator+(const point &A, const point &B) { return point(A.x + B.x, B.y + B.y); }
    friend point operator-(const point &A, const point &B) { return point(A.x - B.x, A.y - B.y); }
    friend point operator-(const point &A) { return point(-A.x, -A.y); }
    friend double operator*(const point &A, const point &B) { return A.x * B.x + A.y * B.y; }
    friend double operator^(const point &A, const point &B) { return A.x * B.y - B.x * A.y; }
    friend double dis(const point &A, const point &B) { return std::sqrt(sqr(A - B)); }
    friend double atan2(const point &A) { return std::atan2(A.x, A.y); }
};
point a[3005];
bool good[3005][3005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        double l = -PI, r = 2 * PI;
        for (int j = 1; j <= n; ++j)
        {
            double d = dis(a[i], a[j]);
            if (d > m)
            {
                double alpha = atan2(a[j] - a[i]), beta = std::asin(m / d);
                double L = alpha - beta, R = alpha + beta;
                if (L >= PI)
                    L -= PI * 2;
                if (R <= 0)
                    R += PI * 2;
                if (R - L >= PI * 2)
                    R -= PI * 2;
                l = std::max(l, L);
                r = std::min(r, R);
            }
        }
        for (int j = 1; j <= n; ++j)
        {
            double alpha = atan2(a[j] - a[i]);
            if ((l <= alpha && alpha <= r) || (l <= alpha + PI * 2 && alpha + PI * 2 <= r))
                good[i][j] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (good[i][j] && good[j][i])
                ++ans;
    std::cout << ans << std::endl;
    return 0;
}