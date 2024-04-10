#include <bits/stdc++.h>

typedef long double db;
typedef long long LL;
const db eps = 1e-6;
bool le(db a, db b) { return a + eps < b; }
bool ge(db a, db b) { return a - eps > b; }
bool leq(db a, db b) { return a - eps <= b; }
bool geq(db a, db b) { return a + eps >= b; }
bool eq(db a, db b) { return a <= b + eps && b <= a + eps; }

LL m; int Q;
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
		return x == b.x ? y > b.y : x < b.x;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec x) {
		out << '(' << x.x << ',' << x.y << ')';
		return out;
	}

} ;
typedef std::vector<vec> VP;
inline VT cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
typedef std::set<vec> SS;
typedef SS::iterator I;
SS S;
bool toleft(I it) {
	if (it == S.begin()) return false;
	I b = it; --b;
	if (b == S.begin()) return false;
	I a = b; --a;
	if (leq(cross(*a, *b, *it), 0)) {
		S.erase(b);
		return true;
	}
	return false;
}
bool toright(I it) {
	I b = it; ++b;
	if (b == S.end()) return false;
	I c = b; ++c;
	if (c == S.end()) return false;
	if (leq(cross(*it, *b, *c), 0)) {
		S.erase(b);
		return true;
	}
	return false;
}
void ins(vec x) {
//	auto l = S.lower_bound(x), r = l;
//	if (r != S.end() && eq(x.x, r->x)) {
//		if (le(x.y, r->y)) S.erase(r);
//		else return ;
//	}
//	if (l != S.begin() && eq(x.x, (--l)->x)) {
//		if (le(x.y, l->y)) S.erase(l);
//		else return ;
//	}
	// std::cout << "INS " << x << std::endl;
	auto t = S.insert(x).first;
	while (toleft(t)) ;
	--t;
	while (toright(t)) ;
}
bool qry(vec x) {
	// std::cout << "QRY " << x << std::endl;
	auto tmp = S.end(); --tmp;
	if (ge(x.x, tmp->x)) return false;
	if (eq(x.x, tmp->x)) return geq(x.y, tmp->y);
	vec l, r;
	auto t = S.lower_bound(x);
	r = *t, l = *--t;
	return leq(cross(x, r, l), 0);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> Q >> m;
	int lans = 0;
	S.insert(vec(0, 0));
	for (int T = 1; T <= Q; ++T) {
		int opt, x, y;
		std::cin >> opt >> x >> y;
		x = (x + lans) % 1000000 + 1;
		y = (y + lans) % 1000000 + 1;
		if (opt == 1)
			ins(vec(m * x / (db) y, m / (db) y));
		else {
			int v;
			if (v = qry(vec(y, x))) lans = T;
			std::cout << (v ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}