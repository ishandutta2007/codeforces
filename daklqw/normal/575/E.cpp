#include <bits/stdc++.h>

const int MAXN = 800010;
const int UP = 100000;
template<class T> T absx(T x) { return x < 0 ? -x : x; }
typedef long long LL;
typedef long double db;
struct Point {
	LL x, y;
	Point() { x = y = 0; }
	Point(LL a, LL b) { x = a, y = b; }
	LL operator ^ (Point b) const { return x * b.y - y * b.x; }
	LL operator * (Point b) const { return x * b.x + y * b.y; }
	LL norm() const { return x * x + y * y; }
	db slen() const { return sqrt(x * x + y * y); }
	Point operator - (Point b) const { return Point(x - b.x, y - b.y); }
	Point operator + (Point b) const { return Point(x + b.x, y + b.y); }
	Point operator * (db k) const { return Point(x * k, y * k); }
	bool operator < (const Point & b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	friend std::istream & operator >> (std::istream & in, Point & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, Point & x) {
		out << x.x << ' ' << x.y;
		return out;
	}

} ;
inline LL cross(Point a, Point b, Point c) {
	return (b - a) ^ (c - a);
}
typedef std::vector<Point> VP;
VP convexhull(VP ps) {
	std::iter_swap(ps.begin(), std::min_element(ps.begin(), ps.end()));
	auto be = ps[0];
	std::sort(ps.begin() + 1, ps.end(),
			[be] (Point a, Point b) {
				a = a - be, b = b - be; LL t = a ^ b;
				return t == 0 ? a.norm() < b.norm() : t > 0;
			}
		);
	static Point st[MAXN]; int top = 0;
	for (auto t : ps) {
		while (top >= 2 && cross(st[top - 1], st[top], t) <= 0) --top;
		st[++top] = t;
	}
	return VP(st + 1, st + 1 + top);
}
int n;
LL R(LL x) { return std::max(0ll, std::min(x, (LL) UP)); }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	VP li;
#define eb li.emplace_back
	for (int i = 1; i <= n; ++i) {
		int x, y, z, t;
		std::cin >> x >> y >> z;
		x >= z ? eb(x - z, y) : (t = z - x, eb(0, R(y - t)), eb(0, R(y + t)));
		y >= z ? eb(x, y - z) : (t = z - y, eb(R(x - t), 0), eb(R(x + t), 0));
		x + z <= UP ? eb(x + z, y) : (t = x + z - UP, eb(UP, R(y - t)), eb(UP, R(y + t)));
		y + z <= UP ? eb(x, y + z) : (t = y + z - UP, eb(R(x - t), UP), eb(R(x + t), UP));
	}
#undef eb
	VP ch = convexhull(li); const int SZ = ch.size();
	typedef std::tuple<Point, Point, Point> AL;
	AL ans; double av = 0;
	for (int i = 0; i != SZ; ++i) {
		auto A = ch[i], B = ch[(i + 1) % SZ], C = ch[(i + 2) % SZ];
		double R = (A - B).slen() * (B - C).slen() * (A - C).slen();
		R /= absx(cross(A, B, C));
		if (R > av) av = R, ans = std::make_tuple(A, B, C);
	}
	std::cout << std::get<0> (ans) << '\n';
	std::cout << std::get<1> (ans) << '\n';
	std::cout << std::get<2> (ans) << '\n';
	return 0;
}