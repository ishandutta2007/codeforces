#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int mx = 300000;
int n;
vector<int> g[mx];
double dp[mx];

void dfs(int v, int pv) {
	if ((v != 0 && g[v].size() == 1) || g[v].size() == 0) {
		dp[v] = 0;
		return;
	}
	dp[v] = 0;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			dfs(v1, v);
			dp[v] += dp[v1];
		}
	}
	if (v == 0)
		dp[v] = dp[v] / (g[v].size()) + 1.0;
	else
		dp[v] = dp[v] / (g[v].size() - 1) + 1.0;
}

int main() {
	int u, v;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d%d", &u, &v);
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	dfs(0, -1);
	printf("%f", dp[0]);
}