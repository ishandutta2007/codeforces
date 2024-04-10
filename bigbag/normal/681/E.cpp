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

const int max_n = 111111;
const unsigned long long inf = 4111111111;
const long double pi = 2 * acos((long double) 0), eps = 1e-9;

#define x0 qwe
#define y0 ewq

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

struct circle {
	long double a, b, r;
	circle() {
		a = b = r = 0;
	}
	circle(long double a, long double b, long double r) : a(a), b(b), r(r) {
	}
};

vector<point> per_circle_line(circle c, line l) {
	point qqq = point(c.a, c.b);
	vector<point> ret;
	l.sdvig(c.a, c.b);
	c.a = c.b = 0;
	long double d = dist(point(0, 0), l);
	if (d > c.r) {
		return ret;
	}
	point p = point(l.A, l.B);
	p = p / dist(p);
	if (-l.C / l.B > 0) {
		p = p * d;
	} else {
		p = p * (-d);
	}
	long double d1 = sqrt(c.r * c.r - d * d);
	point p1 = point(-l.B, l.A);
	p1 = p1 / dist(p1);
	p1 = p1 * d1;
	if (d == c.r) {
		ret.push_back(p + p1 + qqq);
	} else {
		ret.push_back(p + p1 + qqq);
		ret.push_back(p - p1 + qqq);
	}
	return ret;
}

vector<point> per_circle_circle(circle c1, circle c2) {
    if (c1.a == c2.a && c1.b == c2.b) {
        vector<point> ret;
        if (c1.r == c2.r) {
            ret.push_back(point(inf, inf));
        }
        return ret;
    }
    long double sd_x = c1.a, sd_y = c1.b;
    c1.a -= sd_x;
    c2.a -= sd_x;
    c1.b -= sd_y;
    c2.b -= sd_y;
    line l = line(2 * c2.a, 2 * c2.b, c2.r * c2.r - c2.a * c2.a - c2.b * c2.b - c1.r * c1.r);
    vector<point> ret = per_circle_line(c1, l);
    for (int i = 0; i < ret.size(); ++i) {
        ret[i].x += sd_x;
        ret[i].y += sd_y;
    }
    return ret;
}

int x0, y0, v, t, n, x[max_n], y[max_n], r[max_n];
unsigned long long l;
vector<pair<long double, long double> > q;

unsigned long long dist(int x, int y) {
    return 1LL * x * x + 1LL * y * y;
}

double fun(long double x) {
    return x / pi * 180;
}

void add2(long double l, long double r) {
    q.push_back(make_pair(l, r));
}

void add(long double ang0, long double ang) {
    //printf("(%.5f %.5f)\n", fun(ang0), fun(ang));
    long double l = ang0 - ang;
    long double r = ang0 + ang;
    if (r > 2 * pi) {
        add2(l, 2 * pi);
        add2(0, r - 2 * pi);
    } else if (l < 0) {
        add2(0, r);
        add2(l + 2 * pi, 2 * pi);
    } else {
        add2(l, r);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &x0, &y0, &v, &t);
    scanf("%d", &n);
    l = 1LL * v * t;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
        x[i] -= x0;
        y[i] -= y0;
        unsigned long long d = dist(x[i], y[i]);
        if (d <= 1LL * r[i] * r[i]) {
            printf("1.000000000\n");
            return 0;
        }
        unsigned long long sq = d - 1LL * r[i] * r[i];
        long double ang;
        if (sq <= l * l || l > inf) {
            ang = asin(r[i] / sqrt((long double) d));
        } else {
            circle c1 = circle(0, 0, l);
            circle c2 = circle(x[i], y[i], r[i]);
            vector<point> v = per_circle_circle(c1, c2);
            if (v.size() == 0) {
                continue;
            }
            long double a1 = atan2(v[0].y, v[0].x);
            long double a2 = atan2(y[i], x[i]);
            a1 = fabs(a1 - a2);
            ang = min(a1, 2 * pi - a1);
        }
        long double ang0 = atan2(y[i], x[i]);
        if (ang0 < 0) {
            ang0 += 2 * pi;
        }
        add(ang0, ang);
    }
    /*printf("\n");
    for (int i = 0; i < q.size(); ++i) {
        printf("(%.5f %.5f)\n", fun(q[i].first), fun(q[i].second));
    }*/
    sort(q.begin(), q.end());
    long double ans = 0, r = 0;
    for (int i = 0; i < q.size(); ++i) {
        if (r <= q[i].second) {
            ans += q[i].second - max(q[i].first, r);
            r = q[i].second;
        }
    }
    //printf("%.10f\n", fun(ans));
    printf("%.10f\n", (double) (ans / (2 * pi)));
    return 0;
}