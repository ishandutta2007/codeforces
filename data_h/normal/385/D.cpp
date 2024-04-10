#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

const int N = 20;
const double eps = 1e-8;
const double PI = acos(-1.0);

double reach[1 << N];
int n;
double ax[N], ay[N], angle[N];
double source, target;

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
	Point() {}
	
	friend inline Point operator +(Point a, Point b) {
		return Point(a.x + b.x, a.y + b.y);
	}

	friend inline Point operator -(Point a, Point b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	
	friend inline Point operator *(Point a, double b) {
		return Point(a.x * b, a.y * b);
	}
	
	friend inline Point operator /(Point a, double b) {
		return Point(a.x / b, a.y / b);
	}

}points[N];

double det(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

double dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

Point intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
	double s1 = det(b - a, c - a);
	double s2 = det(b - a, d - a);
	return (d * s1 - c * s2) / (s1 - s2);
}

Point rotate(Point a, double b) {
	b /= 180.0;
	b *= PI;
	return Point(a.x * cos(b) - a.y * sin(b), a.x * sin(b) + a.y * cos(b));
}

int main() {

	scanf("%d %lf %lf", &n, &source, &target);
	for(int i = 0; i < n; i++) {
		scanf("%lf %lf %lf", &points[i].x, &points[i].y, &angle[i]);
	}	
	
	for(int i = 0; i < (1 << n); i++) {
		reach[i] = source;
	}
	
	double ans = source;
	
	for(int i = 0; i < (1 << n); i++) {
		reach[i] = min(reach[i], target);
		ans = max(ans, reach[i]);
		for(int j = 0; j < n; j++)
			if (~i >> j & 1) {
				Point t = rotate(Point(reach[i], 0) - points[j], angle[j]);
				if (t.y > -eps) {
					reach[i | (1 << j)] = target;
					continue;
				} else {
					Point cr = intersect(points[j], points[j] + t, Point(0.0, 0.0), Point(1.0, 0.0));
					reach[i | (1 << j)] = max(reach[i | (1 << j)], cr.x);
				}
			}
	}
	
	printf("%.8lf\n", ans - source);
	return 0;
}