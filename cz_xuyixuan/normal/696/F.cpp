#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const double eps = 1e-10;
const double pi = acos(-1);
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct point {double x, y; };
struct line {point a, b; double alpha; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, double b) {return (point) {a.x * b, a.y * b}; }
double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
double moo(point a) {return sqrt(a.x * a.x + a.y * a.y); }
double PolarAngle(point a) {return atan2(a.y, a.x); }
point unit(point a) {return a * (1.0 / moo(a)); }
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
bool HalfPlane(int n, line *a, point &res) {
	static point p[MAXN];
	static line  q[MAXN];
	sort(a + 1, a + n + 1, cmp);
	int l = 0, r = -1;
	for (int i = 1; i <= n; i++) {
		while (l < r && onright(a[i], p[r])) r--;
		while (l < r && onright(a[i], p[l + 1])) l++;
		if (fabs(a[i].alpha - q[r].alpha) <= eps) continue;
		if (a[i].alpha - q[r].alpha >= pi - eps) return false;
		q[++r] = a[i];
		if (l < r) p[r] = intersect(q[r], q[r - 1]);
	}
	while (l < r && onright(q[l], p[r])) r--;
	while (l < r && onright(q[r], p[l + 1])) l++;
	if (r - l <= 1) return false;
	res = intersect(q[l], q[r]);
	return true;
}
int n; point a[MAXN]; line b[MAXN]; point vec[MAXN]; double p[MAXN];
bool check(int l, int r, double d, point &res) {
	static line c[MAXN]; int tot = 0;
	for (int i = 1; i <= n; i++)
		c[++tot] = b[i];
	for (int i = l; i <= r; i++)
		c[++tot] = (line) {a[i + 1] + vec[i] * d, a[i] + vec[i] * d, p[i]};
	return HalfPlane(tot, c, res);
}
bool check(double mid) {
	static int nxt[MAXN]; int pos = 1; point tmp;
	for (int i = 1; i <= 2 * n; i++) {
		while (pos < 2 * n && check(i, pos + 1, mid, tmp)) pos++;
		nxt[i] = pos;
	}
	nxt[2 * n + 1] = 2 * n + 1;
	for (int i = 1; i <= 2 * n; i++)
		if (nxt[nxt[i] + 1] >= i + n - 1) return true;
	return false;
}
void getans(double mid) {
	static int nxt[MAXN]; int pos = 1;
	static point ans[MAXN]; point tmp;
	for (int i = 1; i <= 2 * n; i++) {
		while (pos < 2 * n && check(i, pos + 1, mid, tmp)) pos++;
		nxt[i] = pos; assert(check(i, pos, mid, ans[i]));
	}
	nxt[2 * n + 1] = 2 * n + 1;
	for (int i = 1; i <= 2 * n; i++)
		if (nxt[nxt[i] + 1] >= i + n - 1) {
			printf("%.10lf %.10lf\n", ans[i].x, ans[i].y);
			printf("%.10lf %.10lf\n", ans[nxt[i] + 1].x, ans[nxt[i] + 1].y);
			return;
		}
	assert(false);
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].x), read(a[i].y);
		a[i + n] = a[i];
	}
	a[n * 2 + 1] = a[1];
	for (int i = 1; i <= 2 * n; i++) {
		b[i] = (line) {a[i], a[i + 1], PolarAngle(a[i + 1] - a[i])};
		vec[i] = a[i + 1] - a[i];
		swap(vec[i].x, vec[i].y), vec[i].x *= -1;
		vec[i] = vec[i] * (1 / moo(vec[i]));
		p[i] = PolarAngle(a[i] - a[i + 1]);
	}
	double l = 0, r = 1e5;
	while (l + eps < r) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.10lf\n", r);
	getans(r);
	return 0;
}