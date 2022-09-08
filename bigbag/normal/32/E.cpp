#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const double eps = 0.008, inf = 11111111;

struct point
{
    double x, y;
    void read() {
        cin >> x >> y;
    }
    void write() {
        cout << x << ' ' << y;
    }
    point operator - (point a) {
        point ret;
        ret.x = x - a.x;
        ret.y = y - a.y;
        return ret;
    }
    point operator + (point a) {
        point ret;
        ret.x = x + a.x;
        ret.y = y + a.y;
        return ret;
    }
    point operator * (int a)
    {
        point ret;
        ret.x = x * a;
        ret.y = y * a;
        return ret;
    }
    point operator / (int a) {
        point ret;
        ret.x = x / a;
        ret.y = y / a;
        return ret;
    }
};

struct line {
    double A, B, C;
    void write() {
        cout << A << ' ' << B << ' ' << C;
    }
};

point make_point(double x, double y) {
    point ret;
    ret.x = x;
    ret.y = y;
    return ret;
}

line get_line(point a, point b) {
    line ret;
    ret.A = a.y - b.y;
    ret.B = b.x - a.x;
    ret.C = -ret.A * a.x - ret.B * a.y;
    return ret;
}

point p_line(line a, line b) {
    point ret;
    if (fabs(a.A * b.B - b.A * a.B) <= eps) {
        ret.x = -inf;
        ret.y = -inf;
        return ret;
    }
    ret.y = (b.A * a.C - a.A * b.C) / (a.A * b.B - b.A * a.B);
    ret.x = (b.C * a.B - b.B * a.C) / (a.A * b.B - b.A * a.B);
    return ret;
}

double cross_pr(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

double dist(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

double dist(point a, point b) {
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dist(point a, line b) {
    return fabs((b.A * a.x + b.B * a.y + b.C) / sqrt(b.A * b.A + b.B * b.B));
}

double dist1(point a, point b) {
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double ang(point a, point b) {
    return acos(cross_pr(a, b) / dist(a) / dist(b));
}

bool is_in(point a, point b, point c) {
    /*a.write();
    cout << ' ';
    b.write();
    cout << ' ';
    c.write();
    cout << " = " << fabs(dist(a, b) - dist(a, c) - dist(b, c)) << endl;*/
    double x = dist1(a, b), y = dist1(a, c), z = dist1(b, c);
    return fabs(x - y - z - 2 * sqrt(y * z)) <= eps;
}

bool per_otr(point a, point b, point c, point d) {
    if (is_in(a, b, c) || is_in(a, b, d) || is_in(c, d, a) || is_in(c, d, b)) {
        return true;
    }
    line l = get_line(a, b), l1 = get_line(c, d);
    point ans = p_line(l, l1);
    if (ans.x == -inf && ans.y == -inf) {
        return false;
    }
    if (is_in(a, b, ans) && is_in(c, d, ans)) {
        return true;
    }
    return false;
}

bool one_polypl(point a, point b, point c, point d) {
    line l = get_line(a, b), l1 = get_line(c, d);
    point ans = p_line(l, l1);
    if (ans.x == -inf && ans.y == -inf) {
        return true;
    }
    if (is_in(a, b, ans)) {
        return false;
    }
    return true;
}

point v, p, w1, w2, z1, z2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    v.read();
    p.read();
    w1.read();
    w2.read();
    z1.read();
    z2.read();
    if (!per_otr(v, p, w1, w2) && !per_otr(v, p, z1, z2)) {
        cout << "YES" << endl;
        return 0;
    }
    if (!one_polypl(v, p, z1, z2)) {
        cout << "NO";
        return 0;
    }
    if (z1.x > z2.x) {
        swap(z1, z2);
    }
    line l = get_line(z1, z2);
    if (z1.x == z2.x) {
        if (z1.y > z2.y) {
            swap(z1, z2);
        }
        for (double y = z1.y; y <= z2.y; y += eps) {
            double x = z1.x;
            point z = make_point(x, y);
            if (fabs(ang(z1 - z, v - z) - ang(z2 - z, p - z)) <= eps) {
                if (!per_otr(v, z, w1, w2) && !per_otr(p, z, w1, w2)) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
        cout << "NO" << endl;
    } else {
        for (double x = z1.x; x <= z2.x; x += eps) {
            double y = (-l.C - l.A * x) / l.B;
            point z = make_point(x, y);
            if (fabs(ang(z1 - z, v - z) - ang(z2 - z, p - z)) <= eps) {// || fabs(ang(z2 - z, v - z) - ang(z1 - z, p - z)) <= eps || fabs(ang(z1 - z, v - z) - ang(z1 - z, p - z)) <= eps || fabs(ang(z2 - z, v - z) - ang(z2 - z, p - z)) <= eps) {
                if (!per_otr(v, z, w1, w2) && !per_otr(p, z, w1, w2)) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}