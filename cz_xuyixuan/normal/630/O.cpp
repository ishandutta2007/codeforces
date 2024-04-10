#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
struct point {double x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator * (point a, double b) {return (point) {a.x * b, a.y * b}; }
double len(point x) {
	return sqrt(x.x * x.x + x.y * x.y);
}
void print(point x) {
	printf("%.10lf %.10lf\n", x.x, x.y);
}
int main() {
	ios::sync_with_stdio(false);
	point p, v;
	cin >> p.x >> p.y >> v.x >> v.y;
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	print(p + v * (b / len(v)));
	point u = v * (-1);
	point l = (point) {-v.y, v.x};
	point r = l * (-1);
	point tmp = p;
	print(tmp = tmp + l * (a / 2 / len(l)));
	print(tmp = tmp + r * ((a - c) / 2 / len(r)));
	print(tmp = tmp + u * (d / len(u)));
	print(tmp = tmp + r * (c / len(r)));
	print(tmp = tmp + v * (d / len(v)));
	print(tmp = tmp + r * ((a - c) / 2 / len(r)));
	return 0;
}