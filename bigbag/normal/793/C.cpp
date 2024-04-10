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

const long double pi = 3.14159265358979323846, eps = 1e-10, inf = 111111111;

struct pointi {
    int x, y;
    pointi() {
        x = y = 0;
    }
    pointi(int x, int y) : x(x), y(y) {
    }
    void read() {
        scanf("%d%d", &x, &y);
    }
};

struct point {
    long double x, y;
    point() {
        x = y = 0;
    }
    point(long double x, long double y) : x(x), y(y) {
    }
    point(pointi p) : x(p.x), y(p.y) {
    }
    void write() {
        printf("%.5f %.5f\n", (double) x, (double) y);
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

const int max_n = 111111;

int n;
pointi q[5], a, b, p[max_n], v[max_n];

bool is_in(pointi p) {
    return a.x < p.x && p.x < b.x && a.y < p.y && p.y < b.y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    a.read();
    b.read();
    q[0] = pointi(a.x, a.y);
    q[1] = pointi(b.x, a.y);
    q[2] = pointi(b.x, b.y);
    q[3] = pointi(a.x, b.y);
    q[4] = q[0];
    vector<pair<long double, long double> > all;
    for (int i = 0; i < n; ++i) {
        p[i].read();
        v[i].read();
        if (v[i].x == 0 && v[i].y == 0) {
            if (is_in(p[i])) {
                all.push_back(make_pair(-inf, inf));
                continue;
            } else {
                printf("-1\n");
                return 0;
            }
        }
        if (v[i].x == 0) {
            if (p[i].x == a.x || p[i].x == b.x) {
                printf("-1\n");
                return 0;
            }
        }
        if (v[i].y == 0) {
            if (p[i].y == a.y || p[i].y == b.y) {
                printf("-1\n");
                return 0;
            }
        }
        long double d = dist(v[i]);
        point vv = v[i];
        vv = vv / d;
        point to = point(p[i]) + vv * 1111111;
        long double mn = inf, mx = -inf;
        if (is_in(p[i])) {
            mn = 0;
        }
        for (int j = 0; j < 4; ++j) {
            if (per_otr(p[i], to, q[j], q[j + 1])) {
                line l1 = line(p[i], to);
                line l2 = line(q[j], q[j + 1]);
                point A = p_line(l1, l2);
                long double tm = dist(p[i], A) / d;
                mn = min(mn, tm);
                mx = max(mx, tm);
            }
        }
        all.push_back(make_pair(mn, mx));
    }
    long double mn = inf, mx = 0;
    //cout.precision(20);
    //cout << fixed << mx << endl << mn << endl;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, all[i].first);
        mn = min(mn, all[i].second);
    }
    if (mx + eps <= mn) {
        printf("%.10f\n", (double) mx);
    } else {
        printf("-1\n");
    }
    return 0;
}