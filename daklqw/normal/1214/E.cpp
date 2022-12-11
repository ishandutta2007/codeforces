#include <bits/stdc++.h>

const int MAXN = 100010;
int n, d[MAXN], rk[MAXN];
int st[MAXN], top, vis[MAXN];
int li[MAXN], bak;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> d[i];
	for (int i = 1; i <= n; ++i) rk[i] = i;
	std::sort(rk + 1, rk + 1 + n, [] (int a, int b) { return d[a] < d[b]; });
	for (int i = 1; i < n; ++i)
		std::cout << rk[i] * 2 - 1 << ' ' << rk[i + 1] * 2 - 1 << '\n';
	for (int i = 1; i <= n; ++i) {
		int t = i - (d[rk[i]] - 1);
		if (t > 0) {
			std::cout << rk[t] * 2 - 1 << ' ' << rk[i] * 2 << std::endl;
			vis[i] = true;
			if (t == 1) st[top = 1] = rk[i] * 2;
		}
		if (!vis[i]) {
			t = i + (d[rk[i]] - 1);
			if (t <= n) {
				std::cout << rk[t] * 2 - 1 << ' ' << rk[i] * 2 << std::endl;
				vis[i] = true;
				if (t == 1) st[top = 1] = rk[i] * 2;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			li[++bak] = i;
			d[rk[i]] = (d[rk[i]] - 1) - (i - 1);
		}
	std::sort(li + 1, li + 1 + bak, [] (int a, int b) {
		return d[rk[a]] < d[rk[b]];
	});
	st[0] = rk[1] * 2 - 1;
	for (int i = 1; i <= bak; ++i) {
		int u = li[i];
		while (top > d[rk[u]]) --top;
		// std::cout << "NOW " << u << ' ' << d[rk[u]] << ' ' << top << ' ' << st[top] << std::endl;
		std::cout << st[top] << ' ' << rk[u] * 2 << '\n';
		st[++top] = rk[u] * 2;
	}
	return 0;
}