#include <cstdio>
#include <cmath>

const double eps = 1e-7;
double vm;
double st;

double go(double l, double r, double x, double y, double vx, double vy) {
    bool ne = false;
    if (l > eps) {
        ne = true;
    }
    int iter = 0;
    bool ok = false;
    while (l + eps < r && iter < 120) {
        ++iter;
        double m = (l + r) / 2;
        double tt = m;
        if (ne) {
            tt -= st;
        }
        double dx = (x - vx*tt) / m;
        double dy = (y - vy*tt) / m;
        if (dx * dx + dy * dy < vm * vm) {
            ok = true;
            r = m;
        } else {
            l = m;
        }
    }
    if (!ok) {
        return -1;
    }
    return r;
}

int main() {
    double x1, y1, x2, y2, vx, vy, ux, uy, t;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    scanf("%lf %lf", &vm, &t);
    scanf("%lf %lf %lf %lf", &vx, &vy, &ux, &uy);
    st = t;
    double r = go(0, t, x2 - x1, y2 - y1, vx, vy);
    if (r >= -eps) {
        printf("%.10lf\n", r);
    } else {
        r = go(t, 1e10, x2 - x1 - vx*t, y2 - y1 - vy*t, ux, uy);
        printf("%.10lf\n", r);
    }
    return 0;
}