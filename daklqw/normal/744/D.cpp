#include <bits/stdc++.h>

const int MAXN = 2010;
typedef long double db;
const db eps = 1e-6;
bool le(db a, db b) { return a + eps < b; }
bool ge(db a, db b) { return a - eps > b; }
bool leq(db a, db b) { return a - eps <= b; }
bool geq(db a, db b) { return a + eps >= b; }
bool eq(db a, db b) { return a <= b + eps && b <= a + eps; }
typedef long long LL;
typedef long double db;
typedef db VT;
struct vec {
	VT x, y;
	vec() { x = y = 0; }
	vec(VT a, VT b) { x = a, y = b; }
	VT operator ^ (vec b) const { return x * b.y - y * b.x; }
	VT operator * (vec b) const { return x * b.x + y * b.y; }
	VT norm2() const { return x * x + y * y; }
	db norm() const { return sqrt(x * x + y * y); }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator * (db k) const { return vec(x * k, y * k); }
	bool operator < (const vec & b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec & x) {
		out << x.x << ' ' << x.y;
		return out;
	}
} ;
typedef std::vector<vec> VP;
inline VT cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}

int n, m;
vec A[MAXN];
typedef std::pair<db, int> pi;
std::vector<pi> V;
typedef std::pair<db, db> deb;
db nil = -123456789;
const db PI = acosl(-1);
db red(db x) {
	return fmodl(x + PI * 2 * 5, PI * 2);
}
deb calc(vec x, vec y, db r) {
	if (ge((x = y - x).norm2(), r * r * 4)) return deb(nil, nil);
	db dis = x.norm();
	db delta = acosl(dis / 2 / r);
	db deg = atan2l(x.y, x.x);
	return deb(red(deg - delta), red(deg + delta));
}
bool solve(int idx, db R) {
	V.clear();
	if (idx <= n) V.emplace_back((db) 0, 1);
	for (int i = 1; i <= n + m; ++i) if (i != idx) {
		deb r = calc(A[idx], A[i], R);
		if (r.first == nil) continue;
		const int v = i <= n ? 1 : -1e6;
		if (r.first > r.second) V.emplace_back((db) 0, v);
		V.emplace_back(r.first, v);
		V.emplace_back(r.second, -v);
	}
	std::sort(V.begin(), V.end());
	int now = 0;
	for (auto t : V) if ((now += t.second) > 0) return true;
	return false;
}
const db ma = 1e9;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n + m; ++i) std::cin >> A[i];
	db l = 0.5;
	for (int i = 1; i <= n + m; ++i) if (solve(i, l)) {
		db r = ma, mid;
		while (le(l, r))
			solve(i, mid = (l + r) / 2) ? l = mid : r = mid;
	}
	if (l > ma - 1.2243) std::cout << -1 << std::endl;
	else std::cout << std::fixed << std::setprecision(10) << l << std::endl;
	return 0;
}