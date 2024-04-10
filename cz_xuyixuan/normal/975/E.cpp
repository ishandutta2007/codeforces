#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const long double pi = acosl(-1);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct point {ld x, y; };
struct line {point a, b; ld alpha; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, ld b) {return (point) {a.x * b, a.y * b}; }
ld operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
point a[MAXN]; int n, m, p, q;
point pos, mass; ld area;
ld PolarAngle(point a) {
	return atan2(a.y, a.x);
}
ld dist(point a) {
	return sqrtl(a.x * a.x + a.y * a.y);
}
point query(int x) {
	ld angle = 1.5 * pi + PolarAngle(a[x] - a[p]) - PolarAngle(mass - a[p]);
	return pos + (point) {cos(angle), sin(angle)} * dist(a[x] - a[p]);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	a[0] = a[n];
	for (int i = 1; i <= n; i++) {
		area += a[i - 1] * a[i];
		if (i >= 3) mass = mass + (a[i] + a[i - 1] + a[1]) * (1.0 / 3.0) * (a[1] * a[i - 1] + a[i - 1] * a[i] + a[i] * a[1]);
	}
	mass = mass * (1.0 / area);
	p = 1, q = 2; bool flg = false;
	for (int i = 1; i <= m; i++) {
		int opt; read(opt);
		if (opt == 1) {
			int x, y; read(x), read(y);
			if (flg == false) {
				if (x == 1) pos = a[2], swap(p, q);
				else pos = a[1];
				flg = true;
			}
			if (x == q) q = y;
			else {
				pos = query(q);
				swap(p, q);
				q = y;
			}
		} else {
			int x; read(x);
			if (flg == false) printf("%.10Lf %.10Lf\n", a[x].x, a[x].y);
			else {
				point tmp = query(x);
				printf("%.10Lf %.10Lf\n", tmp.x, tmp.y);
			}
		}
	}
	return 0;
}