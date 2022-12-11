#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long double db;
const db eps = 1e-8;
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
	// VT norm2() const { return x * x + y * y; }
	db norm() const { return sqrt(x * x + y * y); }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator * (db k) const { return vec(x * k, y * k); }
	vec resize(db l) {
		return *this * (l / norm());
	}
	bool operator < (const vec & b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec x) {
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}
} ps[MAXN];
typedef std::vector<vec> VP;
inline VT cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
struct line {
	vec x, y;
	db norm() { return (y - x).norm(); }
	line resize(db l) { return (line) {x, x + (y - x).resize(l)}; }
	friend std::ostream & operator << (std::ostream & out, line x) {
		out << x.x << '-' << x.y;
		return out;
	}
} ls[MAXN];
typedef std::vector<line> VL;
VL sg[MAXN];
int n, m;
void expand(db & A, db & B, db & C, db x, db y) {
	A += x * x, C += y * y, B += x * y * 2;
}
void solver(db & x1, db & x2, db A, db B, db C) {
	// Ax^2 + Bx + C <= 0
	if (eq(A, 0)) {
		if (eq(B, 0)) {
			if (leq(C, 0)) x1 = -1e9, x2 = 1e9;
			else x1 = 1e9, x2 = -1e9;
		} else {
			if (ge(B, 0)) x1 = -1e9, x2 = -C / B;
			else x1 = -C / B, x2 = 1e9;
		}
		return ;
	}
	db dta = B * B - 4 * A * C;
	if (dta <= 0) return (void) (x1 = 1e9, x2 = -1e9);
	dta = std::sqrt(dta);
	x1 = (-B - dta) / 2 / A, x2 = (-B + dta) / 2 / A;
}
bool solve(db lim) {
	typedef std::pair<db, int> tag;
	std::vector<tag> V;
	for (int i = 1; i <= m; ++i) {
		const VL & lhs = sg[i], & rhs = sg[i == m ? 1 : i + 1];
		const int LS = lhs.size(), RS = rhs.size();
		int lcur = 0, rcur = 0;
		line ln = lhs[0], rn = rhs[0], lq, rq;
		vec dl, dr;
		db pre = 0;
		while (true) {
			db dta = std::min(ln.norm(), rn.norm());
			lq = ln.resize(dta), rq = rn.resize(dta);
			dl = (ln.y - ln.x).resize(1);
			dr = (rn.y - rn.x).resize(1);
			ln.x = lq.y, rn.x = rq.y;
			db A = 0, B = 0, C = 0, x1, x2;
			expand(A, B, C, dl.x - dr.x, lq.x.x - rq.x.x);
			expand(A, B, C, dl.y - dr.y, lq.x.y - rq.x.y);
			solver(x1, x2, A, B, C -= lim * lim);
			x1 = std::max(x1, 0.l), x2 = std::min(x2, dta);
			if (le(x1, x2)) {
				V.emplace_back(x1 + pre, 1);
				V.emplace_back(x2 + pre, -1);
			}
			pre += dta;
			if (eq(ln.norm(), 0)) {
				if (lcur + 1 == LS && rcur + 1 == RS) break;
				ln = lhs[++lcur];
			}
			if (eq(rn.norm(), 0)) rn = rhs[++rcur];
		}
	}
	std::sort(V.begin(), V.end());
	int now = 0;
	for (auto t : V)
		if ((now += t.second) == m) return true;
	return false;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> ps[i];
	db C = 0;
	for (int i = 1; i <= n; ++i)
		C += (ls[i] = (line) {ps[i], ps[i == n ? 1 : i + 1]}).norm();
	C /= m;
	int cur = 1; line vn = ls[1];
	for (int i = 1; i <= m; ++i) {
		db now = 0;
		while (le(now, C)) {
			assert(cur <= n);
			db dta = std::min(vn.norm(), C - now);
			line tar = vn.resize(dta);
			sg[i].push_back(tar);
			vn.x = tar.y; now += dta;
			if (eq(vn.norm(), 0)) vn = ls[++cur];
		}
	}
	db l = 0, r = 3000;
	while (std::abs(r - l) > 1e-7) {
		db mid = (l + r) / 2;
		if (solve(mid)) r = mid; else l = mid;
	}
	std::cout << std::fixed << std::setprecision(10) << l << std::endl;
	return 0;
}