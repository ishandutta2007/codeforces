// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, p[300005], q[300005];
struct point
{
    long double x, y;
    point(long double x_ = 0, long double y_ = 0) : x(x_), y(y_) {}
    point operator-() const { return point(-x, -y); }
    point &operator+=(const point &P) { return x += P.x, y += P.y, *this; }
    point &operator-=(const point &P) { return x -= P.x, y -= P.y, *this; }
    point &operator*=(const long double &P) { return x *= P, y *= P, *this; }
    friend point operator+(const point &A, const point &B) { return point(A) += B; }
    friend point operator-(const point &A, const point &B) { return point(A) -= B; }
    friend point operator*(const point &A, const long double &B) { return point(A) *= B; }
    friend point operator*(const long double &A, const point &B) { return point(B) *= A; }
    friend bool operator<(const point &A, const point &B) { return A.y * B.x > B.y * A.x; }
} c[300005], S, E;
std::multiset<point> set;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> S.x >> S.y;
        E = S;
        for (int i = 1; i <= n; ++i)
            std::cin >> c[i].x;
        for (int i = 1; i <= n; ++i)
            std::cin >> c[i].y, c[i].y *= -1;
        set.clear();
        for (int i = 1; i <= n; ++i)
        {
            S -= c[i];
            E += c[i];
            set.insert(c[i] * 2);
            while (S.x < -1e-10)
            {
                point tmp = *set.begin();
                set.erase(set.begin());
                if (S.x + tmp.x > 0)
                {
                    set.insert((S.x + tmp.x) / tmp.x * tmp);
                    S -= S.x / tmp.x * tmp;
                }
                else
                    S += tmp;
            }
            while (E.y < -1e-10)
            {
                point tmp = -*--set.end();
                set.erase(--set.end());
                if (E.y + tmp.y > 0)
                {
                    set.insert(-(E.y + tmp.y) / tmp.y * tmp);
                    E -= E.y / tmp.y * tmp;
                }
                else
                    E += tmp;
            }
            std::cout << E.x << '\n';
        }
    }
    return 0;
}