#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5;
const int MAXP = 20;
const long double eps = 1e-8;
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
struct point {
	long double x, y;
	long double len() {
		return sqrt(x * x + y * y);
	}
	point unit() {
		long double tmp = len();
		return (point) {x / tmp, y / tmp};
	}
	point normal(bool type) {
		if (type) return (point) {-y, x};
		else return (point) {y, -x};
	}
};
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (long double a, point b) {return (point) {a * b.x, a * b.y}; }
bool operator == (point a, point b) {return fabs(a.x - b.x) <= eps && fabs(a.y - b.y) <= eps; }
long double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
long double operator ^ (point a, point b) {return a.x * b.x + a.y * b.y; }
struct circle {point pos; long double r; };
circle a[MAXN];
bool dis[MAXP];
bool vis[MAXN];
point p[MAXP];
int n, m, cnt, C, E, V, Ans;
bool on(point x, circle a) {
	if (fabs((a.pos - x).len() - a.r) <= eps) return true;
	else return false;
}
bool in(point x, circle a) {
	if ((a.pos - x).len() < a.r - eps) return true;
	else return false;
}
bool intersect(circle a, circle b) {
	long double d = (a.pos - b.pos).len();
	if (d < a.r + b.r + eps && d > fabs(a.r - b.r) - eps) return true;
	else return false;
}
void GetIntersection(circle a, circle b) {
	long double d = (a.pos - b.pos).len();
	if (fabs(d - a.r - b.r) <= eps) {
		point tmp = (b.pos - a.pos).unit();
		p[++cnt] = a.pos + a.r * tmp;
		return;
	}
	long double tmp = (d * d + a.r * a.r - b.r * b.r) / (2 * d);
	point tnp = (b.pos - a.pos).unit();
	point mid = a.pos + tmp * tnp;
	p[++cnt] = mid + sqrt(a.r * a.r - tmp * tmp) * tnp.normal(true);
	p[++cnt] = mid + sqrt(a.r * a.r - tmp * tmp) * tnp.normal(false);
}
void visit(int pos) {
	vis[pos] = true;
	for (int i = 1; i <= n; i++)
		if (!vis[i] && intersect(a[i], a[pos])) visit(i);
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].pos.x), read(a[i].pos.y), read(a[i].r);
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
		if (intersect(a[i], a[j])) GetIntersection(a[i], a[j]);
	for (int i = 1; i <= cnt; i++)
	for (int j = 1; j <= i - 1; j++)
		if (p[i] == p[j]) dis[i] = true;
	int tcnt = 0;
	for (int i = 1; i <= cnt; i++)
		if (dis[i] == false) p[++tcnt] = p[i];
	V = cnt = tcnt;
	for (int i = 1; i <= cnt; i++)
	for (int j = 1; j <= n; j++)
		if (on(p[i], a[j])) E++;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) C++, visit(i);
	writeln(Ans = E - V + C + 1);
	return 0;
}