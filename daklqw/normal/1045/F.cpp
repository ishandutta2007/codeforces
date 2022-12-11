#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
typedef long double db;
typedef int VT;
struct vec {
	VT x, y;
	vec() { x = y = 0; }
	vec(VT a, VT b) { x = a, y = b; }
	LL operator ^ (vec b) const { return (LL) x * b.y - (LL) y * b.x; }
	LL operator * (vec b) const { return (LL) x * b.x + (LL) y * b.y; }
	LL norm2() const { return (LL) x * x + (LL) y * y; }
	db norm() const { return sqrt((LL) x * x + (LL) y * y); }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	bool operator < (const vec & b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	bool operator == (const vec & b) const {
		return x == b.x && y == b.y;
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
inline LL cross(vec a, vec b, vec c) {
	return (b - a) ^ (c - a);
}
const int MAXCHST = 1000010;
VP convexhull(VP ps) {
	std::iter_swap(ps.begin(), std::min_element(ps.begin(), ps.end()));
	auto be = ps[0];
	std::sort(ps.begin() + 1, ps.end(),
			[be] (vec a, vec b) {
				a = a - be, b = b - be; LL t = a ^ b;
				return t == 0 ? a.norm2() < b.norm2() : t > 0;
			}
		);
	static vec st[MAXCHST]; int top = 0;
	for (auto t : ps) {
		while (top >= 2 && cross(st[top - 1], st[top], t) <= 0) --top;
		st[++top] = t;
	}
	return VP(st + 1, st + 1 + top);
}
int n;
bool judge(const VP & x) {
	for (auto t : x) if ((t.x & 1) || (t.y & 1)) return false;
	return true;
}
void bye() {
	std::cout << "Ani" << std::endl; exit(0);
}
VP del(const VP & x, VP y) {
	std::sort(y.begin(), y.end());
	VP res;
	int cur = 0, sz = y.size();
	for (auto t : x) {
		while (cur < sz && y[cur] < t) ++cur;
		if (cur == sz || !(y[cur] == t))
			res.push_back(t);
	}
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	VP all; all.resize(n);
	for (int i = 0; i < n; ++i) std::cin >> all[i];
	std::sort(all.begin(), all.end());
	if (!(all[0] == vec(0, 0)))
		all.insert(all.begin(), vec(0, 0));
	VP cx = convexhull(all);
	if (!judge(cx)) bye();
	VP p0, p1;
	p0.reserve(cx.size() + 1 >> 1);
	p1.reserve(cx.size() + 1 >> 1);
	for (int i = 1, s = cx.size(); i < s; ++i)
		(i & 1 ? p0 : p1).push_back(cx[i]);
	if (!judge(convexhull(del(all, p0)))) bye();
	if (!judge(convexhull(del(all, p1)))) bye();
	std::cout << "Borna" << std::endl;
	return 0;
}