#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const double eps = 1e-8;
const double INF = 1e99;
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
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, int b) {return (point) {a.x * b, a.y * b}; }
double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
double dot(point a, point b) {return a.x * b.x + a.y * b.y; }
double dist(point a, point b) {
	a = a - b;
	return sqrt(a.x * a.x + a.y * a.y);
}
bool onseg(point a, point b, point c) {
	return fabs(dist(a, b) - dist(a, c) - dist(b, c)) <= eps;
}
int n, m, top;
point p, a[MAXN], b[MAXN], c[MAXN];
vector <pair <int, int>> e;
bool cmp(point a, point b) {
	if ((a - p) * (b - p) == 0) return dist(a, p) < dist(b, p);
	else return (a - p) * (b - p) > 0;
}
void convexHull() {
	for (int i = 1; i <= n; i++)
		if (a[i].y < a[1].y || (a[i].y == a[1].y && a[i].x < a[1].x)) swap(a[i], a[1]);
	p = c[top = 1] = a[1];
	sort(a + 2, a + n + 1, cmp), a[n + 1] = p;
	for (int i = 2; i <= n + 1; i++) {
		while (top >= 2 + (i == n + 1) && (a[i] - c[top - 1]) * (c[top] - c[top - 1]) >= 0) top--;
		c[++top] = a[i];
	}
}
void work(int l, int r) {
	e.emplace_back(l, r);
	if (l == r - 1) return;
	double Max = -INF; int pos = 0;
	for (int i = l + 1; i <= r - 1; i++) {
		double ang = dot(c[r] - c[i], c[l] - c[i]) / ((c[r] - c[i]) * (c[l] - c[i]));
		if (ang > Max) {
			Max = ang;
			pos = i;
		}
	}
	work(l, pos);
	work(pos, r);
}
bool check(point l, point r) {
	pair <double, double> rng = make_pair(-INF, INF);
	for (int i = 1; i <= n; i++) {
		if (fabs((a[i] - l) * (r - l)) <= eps) {
			assert(onseg(l, r, a[i]));
			continue;
		}
		if ((a[i] - l) * (r - l) > 0) {
			double ang = dot(r - a[i], l - a[i]) / ((r - a[i]) * (l - a[i]));
			chkmax(rng.first, ang);
		} else {
			double ang = dot(l - a[i], r - a[i]) / ((l - a[i]) * (r - a[i]));
			chkmin(rng.second, -ang);
		}
	}
	for (int i = 1; i <= m; i++) {
		if (fabs((b[i] - l) * (r - l)) <= eps) {
			if (onseg(l, r, b[i])) return false;
			continue;
		}
		if ((b[i] - l) * (r - l) > 0) {
			double ang = dot(r - b[i], l - b[i]) / ((r - b[i]) * (l - b[i]));
			chkmin(rng.second, ang);
		} else {
			double ang = dot(l - b[i], r - b[i]) / ((l - b[i]) * (r - b[i]));
			chkmax(rng.first, -ang);
		}
	}
	return rng.first < rng.second - eps;
}
bool solve() {
	if (n == 1) return true;
	convexHull();
	e.clear(), work(1, top - 1);
	for (auto x : e)
		if (check(c[x.first], c[x.second])) return true;
	return false;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	for (int i = 1; i <= m; i++)
		read(b[i].x), read(b[i].y);
	if (solve()) {
		puts("YES");
		return 0;
	}
	swap(n, m);
	swap(a, b);
	if (solve()) {
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}