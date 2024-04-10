#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const double INF = 1e6;
const double eps = 1e-16;
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
struct line {point a, b; double ra, rb; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, double b) {return (point) {a.x * b, a.y * b}; }
double operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
point intersect(const line &x, const line &y) {
	double tmp = (y.a - x.a) * (y.b - x.a);
	double tnp = (y.b - x.b) * (y.a - x.b);
	return (x.a * tnp + x.b * tmp) * (1 / (tmp + tnp));
}
point get(line a, double rad) {
	return intersect(a, (line) {(point) {0, 0}, (point) {cos(rad), sin(rad)}});
}
bool better(line a, line b, double rad) {
	if (a.ra == a.rb) return false;
	if (b.ra == b.rb) return true;
	point ta = get(a, rad);
	point tb = get(b, rad);
	return ta.x * ta.x + ta.y * ta.y < tb.x * tb.x + tb.y * tb.y;
}
struct SegmentTree {
	struct Node {
		int lc, rc; double rad;
		line Max, Nax;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r, double *ang) {
		root = ++size;
		a[root].rad = (ang[l] + ang[r + 1]) / 2;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, ang);
		build(a[root].rc, mid + 1, r, ang);
	}
	void init(int x, double *ang) {
		n = x, root = size = 0;
		build(root, 1, n, ang);
	}
	void addline(int root, line x) {
		if (better(x, a[root].Max, a[root].rad)) {
			a[root].Nax = a[root].Max;
			a[root].Max = x;
		} else if (better(x, a[root].Nax, a[root].rad)) a[root].Nax = x;
	}
	void modify(int root, int l, int r, int ql, int qr, line x) {
		if (l == ql && r == qr) {
			addline(root, x);
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), x);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, x);
	}
	void modify(int l, int r, line x) {
		modify(root, 1, n, l, r, x);
	}
	void pushdown(int root) {
		if (a[root].Max.ra != a[root].Max.rb) {
			addline(a[root].lc, a[root].Max);
			addline(a[root].rc, a[root].Max);
		}
		if (a[root].Nax.ra != a[root].Nax.rb) {
			addline(a[root].lc, a[root].Nax);
			addline(a[root].rc, a[root].Nax);
		}
	}
	double res;
	void getans(int root, int l, int r, double *ang) {
		if (l == r) {
			if (a[root].Max.ra == a[root].Max.rb) return;
			res += get(a[root].Nax, ang[l]) * get(a[root].Nax, ang[r + 1]);
			res -= get(a[root].Max, ang[l]) * get(a[root].Max, ang[r + 1]);
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		getans(a[root].lc, l, mid, ang);
		getans(a[root].rc, mid + 1, r, ang);
	}
	double getans(double *ang) {
		getans(root, 1, n, ang);
		return res / 2;
	}
} ST;
int lines; line a[MAXN];
int angles; double ang[MAXN];
void AddSegment(point s, point t) {
	if (s * t == 0) return; // Without Loss of Precision
	if (s * t < 0) swap(s, t);
	if (s.y > 0 && t.y < 0){
		point p = intersect((line) {s, t}, (line) {(point) {0, 0}, (point) {-INF, 0}});
		p.y = 0, AddSegment(s, p), AddSegment(t, p);
	} else {
		double ra = atan2(s.y, s.x);
		double rb = atan2(t.y, t.x);
		if (ra > rb) ra = -pi;
		a[++lines] = (line) {s, t, ra, rb};
	}
}
int main() {
	int T; read(T);
	while (T--) {
		int m; read(m);
		static point p[MAXN];
		for (int i = 1; i <= m; i++)
			read(p[i].x), read(p[i].y);
		p[0] = p[m];
		for (int i = 1; i <= m; i++)
			AddSegment(p[i - 1], p[i]);
	}
	for (int i = 1; i <= lines; i++) {
		ang[++angles] = a[i].ra;
		ang[++angles] = a[i].rb;
	}
	sort(ang + 1, ang + angles + 1);
	int tmp = angles; angles = 0;
	for (int i = 1; i <= tmp; i++)
		if (i == 1 || ang[i] - ang[angles] > eps) ang[++angles] = ang[i];
	ST.init(angles - 1, ang);
	for (int i = 1; i <= lines; i++) {
		int l = lower_bound(ang + 1, ang + angles + 1, a[i].ra - eps) - ang;
		int r = lower_bound(ang + 1, ang + angles + 1, a[i].rb - eps) - ang;
		ST.modify(l, r - 1, a[i]);
	}
	printf("%.10lf\n", ST.getans(ang));
	return 0;
}