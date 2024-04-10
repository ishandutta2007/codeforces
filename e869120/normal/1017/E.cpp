#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

// ------ Classes ------ //
class Point {
public:
	long double px, py;
	Point() : px(0), py(0) {};
	Point(long double px_, long double py_) : px(px_), py(py_) {};
	bool operator==(const Point& p) const { return px == p.px && py == p.py; }
	bool operator!=(const Point& p) const { return px != p.px || py != p.py; }
	bool operator<(const Point& p) const { return px < p.px ? true : (px == p.px && py < p.py); }
	bool operator>(const Point& p) const { return px > p.px ? true : (px == p.px && py > p.py); }
	bool operator<=(const Point& p) const { return !(Point(px, py) > p); }
	bool operator>=(const Point& p) const { return !(Point(px, py) < p); }
	Point operator+(const Point& p) const { return Point(px + p.px, py + p.py); }
	Point operator-(const Point& p) const { return Point(px - p.px, py - p.py); }
	Point operator/(long double d) const { return Point(px / d, py / d); }
	friend Point operator*(const Point p, long double d) { return Point(p.px * d, p.py * d); }
	friend Point operator*(long double d, const Point& p) { return p * d; }
	Point& operator+=(const Point& p1) { px += p1.px, py += p1.py; return *this; }
	Point& operator-=(const Point& p1) { px -= p1.px, py -= p1.py; return *this; }
	Point& operator*=(long double d) { px *= d, py *= d; return *this; }
	Point& operator/=(long double d) { px /= d, py /= d; return *this; }
};
class Segment {
public:
	Point p1, p2;
	Segment() : p1(Point()), p2(Point()) {};
	Segment(Point p1_, Point p2_) : p1(p1_), p2(p2_) {};
	Segment(long double p1x, long double p1y, long double p2x, long double p2y) : p1(Point(p1x, p1y)), p2(Point(p2x, p2y)) {};
	bool operator==(const Segment& s) const { return (p1 == s.p1 && p2 == s.p2) || (p1 == s.p2 && p2 == s.p1); }
	bool operator!=(const Segment& s) const { return !(Segment(p1, p2) == s); }
};
class Line {
public:
	Point p1, p2;
	Line() : p1(Point()), p2(Point()) {};
	Line(Point p1_, Point p2_) : p1(p1_), p2(p2_) {};
	Line(long double p1x, long double p1y, long double p2x, long double p2y) : p1(Point(p1x, p1y)), p2(Point(p2x, p2y)) {};
	bool operator==(const Line& s) const { return (p1 == s.p1 && p2 == s.p2) || (p1 == s.p2 && p2 == s.p1); }
	bool operator!=(const Line& s) const { return !(Line(p1, p2) == s); }
};
class Circle {
public:
	Point p; long double r;
	Circle() : p(Point()), r(0.0L) {};
	Circle(Point p_) : p(p_), r(0.0L) {};
	Circle(Point p_, long double r_) : p(p_), r(r_) {};
	Circle(long double x_, long double y_) : p(Point(x_, y_)), r(0.0L) {};
	Circle(long double x_, long double y_, long double r_) : p(Point(x_, y_)), r(r_) {};
	bool operator==(const Circle& c) const { return p == c.p && r == c.r; }
	bool operator!=(const Circle& c) const { return !(Circle(p, r) == c); }
};

