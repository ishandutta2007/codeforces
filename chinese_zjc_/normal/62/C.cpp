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
const double eps = 0.000000001;
const int INF = 0x3fffffffffffffff;
double sqr(double x) { return x * x; }
bool eq(double A, double B) { return fabs(A - B) / std::max(1.0l, B) <= eps; }
struct point
{
    double x, y;
    friend point operator+(const point &A, const point &B) { return {A.x + B.x, A.y + B.y}; }
    friend point operator-(const point &A, const point &B) { return {A.x - B.x, A.y - B.y}; }
    point operator*(const double &V) { return {x * V, y * V}; }
    friend bool operator<(const point &A, const point &B) { return eq(A.x, B.x) ? A.y < B.y : A.x < B.x; }
    friend bool operator==(const point &A, const point &B) { return eq(A.x, B.x) && eq(A.y, B.y); }
    friend bool operator<=(const point &A, const point &B) { return !(B < A); }
    friend double dis(const point &A, const point &B) { return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y)); }
};
struct segment
{
    point p[2];
};
double cross(const point &A, const point &B) { return A.x * B.y - A.y * B.x; }
struct triangle
{
    point p[3];
    double area() const { return fabsl(cross(p[1] - p[0], p[2] - p[0])) / 2; }
} a[305];
std::vector<segment> seg;
int n;
double ans;
bool meet(segment A, segment B)
{
    return std::max(std::min(A.p[0].x, A.p[1].x), std::min(B.p[0].x, B.p[1].x)) <=
               std::min(std::max(A.p[0].x, A.p[1].x), std::max(B.p[0].x, B.p[1].x)) &&
           std::max(std::min(A.p[0].y, A.p[1].y), std::min(B.p[0].y, B.p[1].y)) <=
               std::min(std::max(A.p[0].y, A.p[1].y), std::max(B.p[0].y, B.p[1].y)) &&
           cross(A.p[0] - B.p[0], B.p[1] - B.p[0]) * cross(A.p[1] - B.p[0], B.p[1] - B.p[0]) <= 0 &&
           cross(B.p[0] - A.p[0], A.p[1] - A.p[0]) * cross(B.p[1] - A.p[0], A.p[1] - A.p[0]) <= 0;
}
bool on(segment A, point B)
{
    return eq(cross(A.p[1] - A.p[0], B - A.p[0]), 0) && std::min(A.p[0], A.p[1]) <= B && B <= std::max(A.p[0], A.p[1]);
}
point inter(segment A, segment B)
{
    return A.p[0] +
           (A.p[1] - A.p[0]) * (cross(B.p[1] - B.p[0], A.p[0] - B.p[0]) / cross(A.p[1] - A.p[0], B.p[1] - B.p[0]));
}
bool in(triangle A, point B)
{
    return eq(triangle{A.p[0], A.p[1], B}.area() +
                  triangle{A.p[1], A.p[2], B}.area() +
                  triangle{A.p[2], A.p[0], B}.area(),
              A.area());
}
bool check(segment x)
{
    for (int i = 0; i != n; ++i)
        if (in(a[i], x.p[0]) && in(a[i], x.p[1]))
        {
            bool flag = false;
            for (int j = 0; j != 3; ++j)
                if (on({a[i].p[j], a[i].p[(j + 1) % 3]}, x.p[0]) && on({a[i].p[j], a[i].p[(j + 1) % 3]}, x.p[1]))
                    flag = true;
            if (!flag)
                return false;
        }
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    std::cout << std::fixed << std::setprecision(20);
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != 3; ++j)
            std::cin >> a[i].p[j].x >> a[i].p[j].y;
        for (int j = 0; j != 3; ++j)
            seg.push_back({a[i].p[j], a[i].p[(j + 1) % 3]});
    }
    for (int i = 0; i != (int)seg.size(); ++i)
    {
        std::vector<point> p;
        for (int j = 0; j != (int)seg.size(); ++j)
        {
            if (i == j)
                continue;
            if (meet(seg[i], seg[j]))
            {
                point tmp = inter(seg[i], seg[j]);
                if (tmp.x != tmp.x || tmp.y != tmp.y);
                    // std::cout << seg[i].p[0].x << ' ' << seg[i].p[0].y << ' ' << seg[i].p[1].x << ' ' << seg[i].p[1].y << std::endl
                    //           << seg[j].p[0].x << ' ' << seg[j].p[0].y << ' ' << seg[j].p[1].x << ' ' << seg[j].p[1].y << std::endl;
                else
                    p.push_back(tmp);
            }
        }
        p.push_back(seg[i].p[0]);
        p.push_back(seg[i].p[1]);
        std::sort(p.begin(), p.end());
        p.erase(std::unique(p.begin(), p.end()), p.end());
        for (int j = 1; j != (int)p.size(); ++j)
            if (check({p[j - 1], p[j]}))
                ans += dis(p[j - 1], p[j]);
    }
    std::cout << ans << std::endl;
    return 0;
}