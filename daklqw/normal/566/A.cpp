#include <bits/stdc++.h>

const int MAXN = 800010;
int nxt[MAXN][26], dep[MAXN], ans;
int idx = 1;
typedef std::pair<int, int> pi;
std::vector<pi> ansl;
void push(int x, int y) {
	if (x < y) std::swap(x, y);
	ansl.emplace_back(x, -y);
}
typedef std::vector<int> VI;
VI hav[MAXN];
int merge(VI & a, VI & b) {
	if (a.size() < b.size()) std::swap(a, b);
	if (b.empty()) return 0;
	if ((a[0] > 0) ^ (b[0] > 0)) {
		int res = b.size();
		for (auto t : b) {
			push(a.back(), t);
			a.pop_back();
		}
		return res;
	} else {
		a.insert(a.end(), b.begin(), b.end());
		b.clear();
		return 0;
	}
}
void ins(char * s, int id) {
	int u = 1;
	while (*s) {
		int & nt = nxt[u][*s++ - 'a'];
		if (!nt) dep[nt = ++idx] = dep[u] + 1;
		u = nt;
	}
	VI tmp(1, id);
	ans += dep[u] * merge(hav[u], tmp);
}
void dfs(int u) {
	for (int i = 0; i != 26; ++i)
		if (nxt[u][i]) {
			dfs(nxt[u][i]);
			ans += dep[u] * merge(hav[u], hav[nxt[u][i]]);
		}
}
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	static char buf[MAXN];
	for (int i = 1; i <= n; ++i)
		std::cin >> buf, ins(buf, i);
	for (int i = 1; i <= n; ++i)
		std::cin >> buf, ins(buf, -i);
	dfs(1);
	std::cout << ans << std::endl;
	for (auto t : ansl)
		std::cout << t.first << ' ' << t.second << '\n';
	return 0;
}