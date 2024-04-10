#include <bits/stdc++.h>

const int MAXN = 1000010;
std::vector<int> out[MAXN];
bool vis[MAXN];
int n, m;
int li[MAXN], bak;

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1, b, e; i <= m; ++i)
		std::cin >> b >> e, out[b].push_back(e);
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		li[++bak] = i;
		for (auto t : out[i]) vis[t] = true;
	}
	memset(vis, 0, sizeof vis);
	for (int i = bak; i; --i) if (!vis[li[i]]) {
		for (auto t : out[li[i]]) vis[t] = true;
	} else li[i] = -1, --bak;
	std::cout << bak << std::endl;
	for (int i = 1; li[i]; ++i) if (li[i] != -1)
		std::cout << li[i] << ' ';
	return 0;
}