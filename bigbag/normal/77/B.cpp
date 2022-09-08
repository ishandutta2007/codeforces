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

const double eps = 1e-9;

struct point {
    double x, y;
    point() {
        x = y = 0;
    }
    point(double xx, double yy) {
        x = xx;
        y = yy;
    }
    void read() {
        cin >> x >> y;
    }
    void write() {
        printf("%.5f %.5f", x, y);
    }
    bool operator == (point a) {
        return fabs(x - a.x) <= eps && fabs(y - a.y) <= eps;
    }
    point operator - (point a) {
        point ret;
        ret.x = x - a.x;
        ret.y = y - a.y;
        return ret;
    }
};

struct line {
    double A, B, C;
    line() {
        A = B = C = 0;
    }
    line(double a, double b, double c) {
        A = a, B = b, C = c;
    }
    void write() {
        cout << A << ' ' << B << ' ' << C;
    }
};

line get_line(point a, point b) {
    line ret;
    ret.A = a.y - b.y;
    ret.B = b.x - a.x;
    ret.C = -ret.A * a.x - ret.B * a.y;
    return ret;
}

point p_line(line a, line b) {
    point ret;
    ret.y = (b.A * a.C - a.A * b.C) / (a.A * b.B - b.A * a.B);
    ret.x = (b.C * a.B - b.B * a.C) / (a.A * b.B - b.A * a.B);
    return ret;
}

int t;

double get_ans(double a, double b) {
    if (b == 0) {
        return 1;
    }
    if (a == 0) {
        return 0.5;
    }
    line l1 = get_line(point(0, a), point(1, a));
    line l2 = get_line(point(0, 0), point(1, 4));
    point p = p_line(l1, l2);
    if (p.x <= b) {
        double d = p.x;
        double S = a * b + a * d / 2;
        return S / (2 * a * b);
    } else {
        l1 = get_line(point(b, 0), point(b, a));
        p = p_line(l1, l2);
        double d = p.y;
        double S = 2 * a * b - b * d / 2;
        return S / (2 * a * b);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%.15lf\n", get_ans(a, b));
    }
    return 0;
}