#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define x1 sdfg
#define x2 fgn
#define y1 sngf
#define y2 lmnvf

int x1, y1, x2, y2, vmax, t, vx[2], vy[2];
double a, b, d;

double getd(int vx, int vy, double a, double b) {
    double l = 0, r = 11111;
    for (int i = 0; i < 111; ++i) {
        double mid = (l + r) / 2;
        double aa = a * mid;
        double bb = b * mid;
        double xx = aa - vx;
        double yy = bb - vy;
        double dd = sqrt(xx * xx + yy * yy);
        if (dd <= vmax) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

double f(double x) {
    double y = sqrt(vmax * vmax - x * x);
    double aa = a - x * t;
    double bb = b - y * t;
    double dd = sqrt(aa * aa + bb * bb);
    aa /= dd;
    bb /= dd;
    double res = dd / getd(vx[1], vy[1], aa, bb);
    y *= -1;
    aa = a - x * t;
    bb = b - y * t;
    dd = sqrt(aa * aa + bb * bb);
    aa /= dd;
    bb /= dd;
    res = min(res, dd / getd(vx[1], vy[1], aa, bb));
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x1 >> y1 >> x2 >> y2 >> vmax >> t >> vx[0] >> vy[0] >> vx[1] >> vy[1];
    if (x1 == x2 && y1 == y2) {
        cout << 0 << endl;
        return 0;
    }
    a = x2 - x1;
    b = y2 - y1;
    double all = sqrt(a * a + b * b);
    d = sqrt(a * a + b * b);
    a /= d;
    b /= d;
    double d1 = getd(vx[0], vy[0], a, b);
    if (d1 * t >= all) {
        printf("%.10f\n", all / d1);
        return 0;
    }
    a = x2 - x1;
    b = y2 - y1;
    a -= vx[0] * t;
    b -= vy[0] * t;
    double l = -vmax, r = vmax;
    for (int i = 0; i < 111; ++i) {
        double mid1 = (2 * l + r) / 3, mid2 = (l + 2 * r) / 3;
        if (f(mid1) > f(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    printf("%.10f\n", t + f(l));
    return 0;
}