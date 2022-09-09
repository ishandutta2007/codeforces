#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const double rate = 0.001;
const double eps = 1e-9;
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
struct BinaryIndexTree {
	int n, a[MAXN];
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	int query(int x) {
		int ans = 0;
		for (int i = x; i >= 1; i -= i & -i)
			ans += a[i];
		return ans;
	}
	int query(int l, int r) {
		int ans = 0;
		for (int i = r; i >= 1; i -= i & -i)
			ans += a[i];
		for (int i = l - 1; i >= 1; i -= i & -i)
			ans -= a[i];
		return ans;
	}
} BIT;
struct point {double x, y; };
int n, m, tot, fa[MAXN]; point p;
pair <double, int> v[MAXN];
double a[MAXN], b[MAXN];
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
int check(double mid) {
	tot = 0;
	for (int i = 1; i <= n; i++) {
		double dist = abs(a[i] * p.x - p.y + b[i]) / sqrt(a[i] * a[i] + 1);
		if (dist < mid) {
			double ta = a[i] * a[i] + 1, tb = 2 * a[i] * (b[i] - p.y) - 2 * p.x, tc = p.x * p.x + (b[i] - p.y) * (b[i] - p.y) - mid * mid;
			double delta = sqrt(tb * tb - 4 * ta * tc);
			double tx = (-tb + delta) / (2 * ta), ty = tx * a[i] + b[i];
			double sx = (-tb - delta) / (2 * ta), sy = sx * a[i] + b[i];
			v[++tot] = make_pair(atan2(ty - p.y, tx - p.x), i);
			v[++tot] = make_pair(atan2(sy - p.y, sx - p.x), i);
		}
	}
	sort(v + 1, v + tot + 1);
	BIT.init(tot);
	static int f[MAXN], s[MAXN];
	memset(f, 0, sizeof(f));
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= tot; i++)
		if (f[v[i].second]) BIT.modify(i, -1), s[v[i].second] = i;
		else BIT.modify(i, 1), f[v[i].second] = i;
	ll ans = 0;
	for (int i = 1; i <= tot; i++)
		if (f[v[i].second] == i) {
			ans += BIT.query(s[v[i].second]);
			BIT.modify(s[v[i].second], 2);
			BIT.modify(f[v[i].second], -1);
		} else BIT.modify(s[v[i].second], -1);
	assert(ans % 2 == 0);
	return ans / 2;
}
double getdist(int x, int y) {
	double tx = (b[x] - b[y]) / (a[y] - a[x]), ty = tx * a[x] + b[x];
	return sqrt((tx - p.x) * (tx - p.x) + (ty - p.y) * (ty - p.y));
}
double getans(double mid) {
	double ans = mid * m;
	tot = 0;
	for (int i = 1; i <= n; i++) {
		double dist = abs(a[i] * p.x - p.y + b[i]) / sqrt(a[i] * a[i] + 1);
		if (dist < mid) {
			double ta = a[i] * a[i] + 1, tb = 2 * a[i] * (b[i] - p.y) - 2 * p.x, tc = p.x * p.x + (b[i] - p.y) * (b[i] - p.y) - mid * mid;
			double delta = sqrt(tb * tb - 4 * ta * tc);
			double tx = (-tb + delta) / (2 * ta), ty = tx * a[i] + b[i];
			double sx = (-tb - delta) / (2 * ta), sy = sx * a[i] + b[i];
			v[++tot] = make_pair(atan2(ty - p.y, tx - p.x), i);
			v[++tot] = make_pair(atan2(sy - p.y, sx - p.x), i);
		}
	}
	sort(v + 1, v + tot + 1);
	static int f[MAXN], s[MAXN];
	memset(f, 0, sizeof(f));
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= tot; i++)
		if (f[v[i].second]) BIT.modify(i, -1), s[v[i].second] = i;
		else BIT.modify(i, 1), f[v[i].second] = i;
	vector <pair <int, int>> tmp;
	for (int i = 1; i <= n; i++)
		if (f[i]) tmp.emplace_back(s[i] - f[i], i);
	sort(tmp.begin(), tmp.end());
	for (int i = 1; i <= tot + 1; i++)
		fa[i] = i;
	for (auto x : tmp) {
		int l = f[x.second], r = s[x.second];
		fa[l] = l + 1, fa[r] = r + 1;
		while ((l = find(l)) < r) {
			ans -= mid;
			ans += getdist(x.second, v[l].second);
			l += 1;
		}
	}
	return ans;
}
int main() {
	read(n), read(p.x), read(p.y), read(m);
	p.x *= rate, p.y *= rate;
	for (int i = 1; i <= n; i++) {
		read(a[i]), a[i] *= rate;
		read(b[i]), b[i] *= rate;
	}
	double l = 0, r = 1e10;
	while (l + 1e-9 < r && (r - l) / r > 1e-15) {
		double mid = (l + r) / 2;
		if (check(mid) < m) l = mid;
		else r = mid;
	}
	double ans = getans(l);
	printf("%.10lf\n", ans);
	return 0;
}