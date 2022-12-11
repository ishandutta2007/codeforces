#include <bits/stdc++.h>

const int MAXN = 1010;
double P[MAXN][MAXN];
double E[MAXN], prod[MAXN], dis[MAXN];
bool vis[MAXN];
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1, t; j <= n; ++j)
			std::cin >> t, P[i][j] = t / 100.;
	for (int i = 1; i < n; ++i)
		dis[i] = 1e100, E[i] = prod[i] = 1;
	dis[n] = 0;
	for (int i = 1; i <= n; ++i) {
		int at = 0;
		for (int j = 1; j <= n; ++j)
			if (!vis[j] && (!at || dis[at] > dis[j])) at = j;
		vis[at] = true;
		for (int j = 1; j <= n; ++j) if (!vis[j]) {
			E[j] += dis[at] * prod[j] * P[j][at];
			prod[j] *= 1 - P[j][at];
			dis[j] = E[j] / (1 - prod[j]);
		}
	}
	std::cout << std::fixed << std::setprecision(15) << dis[1] << std::endl;
	return 0;
}