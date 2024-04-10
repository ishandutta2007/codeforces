#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 2e5 + 5;
const double eps = 1e-7;
const double pps = 1e-4;
const double INF = 1e99;
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
struct point {double x, y; };
struct line {point a, b; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, double b) {return (point) {a.x * b, a.y * b}; }
double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
double moo(point a) {return sqrt(a.x * a.x + a.y * a.y); }
point unit(point a) {return a * (1.0 / moo(a)); }
double dist(point a, point b) {return moo(b - a); }
bool equal(double x, double y) {return fabs(x - y) <= eps; }
bool parallel(line x, line y) {return equal((x.b - x.a) * (y.b - y.a), 0); }
double PolarAngle(point a) {return atan2(a.y, a.x); }
point intersect(const line &x, const line &y) {
	double tmp = (y.a - x.a) * (y.b - x.a);
	double tnp = (y.b - x.b) * (y.a - x.b);
	return (x.a * tnp + x.b * tmp) * (1 / (tmp + tnp));
}
bool online(const line &x, const point &y) {
	return equal((y - x.a) * (y - x.b), 0);
}
bool operator < (point a, point b) {
	if (equal(a.x, b.x)) return a.y < b.y;
	else return a.x < b.x;
}
bool operator > (point a, point b) {
	if (equal(a.x, b.x)) return a.y > b.y;
	else return a.x > b.x;
}
int n; double w, h, t[MAXN];
point s, pos[MAXN]; line a[MAXN];
void extend(line &ans, line a, point x, point y) {
	line tmp = (line) {min(x, y), max(x, y)};
	if (parallel(tmp, a)) {
		if (online(a, x)) {
			chkmin(ans.a, x);
			chkmax(ans.b, x);
			chkmin(ans.a, y);
			chkmax(ans.b, y);
		}
		return;
	}
	point pos = intersect(a, tmp);
	if (pos < tmp.a || pos > tmp.b) return;
	chkmin(ans.a, pos);
	chkmax(ans.b, pos);
}
void shrinka(line &ans, line a, point x, point y) {
	line tmp = (line) {min(x, y), max(x, y)};
	if (parallel(tmp, a)) return;
	point pos = intersect(a, tmp);
	if (pos < tmp.a || pos > tmp.b) return;
	chkmax(ans.a, pos);
}
void shrinkb(line &ans, line a, point x, point y) {
	line tmp = (line) {min(x, y), max(x, y)};
	if (parallel(tmp, a)) return;
	point pos = intersect(a, tmp);
	if (pos < tmp.a || pos > tmp.b) return;
	chkmin(ans.b, pos);
}
bool valid(double speed) {
	line now = (line) {s, s};
	for (int i = 1; i <= n; i++) {
		double delta = (t[i] - t[i - 1]) * speed;
		line ans = (line) {(point) {INF, INF}, (point) {-INF, -INF}};
		point x[4] = {now.a, now.a, now.a, now.a};
		point y[4] = {now.b, now.b, now.b, now.b};
		x[0].x -= delta, x[0].y -= delta;
		x[1].x -= delta, x[1].y += delta;
		x[2].x += delta, x[2].y += delta;
		x[3].x += delta, x[3].y -= delta;
		y[0].x -= delta, y[0].y -= delta;
		y[1].x -= delta, y[1].y += delta;
		y[2].x += delta, y[2].y += delta;
		y[3].x += delta, y[3].y -= delta;
		extend(ans, a[i], x[0], x[1]);
		extend(ans, a[i], x[1], x[2]);
		extend(ans, a[i], x[2], x[3]);
		extend(ans, a[i], x[3], x[0]);
		extend(ans, a[i], y[0], y[1]);
		extend(ans, a[i], y[1], y[2]);
		extend(ans, a[i], y[2], y[3]);
		extend(ans, a[i], y[3], y[0]);
		extend(ans, a[i], x[0], y[0]);
		extend(ans, a[i], x[1], y[1]);
		extend(ans, a[i], x[2], y[2]);
		extend(ans, a[i], x[3], y[3]);
		shrinka(ans, a[i], (point) {0, 0}, (point) {0, w});
		if (a[i].a.y < a[i].b.y) shrinka(ans, a[i], (point) {0, 0}, (point) {w, 0});
		else shrinkb(ans, a[i], (point) {0, 0}, (point) {w, 0});
		if (a[i].a.y > a[i].b.y) shrinka(ans, a[i], (point) {w, w}, (point) {0, w});
		else shrinkb(ans, a[i], (point) {w, w}, (point) {0, w});
		shrinkb(ans, a[i], (point) {w, w}, (point) {w, 0});
		if (ans.b < ans.a) return false;
		now = ans;
	}
	return true;
}
double calc(double x, point mid) {
	double ans = mid.x;
	ans += (mid.x - x) / mid.y * (h - mid.y);
	return ans;
}
int main() {
	read(n), read(w), read(h);
	read(s.x), read(s.y);
	for (int i = 1; i <= n; i++) {
		read(t[i]), read(pos[i].x), read(pos[i].y);
		a[i].a = (point) {0, calc(0, pos[i])};
		a[i].b = (point) {w, calc(w, pos[i])};
		if (a[i].a > a[i].b) swap(a[i].a, a[i].b);
	}
	double l = 0, r = 2 * w;
	while (l + pps < r) {
		double mid = (l + r) / 2;
		if (valid(mid)) r = mid;
		else l = mid;
	}
	double ans = (l + r) / 2;
	if (ans > w + eps) printf("-1\n");
	else printf("%.10lf\n", ans);
	return 0;
}