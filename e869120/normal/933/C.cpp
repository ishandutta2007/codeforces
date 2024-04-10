#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

const long double EPS = 1e-10;

class Point {
public:
	long double px, py;
	Point() : px(0), py(0) {};
	Point(long double px_, long double py_) : px(px_), py(py_) {};
	bool operator==(const Point& p) const { return fabs(px - p.px) < EPS && fabs(py - p.py) < EPS; }
	bool operator!=(const Point& p) const { return fabs(px - p.px) >= EPS || fabs(py - p.py) >= EPS; }
	bool operator<(const Point& p) const { return p.px - px >= EPS ? true : (fabs(px - p.px) < EPS && p.py - py >= EPS); }
	bool operator>(const Point& p) const { return px - p.px >= EPS ? true : (fabs(px - p.px) < EPS && py - p.py >= EPS); }
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
vector<Point> crp(Circle c1, Circle c2) {
	long double d = abs(c1.p - c2.p); if (c1.r + c2.r + EPS <= d || abs(c2.r - c1.r) - EPS > d) return vector<Point>{};
	long double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	long double t = arg(c2.p - c1.p);
	return{ c1.p + pol(c1.r, t + a), c1.p + pol(c1.r, t - a) };
}

Circle C[3];
int V = 0, E = 0; vector<Point>vec2;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> C[i].p.px >> C[i].p.py >> C[i].r;
	for (int i = 0; i < n; i++) {
		vector<Point>vec;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			vector<Point> G = crp(C[i], C[j]);
			for (int k = 0; k < G.size(); k++) { vec.push_back(G[k]); vec2.push_back(G[k]); }
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		E += max(1, (int)vec.size());
	}
	sort(vec2.begin(), vec2.end());
	vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
	V += max(1, (int)vec2.size());

	cout << E - V + 2 << endl;
	return 0;
}