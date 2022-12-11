#include <cstdio>
#include <cmath>
typedef long long int64;
static const double EPS = 1e-7;
static const int INF = 0x7fffffff;
static const int MAXN = 10006;

int n, v, w, u;
int x[MAXN], y[MAXN];

template <typename T> inline int sign(const T x) {
    return ((x > -EPS && x < EPS) ? 0 : (x > 0 ? 1 : -1));
}
inline double cross(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

inline bool intersect_semistrict(
    double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
{
    return sign(cross(x1, y1, x3, y3, x2, y2)) * sign(cross(x1, y1, x4, y4, x2, y2)) <= 0 &&
        sign(cross(x3, y3, x1, y1, x4, y4)) * sign(cross(x3, y3, x2, y2, x4, y4)) < 0;
}
inline bool intersect(
    double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
{
    return sign(cross(x1, y1, x3, y3, x2, y2)) * sign(cross(x1, y1, x4, y4, x2, y2)) <= 0 &&
        sign(cross(x3, y3, x1, y1, x4, y4)) * sign(cross(x3, y3, x2, y2, x4, y4)) <= 0;
}

int main()
{
    scanf("%d%d%d%d", &n, &w, &v, &u);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
    x[n] = x[0]; y[n] = y[0];

    bool no_intsc = true;
    for (int i = 0; i < n; ++i) {
        if (intersect_semistrict(0, 0, (double)w / u * v, w, x[i], y[i], x[i + 1], y[i + 1])) {
            no_intsc = false; break;
        }
    }
    if (no_intsc) {
        printf("%.12lf\n", (double)w / u);
        return 0;
    }

    int sx = 0, sy = INF, idx = -1;
    for (int i = 0; i < n; ++i) {
        // if (x[i] > 0 && y[i] / x[i] < sy / sx)
        if (x[i] > 0 && (int64)y[i] * sx < (int64)x[i] * sy) {
            sx = x[i]; sy = y[i]; idx = i;
        }
    }
    double cx = sx, cy = sy;
    while (true) {
        // if ((y[idx + 1] - y[idx]) / (x[idx + 1] - x[idx]) >= u / v)
        if ((int64)v * (y[idx + 1] - y[idx]) >= (int64)u * (x[idx + 1] - x[idx])) {
            cx += ((double)w - cy) / u * v;
            cy = w;
            break;
        }
        idx = (idx + 1) % n;
        cx = x[idx]; cy = y[idx];
    }

    printf("%.12lf\n", (double)cx / v);

    return 0;
}