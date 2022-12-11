#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef long long LL;
struct vec {
	int x, y, id, at;
	vec() { x = y = 0; }
	vec(int a, int b) { x = a, y = b; }
	int operator ^ (vec b) const { return x * b.y - y * b.x; }
	int operator * (vec b) const { return x * b.x + y * b.y; }
	vec operator * (int k) const { return vec(x * k, y * k); }
	int norm2() const { return x * x + y * y; }
	bool operator < (vec b) {
		return (LL) x * b.y < (LL) y * b.x;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
} ps[MAXN], ans(-1, -114514);

int atx, aty;
int polar(vec x) {
	return x.y < 0 ? 2 : x.y == 0;
}
void judge(vec x, vec y) {
	if ((x ^ y) < 0) return ;
	vec deg(x ^ y, x * y);
	bool r = false;
	if (ans.x == -1) r = true;
	else if (polar(deg) < polar(ans)) r = true;
	else if (deg < ans) r = true;
	if (r) {
		ans = deg;
		atx = x.id;
		aty = y.id;
	}
}
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		vec a; std::cin >> a; a.id = i;
		a.at = a.y < 0 || (a.y == 0 && a.x < 0);
		ps[i] = a;
	}
	auto cmp = [] (vec a, vec b) {
		if (a.at != b.at) return a.at < b.at;
		int t = a ^ b;
		return t == 0 ? a.norm2() < b.norm2() : t > 0;
	};
	std::sort(ps + 1, ps + 1 + n, cmp);
	for (int i = 1; i < n; ++i)
		judge(ps[i], ps[i + 1]);
	judge(ps[n], ps[1]);
	std::cout << atx << ' ' << aty << std::endl;
	return 0;
}