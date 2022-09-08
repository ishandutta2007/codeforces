#include <map>
#include <set>
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

const long double pi = 2 * acos(0.0), eps = 1e-9, inf = 1e18;

struct point {
    long double x, y;
    point() {
        x = y = 0;
    }
    point(long double x, long double y) : x(x), y(y) {
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
        return point(x - a.x, y - a.y);
    }
    point operator + (point a) {
        return point(x + a.x, y + a.y);
    }
    point operator * (long double a) {
        return point(x * a, y * a);
    }
    point operator / (long double a) {
        return point(x / a, y / a);
    }
};

struct line {
    long double A, B, C;
    line() {
        A = B = C = 0;
    }
    line(long double A, long double B, long double C) : A(A), B(B), C(C) {
    }
    line(point a, point b) {
		A = a.y - b.y;
		B = b.x - a.x;
		C = -A * a.x - B * a.y;
	}
    void write() {
        cout << A << ' ' << B << ' ' << C << endl;
    }
	void sdvig(long double x, long double y) {
		if (B != 0) {
			point p1 = point(1, (-C - A) / B);
			point p2 = point(2, (-C - 2 * A) / B);
			p1.x -= x;
			p1.y -= y;
			p2.x -= x;
			p2.y -= y;
			line l;
			l = line(p1, p2);
			A = l.A;
			B = l.B;
			C = l.C;
		} else {
			point p1 = point((B * y - C) / A, 1);
			point p2 = point((B * y - C) / A, 2);
			p1.x -= x;
			p1.y -= y;
			p2.x -= x;
			p2.y -= y;
			line l;
			l = line(p1, p2);
			A = l.A;
			B = l.B;
			C = l.C;
		}
	}
};

point mid(point a, point b) {
    return point((a.x + b.x) / 2, (a.y + b.y) / 2);
}

point get_point_in_line_x(line l, long double x) {
    return point(x, (-l.C - l.A * x) / l.B);
}

point get_point_in_line_y(line l, long double y) {
    return point((-l.B * y - l.C) / l.A, y);
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

long double cross_pr(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

long double vect_pr(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

long double dist(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

long double dist(point a, point b) {
    return dist(a - b);
}

long double dist(point p, line l) {
    return fabs((l.A * p.x + l.B * p.y + l.C) / sqrt(l.A * l.A + l.B * l.B));
}

bool is_in(point a, point b, point c) {
    return fabs(dist(a, b) - dist(a, c) - dist(b, c)) <= eps;
}

long double dist(point a, line b, point p1, point p2) {
    long double ret = dist(a, b);
    point p = point(b.A, b.B);
    p = p / dist(p);
    p = p * ret;
    point q = point(a.x - p.x, a.y - p.y);
    if (is_in(p1, p2, point(a.x - p.x, a.y - p.y)) || is_in(p1, p2, point(a.x + p.x, a.y + p.y))) {
        return ret;
    }
    return min(dist(a, p1), dist(a, p2));
}

long double angle(point a, point b) {
    return acos(cross_pr(a, b) / dist(a) / dist(b));
}

bool per_otr(point a, point b, point c, point d) {
    if (is_in(a, b, c) || is_in(a, b, d) || is_in(c, d, a) || is_in(c, d, b)) {
        return true;
    }
    line l(a, b), l1(c, d);
    point ans = p_line(l, l1);
    if (ans.x == -inf && ans.y == -inf) {
        return false;
    }
    if (is_in(a, b, ans) && is_in(c, d, ans)) {
        return true;
    }
    return false;
}

const int max_n = 101111;

int n;
long double mx = 0, mn = inf;
point o, p[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> o.x >> o.y;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        mx = max(mx, dist(o, p[i]));
    }
    p[n] = p[0];
    for (int i = 0; i < n; ++i) {
        mn = min(mn, dist(o, line(p[i], p[i + 1]), p[i], p[i + 1]));
    }
    printf("%.10f\n", (double) (pi * (mx - mn) * (mx + mn)));
    return 0;
}