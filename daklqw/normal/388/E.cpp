#include <bits/stdc++.h>

const int MAXN = 1010;

typedef long double db;
const db eps = 1e-8;
bool le(db a, db b) { return a + eps < b; }
bool ge(db a, db b) { return a - eps > b; }
bool leq(db a, db b) { return a - eps <= b; }
bool geq(db a, db b) { return a + eps >= b; }
bool eq(db a, db b) { return a <= b + eps && b <= a + eps; }

typedef db VT;
struct vec {
	VT x, y;
	vec() { x = y = 0; }
	vec(VT a, VT b) { x = a, y = b; }
// WARN: modify following 4 functions if VT is int
// 1. A * B    2. return LL
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
	bool operator == (const vec & b) const {
		return eq(x, b.x) && eq(y, b.y);
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec x) {
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}
} ps[MAXN], vs[MAXN];
typedef std::vector<vec> VP;
vec trans(vec x) {
	if (eq(x.y, 0)) return vec(std::abs(x.x), 0);
	return x.y < 0 ? vec(-x.x, -x.y) : x;
}
int n;

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, l, r; i <= n; ++i) {
		std::cin >> l >> ps[i] >> r >> vs[i];
		vec sp = (vs[i] - ps[i]) * (1. / (r - l));
		ps[i] = ps[i] - sp * l;
		vs[i] = sp;
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		static db tim[MAXN];
		static vec ns[MAXN];
		int bak = 0;
		for (int j = i + 1; j <= n; ++j) {
			vec lhs = ps[i] - ps[j], rhs = vs[j] - vs[i];
			if (std::abs(lhs ^ rhs) > eps) continue;
			if (rhs.norm() < eps) continue;
			++bak;
			ns[bak] = rhs;
			db t = lhs.norm() / rhs.norm();
			rhs = rhs * t;
			if (!(rhs == lhs)) t = -t;
			tim[bak] = t;
		}
		if (!bak) continue;
		ans = std::max(ans, 2);
		std::sort(tim + 1, tim + 1 + bak);
		int tmp = 1;
		for (int j = 2; j <= bak; ++j) {
			if (eq(tim[j], tim[j - 1]))
				ans = std::max(ans, ++tmp + 1);
			else tmp = 1;
		}
		auto cmp = [] (vec a, vec b) {
			db cr = trans(a) ^ trans(b);
			// db cr = a ^ b;
			return eq(cr, 0) ? a < b : cr < 0;
		};
		std::sort(ns + 1, ns + 1 + bak, cmp);
		for (int j = 1; j <= bak; ) {
			tmp = 1;
			int r = j + 1;
			while (r <= bak && eq(ns[j] ^ ns[r], 0)) {
				if (!(ns[r - 1] == ns[r])) ++tmp;
				++r;
			}
			ans = std::max(ans, tmp + 1);
			j = r;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}