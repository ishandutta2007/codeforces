#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long double db;
const db eps = 1e-7;
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
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}
} ps[MAXN];
typedef std::vector<vec> VP;
inline VT cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
int n, m;
bool del[MAXN];
const db PI = acosl(-1);
db reduce(db x) { return std::fmod(x + PI * 10, PI * 2); }
int L[18][MAXN << 1];
struct itv { db l, r; int id; } is[MAXN << 1], deb[MAXN << 1];
std::map<db, std::vector<itv> > M;

bool solve(db lim) {
	int bak = 0;
	for (int i = 1; i <= n; ++i) {
		db tn = ps[i].norm();
		if (leq(tn, lim)) return false;
		db polar = std::atan2(ps[i].y, ps[i].x);
		db delta = std::acos(lim / tn);
		db l = reduce(polar - delta), r = reduce(polar + delta);
		if (leq(l, r)) {
			deb[++bak] = (itv) {l, r, i};
			deb[++bak] = (itv) {l + PI * 2, r + PI * 2, i};
		} else r += 2 * PI, deb[++bak] = (itv) {l, r, i};
		is[i].l = l, is[i].r = r;
	}
	memset(del, 0, n + 1);
	std::sort(deb + 1, deb + 1 + bak, [] (itv a, itv b) {
		return a.r < b.r;
	});
	db lb = 0;
	for (int i = 1; i <= bak; ++i)
		if (geq(deb[i].l, lb)) lb = deb[i].l;
		else del[deb[i].id] = true;
	bak = 0;
	for (int i = 1; i <= n; ++i) if (!del[i]) is[++bak] = is[i];
	std::sort(is + 1, is + 1 + bak, [] (itv a, itv b) {
		return a.l < b.l;
	});
	int _bak = bak;
	for (int i = 1; i <= _bak; ++i) {
		is[i].id = i;
		if (is[i].r < 2 * PI)
			is[++bak] = (itv) {is[i].l + PI * 2, is[i].r + PI * 2, i + _bak};
	}
	int cur = 1;
	for (int i = 1; i <= bak; ++i) {
		while (cur < i && is[cur].r < is[i].l) ++cur;
		L[0][i] = cur;
	}
	for (int i = 1; i != 18; ++i)
		for (int j = 1; j <= bak; ++j)
			if (L[i - 1][j]) L[i][j] = L[i - 1][L[i - 1][j] - 1];
	for (int i = bak; i >= _bak; --i) {
		int cur = i + 1;
		for (int j = 17; ~j && cur; --j) if (m >> j & 1)
			cur = L[j][cur - 1];
		if (i - cur + 1 >= _bak) return true;
	}
	return false;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	db l = 0, r = 0;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x, y; std::cin >> x >> y;
		r = std::max(r, (ps[i] = vec(x, y)).norm());
	}
	std::sort(ps + 1, ps + 1 + n, [] (vec a, vec b) {
		return a.norm() < b.norm();
	});
	while (std::abs(r - l) > eps) {
		db mid = (l + r) / 2;
		if (solve(mid)) l = mid; else r = mid;
	}
	std::cout << std::fixed << std::setprecision(10);
	std::cout << l << std::endl;
	return 0;
}