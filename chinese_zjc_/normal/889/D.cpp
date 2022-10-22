// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
struct point
{
    long long x, y;
    point() : x(), y() {}
    point(long long x_, long long y_) : x(x_), y(y_) {}
    point &operator+=(const point &val)
    {
        x += val.x;
        y += val.y;
        return *this;
    }
    point &operator-=(const point &val)
    {
        x -= val.x;
        y -= val.y;
        return *this;
    }
    point &operator*=(const int &val)
    {
        x *= val;
        y *= val;
        return *this;
    }
    point &operator/=(const int &val)
    {
        x /= val;
        y /= val;
        return *this;
    }
    point operator+(const point &val) const { return point(*this) += val; }
    point operator*(const int &val) const { return point(*this) *= val; }
    point operator/(const long long &val) const { return point(*this) /= val; }
    friend bool operator==(const point &A, const point &B) { return A.x == B.x && A.y == B.y; }
    friend bool operator<(const point &A, const point &B) { return A.x == B.x ? A.y < B.y : A.x < B.x; }
    point operator-() const { return point(-x, -y); }
    friend long long operator*(const point &A, const point &B) { return A.x * B.y - A.y * B.x; }
} c;
std::vector<point> p, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    p.resize(n);
    for (int i = 0; i != n; ++i)
        std::cin >> p[i].x >> p[i].y, c += p[i] * 2, p[i] *= 2 * n;
    for (int i = 0; i != n; ++i)
        p[i] -= c;
    for (std::size_t i = 0; i != p.size(); ++i)
    {
        for (std::size_t j = i; ++j != p.size();)
            if (p[i] == -p[j])
            {
                p.erase(p.begin() + j);
                p.erase(p.begin() + i);
                --i;
                break;
            }
    }
    n = p.size();
    if (n <= 1)
        return std::cout << -1 << std::endl, 0;
    // std::cout << c.x << ' ' << c.y << std::endl;
    for (int i = 0; i != n; ++i)
        if (p[i].x || p[i].y)
            std::swap(p[i], p[0]);
    for (int i = 0; i != n; ++i)
    {
        point mid = (p[0] + p[i]) / 2;
        std::vector<long long> tmp;
        for (int j = 0; j != n; ++j)
            tmp.push_back(mid * p[j]);
        std::sort(tmp.begin(), tmp.end());
        bool good = true;
        for (int j = 0; j != n; ++j)
            good &= tmp[j] == -tmp[n - j - 1];
        if (good)
            ans.push_back(mid);
    }
    for (auto &i : ans)
    {
        long long gcd = std::__gcd(i.x, i.y);
        i /= gcd;
    }
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    std::cout << ans.size() << std::endl;
    return 0;
}