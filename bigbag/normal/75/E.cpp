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

const double pi = 3.14159265358979323846, eps = 1e-9, inf = 111111111;
const int max_n = 33;

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
    point operator + (point a) {
        point ret;
        ret.x = x + a.x;
        ret.y = y + a.y;
        return ret;
    }
    point operator * (double a) {
        point ret;
        ret.x = x * a;
        ret.y = y * a;
        return ret;
    }
    point operator / (double a) {
        point ret;
        ret.x = x / a;
        ret.y = y / a;
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
    void get_line(point a, point b) {
		A = a.y - b.y;
		B = b.x - a.x;
		C = -A * a.x - B * a.y;
	}
	void sdvig(double x, double y) {
		if (B != 0) {
			point p1 = point(1, (-C - A) / B);
			point p2 = point(2, (-C - 2 * A) / B);
			p1.x -= x;
			p1.y -= y;
			p2.x -= x;
			p2.y -= y;
			line l;
			l.get_line(p1, p2);
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
			l.get_line(p1, p2);
			A = l.A;
			B = l.B;
			C = l.C;
		}
	}
};

point mid(point a, point b) {
    point ret;
    ret.x = (a.x + b.x) / 2;
    ret.y = (a.y + b.y) / 2;
    return ret;
}

line get_line(point a, point b) {
    line ret;
    ret.A = a.y - b.y;
    ret.B = b.x - a.x;
    ret.C = -ret.A * a.x - ret.B * a.y;
    return ret;
}

point get_point_in_line_x(line l, double x) {
    point ret;
    ret.x = x;
    ret.y = (-l.C - l.A * x) / l.B;
    return ret;
}

point get_point_in_line_y(line l, double y) {
    point ret;
    ret.x = (-l.B * y - l.C) / l.A;
    ret.y = y;
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

double vect_pr(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

double dist(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dist(point a, line b) {
    return fabs((b.A * a.x + b.B * a.y + b.C) / sqrt(b.A * b.A + b.B * b.B));
}

bool is_in(point a, point b, point c) {
    return fabs(dist(a, b) - dist(a, c) - dist(b, c)) <= eps;
}

double dist(point a, line b, point p1, point p2) {
    double ret = dist(a, b);
    point p = point(b.A, b.B);
    p = p / dist(p);
    p = p * ret;
    point q = point(a.x - p.x, a.y - p.y);
    if (is_in(p1, p2, point(a.x - p.x, a.y - p.y)) || is_in(p1, p2, point(a.x + p.x, a.y + p.y))) {
        return ret;
    }
    return min(dist(a, p1), dist(a, p2));
}

double angle(point a, point b) {
    return acos(cross_pr(a, b) / dist(a) / dist(b));
}

bool per_otr(point a, point b, point c, point d) {
    line l = get_line(a, b), l1 = get_line(c, d);
    point ans = p_line(l, l1);
    if (ans.x == -inf && ans.y == -inf) {
        return false;
    }
    if (is_in(a, b, c) || is_in(a, b, d) || is_in(c, d, a) || is_in(c, d, b)) {
        return true;
    }
    if (is_in(a, b, ans) && is_in(c, d, ans)) {
        return true;
    }
    return false;
}

point start, fin;
int n;
point p[max_n];
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    start.read();
    fin.read();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p[i].read();
    }
    p[n] = p[0];
    for (int i = 0; i < n; ++i) {
        if (per_otr(start, fin, p[i], p[i + 1])) {
            v.push_back(i);
        }
    }
    if (v.size() == 0) {
        printf("%.10f\n", dist(start, fin));
        return 0;
    }
    point p1 = p_line(get_line(start, fin), get_line(p[v[0]], p[v[0] + 1]));
    point p2 = p_line(get_line(start, fin), get_line(p[v[1]], p[v[1] + 1]));
    if (p1 == p2 && v.size() > 2) v[1] = v[2];
    p1 = p_line(get_line(start, fin), get_line(p[v[0]], p[v[0] + 1]));
    p2 = p_line(get_line(start, fin), get_line(p[v[1]], p[v[1] + 1]));
    /*p1.write();
    cout << endl;
    p2.write();
    cout << endl;*/
    double ans = dist(start, p1) + 2 * dist(p1, p2) + dist(p2, fin);
    ans = min(ans, dist(start, p2) + 2 * dist(p2, p1) + dist(p1, fin));
    for (int i = 0; i < v.size(); ++i) {
        //cout << v[i] << endl;
    }
    int n1 = v[0], n2 = v[1];
    if (n1 > n2) {
        swap(n1, n2);
    }
    double d1 = dist(start, p1) + dist(fin, p2) + dist(p1, p[n1 + 1]) + dist(p2, p[n2]);
    for (int i = n1 + 1; i < n2; ++i) {
        d1 += dist(p[i], p[i + 1]);
    }
    //cout << d1 << endl;
    ans = min(ans, d1);

    d1 = dist(fin, p1) + dist(start, p2) + dist(p1, p[n1 + 1]) + dist(p2, p[n2]);
    for (int i = n1 + 1; i < n2; ++i) {
        d1 += dist(p[i], p[i + 1]);
    }
    //cout << d1 << endl;
    ans = min(ans, d1);



    d1 = dist(start, p1) + dist(fin, p2) + dist(p1, p[n1]) + dist(p2, p[n2 + 1]);
    for (int i = n1; i > 0; --i) {
        d1 += dist(p[i], p[i - 1]);
    }
    for (int i = n2 + 1; i < n; ++i) {
        d1 += dist(p[i], p[i + 1]);
    }
    //cout << d1 << endl;
    ans = min(ans, d1);

    d1 = dist(fin, p1) + dist(start, p2) + dist(p1, p[n1]) + dist(p2, p[n2 + 1]);
    for (int i = n1; i > 0; --i) {
        d1 += dist(p[i], p[i - 1]);
    }
    for (int i = n2 + 1; i < n; ++i) {
        d1 += dist(p[i], p[i + 1]);
    }
    //cout << d1 << endl;
    ans = min(ans, d1);

    printf("%.10f\n", ans);
    return 0;
}