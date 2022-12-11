#include <bits/stdc++.h>

const int MAXN = 300010;
int col[MAXN], fa[MAXN], szx[MAXN], szy[MAXN];
int n, m;
char buf[MAXN];
int find(int u) {
	if (u == fa[u]) return u;
	int val = 0, x = u;
	while (fa[x] != x) val ^= col[x], x = fa[x];
	fa[u] = x, col[u] = val;
	return x;
}
int getcol(int x) { return fa[x] == x ? col[x] : col[x] ^ col[fa[x]]; }
std::vector<int> hav[MAXN];
int ans;
void flip(int x) { col[x] ^= 1, std::swap(szx[x], szy[x]); }
void adde(int A, int B, int x) {
	if (find(A) != find(B)) {
		int tx = find(A), ty = find(B);
		ans -= std::min(szx[tx], szy[tx]);
		ans -= std::min(szx[ty], szy[ty]);
		if ((getcol(A) ^ getcol(B)) == (buf[x] & 1)) flip(ty);
		if (col[tx]) col[ty] ^= 1;
		fa[ty] = tx;
		szx[tx] += szx[ty];
		szy[tx] += szy[ty];
		ans += std::min(szx[tx], szy[tx]);
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	std::cin >> buf + 1;
	for (int i = 1, t; i <= m; ++i) {
		fa[i] = i; std::cin >> t; szy[i] = 1;
		for (int j = 1, x; j <= t; ++j) {
			std::cin >> x;
			hav[x].push_back(i);
		}
	}
	col[m + 1]; fa[m + 1] = m + 1; szy[m + 1] = 0x3f3f3f3f;
	for (int i = 1; i <= n; ++i) {
		if (hav[i].empty()) ;
		else if (hav[i].size() == 1) adde(hav[i][0], m + 1, i);
		else adde(hav[i][0], hav[i][1], i);
		std::cout << ans << '\n';
	}
	return 0;
}