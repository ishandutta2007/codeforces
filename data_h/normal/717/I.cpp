#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
double eps(1e-10);
int sign(const double & x) {
	return (x > eps) - (x + eps < 0);
}
bool equal(const double & x, const double & y) {
	return x + eps > y && y + eps > x;
}
struct Point {
	double x, y, z;
	Point() {
	}
	Point(const double & x, const double & y, const double & z) : x(x), y(y), z(z) {
	}
	void print() const {
		printf("%f %f %f\n", x, y, z);
	}
	void scan() {
		scanf("%lf%lf%lf", &x, &y, &z);
	}
	double sqrlen() const {
		return x * x + y * y + z * z;
	}
	double len() const {
		return sqrt(max(0., sqrlen()));
	}
	bool operator < (const Point & b) const {
		if(!equal(x, b.x)) {
			return x < b.x;
		}
		if(!equal(y, b.y)) {
			return y < b.y;
		}
		if(!equal(z, b.z)) {
			return z < b.z;
		}
		return false;
	}
	double dirlen() const {
		return len() * ((*this) < Point(0, 0, 0) ? -1 : 1);
	}
	Point operator + (const Point & b) const {
		return Point(x + b.x, y + b.y, z + b.z);
	}
	Point operator - (const Point & b) const {
		return Point(x - b.x, y - b.y, z - b.z);
	}
	double operator % (const Point & b) const {
		return x * b.x + y * b.y + z * b.z;
	}
	Point operator * (const Point & b) const {
		return Point(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
	}
	Point zoom(const double & l) const {
		double lambda(l / len());
		return Point(lambda * x, lambda * y, lambda * z);
	}
};
inline Point operator * (const double & x, const Point & a) {
	return Point(x * a.x, x * a.y, x * a.z);
}
struct Plane {
	Point o, norm;
};
struct Line {
	Point s, d;
	Line(const Point & s, const Point & d) : s(s), d(d) {
	}
};
Point intersection(const Line & a, const Line & b) {
	double lambda(((b.s - a.s) * b.d).dirlen() / (a.d * b.d).dirlen());
	return a.s + lambda * a.d;
}
vector<pair<Point, pair<int, int> > > evts;
void calc(const vector<Point> & points, const vector<Point> & q) {
	Plane p1, p2;
	p1.o = points[0];
	p2.o = q[0];
	p1.norm = (points[0] - points[1]) * (points[2] - points[0]);
	p2.norm = (q[0] - q[1]) * (q[2] - q[0]);
	p1.norm = p1.norm.zoom(1);
	p2.norm = p2.norm.zoom(1);
	if(sign((p1.norm * p2.norm).len()) == 0) {
		return;
	}
	Point d(p1.norm * p2.norm);
	Point g(d * p1.norm);
	d = d.zoom(1);
	g = g.zoom(1);
	//g.print();
	Line l(p1.o + (p2.o - p1.o) % p2.norm / (g % p2.norm) * g, d);
	//l.s.print();
	//l.d.print();
	static vector<pair<Point, pair<int, int> > > vec;
	vec.clear();
	for(int i(0); i < (int)points.size(); i++) {
		Point a(points[i]), b(points[(i + 1) % (int)points.size()]);
		int da(sign((a - l.s) % g)), db(sign((b - l.s) % g));
		if(da == db) {
			
		}else {
			Point crs(intersection(Line(a, b - a), l));
			if(da != 0 && db != 0) {
				evts.push_back(make_pair(crs, make_pair(da, 0)));
			}else {
				vec.push_back(make_pair(crs, make_pair(da, db)));
			}
		}
	}
	for(int i(0); i < (int)vec.size(); i++) {
		if(vec[i].second.second == 0) {
			if(vec[i].second.first != vec[(i + 1) % (int)vec.size()].second.second) {
				evts.push_back(make_pair(vec[i].first, make_pair(vec[i].second.first, 0)));
			}
		}
	}

}
vector<Point> vec[2];
int main() {
	for(int d(0); d < 2; d++) {
		int n;
		scanf("%d", &n);
		for(int i(0); i < n; i++) {
			Point p;
			p.scan();
			vec[d].push_back(p);
		}
	}
	calc(vec[0], vec[1]);
	for(auto& evt : evts) {
		evt.second.second = 1;
	}
	calc(vec[1], vec[0]);
	sort(evts.begin(), evts.end());
	int ans(0);
	int cur(0);
	for(auto evt : evts) {
		if(evt.second.second == 1) {
			cur += evt.second.first;
		}else {
			if(cur != 0) {
				ans += evt.second.first;
			}
		}
	}
	printf("%s\n", ans != 0 ? "YES" : "NO");
}