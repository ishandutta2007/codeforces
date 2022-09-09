#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const double eps = 1e-10;
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
struct circle {point o; double r; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, double b) {return (point) {a.x * b, a.y * b}; }
double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
double moo(point a) {return sqrt(a.x * a.x + a.y * a.y); }
point unit(point a) {return a * (1.0 / moo(a)); }
double dist(point a, point b) {return moo(b - a); }
double PolarAngle(point a) {return atan2(a.y, a.x); }
pair <point, point> intersect(circle a, circle b) {
	double d = dist(a.o, b.o);
	double x = (a.r * a.r + d * d - b.r * b.r) / (2 * d);
	double z = sqrt(a.r * a.r - x * x);
	point u = unit(b.o - a.o);
	point mid = a.o + u * x;
	swap(u.x, u.y), u.x *= -1;
	return make_pair(mid + u * z, mid - u * z);
}
int n; double l;
circle a[MAXN];
point p, q;
bool valid(double mid) {
	circle o = (circle) {p, mid};
	vector <pair <double, int>> res;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		double d = dist(o.o, a[i].o);
		if (o.r + a[i].r > d && fabs(o.r - a[i].r) < d) {
			tot++;
			pair <point, point> tmp = intersect(o, a[i]);
			res.emplace_back(PolarAngle(tmp.first - o.o), tot);
			res.emplace_back(PolarAngle(tmp.second - o.o), tot);
		}
	}
	if (res.empty()) return false;
	sort(res.begin(), res.end());
	static int Stack[MAXN]; int top = 0;
	for (auto x : res) {
		if (Stack[top] == x.second) top--;
		else Stack[++top] = x.second;
	}
	return top != 0;
}
int main() {
	read(n), read(l);
	p = (point) {l, 0}, q = (point) {-l, 0};
	for (int i = 1; i <= n; i++) {
		read(a[i].o.x), read(a[i].o.y);
		a[i].r = dist(a[i].o, q);
	}
	double l = 0, r = dist(p, q);
	while (r - l >= eps) {
		double mid = (l + r) / 2;
		if (valid(mid)) r = mid;
		else l = mid;
	}
	printf("%.8lf\n", (l + r) / 2);
	return 0;
}