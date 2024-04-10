#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
const double eps = 1e-12;
const double bound = 1e6;
const double pi = acos(-1);
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
struct info {point pos; double alpha; };
struct line {point a, b; double alpha; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, double b) {return (point) {a.x * b, a.y * b}; }
double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
double operator / (point a, point b) {
	if (abs(b.x) > eps) return a.x / b.x;
	else return a.y / b.y;
}
double moo(point a) {return sqrt(a.x * a.x + a.y * a.y); }
point unit(point a) {return a * (1.0 / moo(a)); }
double dist(point a, point b) {return moo(b - a); }
bool equal(double x, double y) {return fabs(x - y) <= eps; }
bool parallel(line x, line y) {return equal((x.b - x.a) * (y.b - y.a), 0); }
double PolarAngle(point a) {return atan2(a.y, a.x); }
int n, m, tot;
point p[MAXN];
line a[MAXN], q[MAXN];
point intersect(const line &x, const line &y) {
	double tmp = (y.a - x.a) * (y.b - x.a);
	double tnp = (y.b - x.b) * (y.a - x.b);
	return (x.a * tnp + x.b * tmp) * (1 / (tmp + tnp));
}
bool onright(const line &l, const point &p) {
	if ((p - l.a) * (l.b - l.a) > -eps) return true;
	else return false;
}
bool onrightcmp(const line &l, const point &p) {
	if ((p - l.a) * (l.b - l.a) > eps) return true;
	else return false;
}
bool cmp(const line &a, const line &b) {
	if (fabs(a.alpha - b.alpha) > eps) return a.alpha < b.alpha;
	else return onrightcmp(a, b.a);
}
void HalfPlane(int n) {
	sort(a + 1, a + n + 1, cmp);
	int l = 0, r = -1;
	for (int i = 1; i <= n; i++) {
		while (l < r && onright(a[i], p[r])) r--;
		while (l < r && onright(a[i], p[l + 1])) l++;
		if (fabs(a[i].alpha - q[r].alpha) <= eps) continue;
		if (a[i].alpha - q[r].alpha >= pi - eps) {
			printf("%.10lf\n", 0.0);
			return;
		}
		q[++r] = a[i];
		if (l < r) p[r] = intersect(q[r], q[r - 1]);
	}
	while (l < r && onright(q[l], p[r])) r--;
	while (l < r && onright(q[r], p[l + 1])) l++;
	if (r - l <= 1) printf("%.10lf\n", 0.0);
	else {
		p[l] = intersect(q[l], q[r]);
		double ans = 0;
		for (int i = l; i <= r; i++) {
			int j = i + 1;
			if (i == r) j = l;
			ans += p[i] * p[j];
		}
		printf("%.10lf\n", abs(ans)  / 2);
	}
}
info b[MAXN];
bool cnp(info a, info b) {
	return a.alpha < b.alpha;
}
int main() {
	read(tot);
	while (tot--) {
		read(n), m = 0;
		point ld = (point) {-bound, -bound};
		point rd = (point) {bound, -bound};
		point ru = (point) {bound, bound};
		point lu = (point) {-bound, bound};
		a[++m] = (line) {ld, rd, PolarAngle(rd - ld)};
		a[++m] = (line) {rd, ru, PolarAngle(ru - rd)};
		a[++m] = (line) {ru, lu, PolarAngle(lu - ru)};
		a[++m] = (line) {lu, ld, PolarAngle(ld - lu)};
		for (int i = 1; i <= n; i++){
			read(b[i].pos.x), read(b[i].pos.y);
			b[i].alpha = PolarAngle(b[i].pos - b[1].pos);
		}
		sort(b + 2, b + n + 1, cnp);
		for (int i = 2; i <= n; i++) {
			b[i + n - 1] = b[i];
			b[i + n - 1].alpha += 2 * pi;
		}
		bool flg = false;
		for (int i = 2, j = 2; i <= n; i++) {
			chkmax(j, i);
			while (b[j + 1].alpha - b[i].alpha < pi + eps) j++;
			if (equal(b[i + 1].alpha - b[i].alpha, 0) || equal(b[j].alpha - b[i].alpha, pi)) {
				printf("%.10lf\n", 0.0);
				flg = true;
				break;
			}
			if (j != i) a[++m] = (line) {b[i].pos, b[j].pos, PolarAngle(b[j].pos - b[i].pos)};
			if (b[i + 1].alpha - b[i].alpha < pi - eps) a[++m] = (line) {b[i].pos, b[i + 1].pos, PolarAngle(b[i + 1].pos - b[i].pos)};
		}
		if (flg) continue;
		HalfPlane(m);
	}
	return 0;
}