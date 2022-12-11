#include <bits/stdc++.h>

const int mod = 1000000007;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double db;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int fastpow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
struct Point {
	LL x, y;
	Point() { x = y = 0; }
	Point(LL a, LL b) { x = a, y = b; }
	LL operator ^ (Point b) const { return x * b.y - y * b.x; }
	Point operator - (Point b) const { return Point(x - b.x, y - b.y); }
	Point operator + (Point b) const { return Point(x + b.x, y + b.y); }
	friend std::istream & operator >> (std::istream & in, Point & x) {
		in >> x.x >> x.y;
		return in;
	}

} ;
typedef std::vector<Point> VP;
int n; 
const int MAXN = 1000010;
Point ps[MAXN];
LL ars[MAXN], area;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> ps[n - i - 1];
	for (int i = n; i < n * 2; ++i) ps[i] = ps[i - n];
	n <<= 1;
	for (int i = 0; i < n; ++i) ars[i] = ps[i] ^ ps[i + 1];
	for (int i = 0; i < n / 2; ++i) area += ars[i];
	LL now = 0;
	int is = 0, ss = 0, vx = 0, vy = 0;
	int cur = 0, ans = 0;
	for (int i = 0; i < n / 2; ++i) {
		while (true) {
			LL t = now + (ps[cur + 1] ^ ps[i]) + ars[cur];
			if (t >= area - t) break;
			now += ars[cur];
			reduce(is += ss - mod);
			is = remod(is + ars[cur]);
			ss = remod(ss + ars[cur]);
			vx = remod(vx + ps[cur].x);
			vy = remod(vy + ps[cur].y);
			++cur;
		}
		int val = is;
		int sx = remod(-vx - ps[cur].x + ps[i].x);
		int sy = remod(-vy - ps[cur].y + ps[i].y);
		val = remod((LL) remod(ps[i].x) * sy - (LL) remod(ps[i].y) * sx + val);
		val = remod((LL) remod(area) * (cur - i - 1) - val * 2);
		reduce(ans += val - mod);
		now -= ars[i];
		reduce(is -= mul(remod(ars[i]), cur - i));
		ss = remod(ss - ars[i]);
		vx = remod(vx - ps[i].x);
		vy = remod(vy - ps[i].y);
	}
	std::cout << ans << std::endl;
	return 0;
}