#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXLOG = 20;
const double eps = 1e-10;
const double pi = acos(-1);
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
struct point {double x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, double b) {return (point) {a.x * b, a.y * b}; }
double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
double moo(point a) {return sqrt(a.x * a.x + a.y * a.y); }
double PolarAngle(point a) {return atan2(a.y, a.x); }
point unit(point a) {return a * (1.0 / moo(a)); }
int n, m, nxt[MAXN][MAXLOG]; point a[MAXN];
pair <double, double> p[MAXN];
bool check(double x) {
	memset(nxt, 0, sizeof(nxt));
	for (int i = 1, cnt = 0; i <= n; i++) {
		double ang = PolarAngle(a[i]), delta = acos(x / moo(a[i]));
		if (ang + delta > pi) ang -= 2 * pi;
		p[++cnt] = make_pair(ang + delta, ang - delta);
		p[++cnt] = make_pair(ang + delta + 2 * pi, ang - delta + 2 * pi);
	}
	sort(p + 1, p + 2 * n + 1);
	for (int i = 1, j = 1; i <= 2 * n; i++) {
		while (j <= 2 * n - 1 && p[j].second <= p[i].first) j++;
		nxt[i][0] = j;
	}
	for (int p = 1; p < MAXLOG; p++)
	for (int i = 1; i <= 2 * n; i++)
		nxt[i][p] = nxt[nxt[i][p - 1]][p - 1];
	for (int i = 1; i <= n; i++) {
		int pos = i, ans = 1;
		for (int j = MAXLOG - 1; j >= 0; j--)
			if (nxt[pos][j] < i + n) {
				pos = nxt[pos][j];
				ans += 1 << j;
			}
		if (ans <= m) return true;
	}
	return false;
}
int main() {
	read(n), read(m);
	double l = 0, r = 1e18;
	for (int i = 1; i <= n; i++) {
		read(a[i].x), read(a[i].y);
		chkmin(r, moo(a[i]));
	}
	if (r < eps) {
		printf("%.10lf\n", 0.0);
		return 0;
	}
	r -= eps;
	while (l + eps < r) {
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.10lf\n", (l + r) / 2);
	return 0;
}