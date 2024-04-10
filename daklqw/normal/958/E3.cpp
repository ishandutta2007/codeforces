#include <bits/stdc++.h>

const int MAXN = 20010;
struct P {
	int x, y, id;
	bool operator < (P b) {
		int t = x * b.y - y * b.x;
		return t == 0 ? x * x + y * y < b.x * b.x + b.y * b.y : t > 0;
	}
} ps[MAXN];
int ansl[MAXN], n;
void solve(int l, int r) {
	if (l >= r) return ;
	int at = l;
	for (int i = l + 1; i <= r; ++i)
		if (ps[i].y < ps[at].y || (ps[i].y == ps[at].y && ps[i].x < ps[at].x)) at = i;
	std::swap(ps[at], ps[l]);
	for (int i = l + 1; i <= r; ++i)
		ps[i].x -= ps[l].x, ps[i].y -= ps[l].y;
	std::sort(ps + l + 1, ps + r + 1);
	int cur = l + 1, dta = 0;
	while (cur <= r) {
		bool diff = (ps[cur].id > n) ^ (ps[l].id > n);
		if (diff && dta == 0) {
			int x = ps[cur].id, y = ps[l].id;
			if (x > y) std::swap(x, y);
			ansl[x] = y - n;
			solve(l + 1, cur - 1);
			solve(cur + 1, r);
			return ;
		}
		dta += diff ? 1 : -1;
		++cur;
	}
	std::cout << "ERR!\n"; exit(1);
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n * 2; ++i) {
		std::cin >> ps[i].x >> ps[i].y;
		ps[i].id = i;
	}
	solve(1, n * 2);
	for (int i = 1; i <= n; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}