#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
#define PI	acos(-1)
struct point {double x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, double b) {return (point) {a.x * b, a.y * b}; }
double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
double len(point x) {
	return sqrt(x.x * x.x + x.y * x.y);
}
point intersect(point a, point b, point c, point d) {
	double u = (a - c) * (a - d), v = (b - d) * (b - c);
	return (a * v + b * u) * (1 / (u + v));
}
point rotate(point a, double alpha) {
	return (point) {a.x * cos(alpha) - a.y * sin(alpha), a.x * sin(alpha) + a.y * cos(alpha)};
}
point get(double n, double x, point a) {
	return rotate(a, 2 * PI / n * x);
}
int main() {
	double n, r;
	cin >> n >> r;
	point o = (point) {0, 0};
	point a = (point) {0, r};
	point b = intersect(a, get(n, (n - 1) / 2, a), get(n, 1, a), get(n, 1 + (n + 1) / 2, a));
	point c = intersect(a, get(n, (n + 1) / 2, a), get(n, n - 1, a), get(n, n - 1 - (n + 1) / 2, a));
	double s = 0;
	s += fabs((b - a) * (c - a)) / 2;
	s += fabs((b - o) * (c - o)) / 2;
	printf("%.10lf\n", s * n);
	return 0;
}