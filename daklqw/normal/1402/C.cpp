#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef long long LL;
typedef std::pair<int, int> pi;
int n, m, K, A[MAXN];
int mv[MAXN], am[MAXN];
struct C {
	LL x; int y, z;
	C() { x = y = z = 0; }
	C(LL a, int b, int c) { x = a, y = b, z = c; }
} ;
std::vector<C> add[MAXN];
struct D { LL x, y; int id, typ; } li[MAXN];
int bak;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> K;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1, t1, t2, t3; i <= m; ++i) {
		std::cin >> t1 >> t2 >> t3;
		if (t1 == 3) li[++bak] = (D) {t3 - 1, 1, i, 3};
		else if (t1 == 2) add[t2].emplace_back(t3, i, 2);
		else if (t3 > mv[t2]) mv[t2] = t3, am[t2] = i;
	}
	for (int i = 1; i <= n; ++i) if (mv[i] > A[i])
		add[i].emplace_back(mv[i] - A[i], am[i], 1);
	for (int i = 1; i <= n; ++i) {
		std::vector<C> & V = add[i];
		std::sort(V.begin(), V.end(), [] (C a, C b) { return a.x > b.x; });
		LL lst = A[i];
		for (auto t : V) {
			li[++bak] = (D) {t.x, lst, t.y, t.z};
			lst += t.x;
		}
	}
	std::sort(li + 1, li + 1 + bak, [] (D a, D b) {
		return a.x * b.y > a.y * b.x;
	});
	std::vector<pi> ansl;
	for (int i = 1, up = std::min(bak, K); i <= up; ++i) {
		if (li[i].x < 0) break;
		ansl.emplace_back(li[i].typ, li[i].id);
	}
	std::sort(ansl.begin(), ansl.end());
	std::cout << ansl.size() << '\n';
	for (auto t : ansl) std::cout << t.second << ' ';
	std::cout << std::endl;
	return 0;
}