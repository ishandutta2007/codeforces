#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 1000008;
typedef std::pair<int64, int64> point;
typedef std::pair<double, double> point_f;
#define x first
#define y second
template <typename T> inline int sign(const T x) { return x < 0 ? -1 : (x > 0 ? 1 : 0); }
template <typename T> inline T abs(const T x) { return x < 0 ? -x : x; }

int n, x_tot, y_tot;
point p[MAXN];
const point POINT_ZERO = point(0, 0);
const point POINTF_ZREO = point_f(0.0, 0.0);

inline point operator - (const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
}
inline point operator * (const point &a, const int64 b) {
    return point(a.x * b, a.y * b);
}
inline int64 cross(const point &a, const point &b) {
    return (int64)a.x * b.y - (int64)a.y * b.x;
}
inline point_f seg_intsct(const point &a, const point &b, const point &c, const point &d) {
    bool c1 = (sign(cross(a - c, b - c)) * sign(cross(a - d, b - d)) <= 0),
        c2 = (sign(cross(c - a, d - a)) * sign(cross(c - b, d - b)) <= 0);
    if (!c1 || !c2) return point_f(-1, -1);
    double k = abs((double)cross(d - a, b - a) / cross(c - a, b - a));
    return point_f((k * c.x + d.x) / (1.0 + k), (k * c.y + d.y) / (1.0 + k));
}

int *convex_hull(int n, point *p)
{
    std::sort(p, p + n);
    int *s = new int[n + 3], ct = 0, lower_ct = 0;
    for (int i = 0; i < n; ++i) {
        while (ct > 1 && cross(p[s[ct - 1]] - p[s[ct - 2]], p[i] - p[s[ct - 1]]) <= 0) --ct;
        s[ct++] = i;
    }
    lower_ct = ct;
    for (int i = n - 2; i >= 0; --i) {
        while (ct > lower_ct && cross(p[s[ct - 1]] - p[s[ct - 2]], p[i] - p[s[ct - 1]]) <= 0) --ct;
        s[ct++] = i;
    }
    s[ct - 1] = s[0];
    s[ct] = -1;
    return s;
}

int main()
{
    scanf("%d%d%d", &n, &x_tot, &y_tot);
    int64 x_max = -1, y_max = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &p[i].x, &p[i].y);
        x_max = std::max(x_max, p[i].x);
        y_max = std::max(y_max, p[i].y);
    }
    p[n++] = point(x_max, 0);
    p[n++] = point(0, y_max);

    int *cvx = convex_hull(n, p);
    double max_intsc_x = -1.233;
    point target = point(x_tot, y_tot) * (int64)((double)x_max * 2 / x_tot + 5);
    point_f r;
    for (++cvx; *cvx != -1; ++cvx) {
        r = seg_intsct(POINT_ZERO, target, p[*(cvx - 1)], p[*cvx]);
        if (r.x != -1.0)
            max_intsc_x = std::max(max_intsc_x, r.x);
    }
    printf("%.12lf\n", (double)x_tot / max_intsc_x);

    return 0;
}