// ------ Functions ------ //
long double norm(const Point& a) { return a.px * a.px + a.py * a.py; }
long double abs(const Point& a) { return sqrtl(norm(a)); }
long double arg(const Point& a) { return atan2l(a.py, a.px); }
long double dot(const Point& a, const Point& b) { return a.px * b.px + a.py * b.py; }
long double crs(const Point& a, const Point& b) { return a.px * b.py - a.py * b.px; }
Point pol(long double r, long double d) { return Point(cosl(d) * r, sinl(d) * r); }
Point prj(const Segment& a, const Point& b) { return a.p1 + (a.p2 - a.p1) * dot(b - a.p1, a.p2 - a.p1) / norm(a.p2 - a.p1); }
Point prj(const Line& a, const Point& b) { return a.p1 + (a.p2 - a.p1) * dot(b - a.p1, a.p2 - a.p1) / norm(a.p2 - a.p1); }
Point rfl(const Segment& a, const Point& b) { return b + (prj(a, b) - b) * 2.0L; }
Point rfl(const Line& a, const Point& b) { return b + (prj(a, b) - b) * 2.0L; }
int ccw(const Point& p0, const Point& p1, const Point& p2) {
	Point a = p1 - p0, b = p2 - p0;
	if (crs(a, b) > 1e-10) return 1;
	if (crs(a, b) < -1e-10) return -1;
	if (dot(a, b) < -1e-10) return 2;
	if (norm(a) < norm(b)) return -2;
	return 0;
}
bool its(const Point& p1, const Point& p2, const Point& p3, const Point& p4) { return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0); }
bool its(const Segment& s1, const Segment& s2) { return its(s1.p1, s1.p2, s2.p1, s2.p2); }
long double dst(const Point& a, const Point& b) { return abs(b - a); }
long double dst(const Line& a, const Point& b) { return abs(crs(a.p2 - a.p1, b - a.p1) / abs(a.p2 - a.p1)); }
long double dst(const Segment& a, const Point& b) { return dot(a.p2 - a.p1, b - a.p1) < 0.0 ? abs(b - a.p1) : (dot(a.p1 - a.p2, b - a.p2) < 0.0 ? abs(b - a.p2) : abs(crs(a.p2 - a.p1, b - a.p1) / abs(a.p2 - a.p1))); }
long double dst(const Segment& a, const Segment& b) { return its(a, b) ? 0 : min({ dst(a, b.p1), dst(a, b.p2), dst(b, a.p1), dst(b, a.p2) }); }
Point crp(Line a, Line b) {
	Point c = b.p2 - b.p1;
	long double d1 = abs(crs(c, a.p1 - b.p1));
	long double d2 = abs(crs(c, a.p2 - b.p1));
	return a.p1 + (a.p2 - a.p1) * (d1 / (d1 + d2));
}
Point crp(Segment a, Segment b) {
	Point c = b.p2 - b.p1;
	long double d1 = abs(crs(c, a.p1 - b.p1));
	long double d2 = abs(crs(c, a.p2 - b.p1));
	return a.p1 + (a.p2 - a.p1) * (d1 / (d1 + d2));
}
pair<Point, Point> crp(Circle c, Line l) {
	Point p1 = prj(l, c.p);
	Point p2 = (l.p2 - l.p1) / abs(l.p2 - l.p1);
	double base = sqrt(c.r * c.r - norm(p1 - c.p));
	return make_pair(p1 + p2 * base, p1 - p2 * base);
}
vector<Point> crp(Circle c1, Circle c2) {
	long double d = abs(c1.p - c2.p);
	long double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	long double t = arg(c2.p - c1.p);
	return{ c1.p + pol(c1.r, t + a), c1.p + pol(c1.r, t - a) };
}
long double area(vector<Point> v) {
	long double ret = 0.0L;
	for (int i = 0; i < v.size(); i++) ret += crs(v[i], v[(i + 1) % v.size()]);
	return ret / 2;
}
bool is_convex(vector<Point> v) {
	if (v.size() < 3) return false;
	int s = -3;
	for (int i = 0; i < v.size(); i++) {
		int r = ccw(v[i], v[(i + v.size() - 1) % v.size()], v[(i + 1) % v.size()]);
		if (abs(r) == 1 && s == -3) s = r;
		if (s * r == -1) return false;
	}
	return true;
}
int contain(vector<Point> v, Point p) {
	bool in = false;
	for (int i = 0; i < v.size(); ++i) {
		Point a = v[i] - p, b = v[(i + 1) % v.size()] - p;
		if (a.py > b.py) swap(a, b);
		if (a.py <= 0 && 0 < b.py)
			if (crs(a, b) < 0) in = !in;
		if (crs(a, b) == 0 && dot(a, b) <= 0) return 1;
	}
	return in ? 2 : 0;
}
vector<Point> convex_hull(vector<Point> v) {
	if (v.size() < 3) return v;
	sort(v.begin(), v.end());
	vector<Point> u = { v[0], v[1] }, l = { v[v.size() - 1], v[v.size() - 2] };
	for (int i = 2; i < v.size(); i++) {
		for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], v[i]) >= 0; n--) u.pop_back();
		u.push_back(v[i]);
	}
	for (int i = v.size() - 3; i >= 0; i--) {
		for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], v[i]) >= 0; n--) l.pop_back();
		l.push_back(v[i]);
	}
	reverse(l.begin(), l.end());
	for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);

	vector<Point>ll;
	for (int i = 0; i < l.size(); i++) {
		Point A = l[(i + l.size() - 1) % l.size()], B = l[i], C = l[(i + 1) % l.size()];
		if (fabs(crs(A - B, C - B)) > 1e-10) ll.push_back(l[i]);
	}
	if (ll.size() == 0) {
		sort(l.begin(), l.end());
		ll.push_back(l[0]);
		ll.push_back(l[l.size() - 1]);
	}
	return ll;
}

int N, M; Point V1[100009], V2[100009]; long double power[100009];

int main() {
	scanf("%d%d", &N, &M); if (N == 1 && M == 1) { cout << "YES" << endl; return 0; }
	for (int i = 0; i < N; i++) scanf("%Lf%Lf", &V1[i].px, &V1[i].py);
	for (int i = 0; i < M; i++) scanf("%Lf%Lf", &V2[i].px, &V2[i].py);
	vector<Point>L1; for (int i = 0; i < N; i++) L1.push_back(V1[i]); L1 = convex_hull(L1);
	vector<Point>L2; for (int i = 0; i < M; i++) L2.push_back(V2[i]); L2 = convex_hull(L2);

	long double sx = 0, sy = 0; for (int i = 0; i < L1.size(); i++) { sx += L1[i].px; sy += L1[i].py; } sx /= L1.size(); sy /= L1.size();
	long double tx = 0, ty = 0; for (int i = 0; i < L2.size(); i++) { tx += L2[i].px; ty += L2[i].py; } tx /= L2.size(); ty /= L2.size();

	vector<long double>G1, G2;
	for (int i = 0; i < L1.size(); i++) G1.push_back(dst(L1[i], Point{ sx, sy }));
	for (int i = 0; i < L2.size(); i++) G2.push_back(dst(L2[i], Point{ tx, ty }));

	long double CONSTANT = 1.0000869120;
	power[0] = 1; for (int i = 1; i <= 100000; i++) power[i] = power[i - 1] * CONSTANT;
	long double S1 = 0; for (int i = 0; i < L1.size(); i++) { S1 += power[i] * G1[i]; }
	long double S2 = 0; for (int i = 0; i < L2.size(); i++) { S2 += power[i] * G2[i]; }

	bool flag = false;
	for (int i = 0; i < L2.size(); i++) {
		if (abs(S1 - S2) < 1e-12 || abs(S1 - S2) / (S1 + S2) < 1e-15) { cout << "YES" << endl; flag = true; break; }
		S2 -= power[L2.size() - 1] * G2[L2.size() - 1 - i];
		S2 *= CONSTANT;
		S2 += G2[L2.size() - 1 - i];
	}
	if (flag == false) cout << "NO" << endl;
	return 0;
}