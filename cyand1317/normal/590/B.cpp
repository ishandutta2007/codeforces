#include <cstdio>
#include <cmath>
#define y1 __y1
template <typename T> inline T sqr(const T x) { return x * x; }

int x1, y1, x2, y2;
int vmax, t;
int vx, vy, wx, wy;

inline bool check(double time)
{
    double float_x, float_y;
    if (time <= t) {
        float_x = time * vx;
        float_y = time * vy;
    } else {
        float_x = (double)t * vx + (time - t) * wx;
        float_y = (double)t * vy + (time - t) * wy;
    }
    float_x += x1;
    float_y += y1;
    // mdzz~~~ (` )
    return sqrt(sqr((double)x2 - float_x) + sqr((double)y2 - float_y)) <= time * vmax;
}

int main()
{
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d%d%d%d%d%d", &vmax, &t, &vx, &vy, &wx, &wy);

    double lo = 0, hi = 1e12, mid;
    for (int i = 0; i < 100; ++i) {
        mid = (lo + hi) / 2;
        if (check(mid)) hi = mid; else lo = mid;
    }

    printf("%.9lf\n", (lo + hi) / 2);
    return 0;
}