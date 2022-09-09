#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 1e9 + 5;
const double eps = 1e-8;
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
double operator * (point a, point b) {return 1ll * a.x * b.y - 1ll * a.y * b.x; }
double dot(point a, point b) {return a.x * b.x + a.y * b.y; }
double moo(point a) {return a.x * a.x + a.y * a.y; }
double dist(point a) {return sqrt(moo(a)); }
int n, m; point a[MAXN], b[MAXN], p, q;
bool collide(int i, int j) {
	double goal = moo(q), l = INF, r = 0;
	int tot = 0; point pt[4];
	for (int di = 0; di <= 1; di++)
	for (int dj = 0; dj <= 1; dj++) {
		pt[tot++] = q - b[j - dj] + a[i - di];
		chkmin(l, moo(pt[tot - 1])), chkmax(r, moo(pt[tot - 1]));
	}
	if (goal > r) return false;
	if (goal >= l) return true;
	for (int i = 0; i <= 3; i++)
	for (int j = i + 1; j <= 3; j++) {
		if (pt[i] * pt[j] == 0) continue;
		double tmp = dot(p - pt[i], pt[j] - pt[i]) / dist(pt[i] - pt[j]);
		point res = pt[i] + (pt[j] - pt[i]) * (tmp / dist(pt[i] - pt[j]));
		if (dist(res) <= sqrt(goal) + eps && dist(res - pt[i]) + dist(res - pt[j]) - dist(pt[i] - pt[j]) <= eps) return true;
	}
	return false;
}
int main() {
	read(p.x), read(p.y), read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].x), read(a[i].y);
		a[i] = a[i] - p;
	}
	read(q.x), read(q.y), read(m);
	for (int i = 1; i <= m; i++) {
		read(b[i].x), read(b[i].y);
		b[i] = b[i] - p;
	}
	a[0] = a[n], b[0] = b[m];
	q = q - p, p = p - p;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (collide(i, j)) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}