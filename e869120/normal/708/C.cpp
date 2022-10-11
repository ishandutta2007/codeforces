#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning(disable: 4996)
vector<int>x[400009], y[400009]; int n, a, b, par[400009], dp[400009], u[400009]; bool used1[400009]; vector<pair<int, int>>z[400009];
void dfs1(int pos) {
	used1[pos] = true;
	for (int i = 0; i < x[pos].size(); i++) {
		if (used1[x[pos][i]] == true)continue;
		par[x[pos][i]] = pos;
		y[pos].push_back(x[pos][i]);
		dfs1(x[pos][i]);
	}
}
int dfs2(int pos) {
	int cnt = 0;
	for (int i = 0; i < y[pos].size(); i++) {
		cnt += dfs2(y[pos][i]);
		dp[pos] = max(dp[pos], dp[y[pos][i]]);
	}
	cnt++;
	if (cnt <= n / 2)dp[pos] = max(dp[pos], cnt);
	u[pos] = cnt;
	return cnt;
}
void dfs3(int pos) {
	if (par[pos] == 0) { z[pos].push_back(make_pair(0, -1)); }
	else {
		for (int i = 0; i < z[par[pos]].size(); i++) {
			if (z[par[pos]][i].second == pos)continue;
			z[pos].push_back(make_pair(z[par[pos]][i].first, par[pos]));
		}
	}
	for (int i = 0; i < y[pos].size(); i++)z[pos].push_back(make_pair(dp[y[pos][i]], y[pos][i]));
	if (n - u[pos] <= n / 2) { z[pos].push_back(make_pair(n - u[pos], par[pos])); }
	sort(z[pos].begin(), z[pos].end(), greater<pair<int, int>>());
	if (z[pos].size() >= 3)z[pos].erase(z[pos].begin() + 2, z[pos].end());
	for (int i = 0; i < y[pos].size(); i++)dfs3(y[pos][i]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) { scanf("%d%d", &a, &b); x[a].push_back(b); x[b].push_back(a); }
	dfs1(1); dfs2(1); dfs3(1);
	for (int i = 1; i <= n; i++) {
		if (i >= 2)cout << " ";
		bool OK = true;
		int G = n - 1;
		for (int j = 0; j < y[i].size(); j++) {
			if (u[y[i][j]] > n / 2) {
				if (u[y[i][j]] - dp[y[i][j]] > n / 2) {
					OK = false;
				}
			}
			G -= u[y[i][j]];
		}
		if (G > n / 2) {
			int maxn = 0;
			for (int j = 0; j < z[par[i]].size(); j++) {
				if (z[par[i]][j].second == i)continue;
				maxn = max(maxn, z[par[i]][j].first);
			}
			if (G - maxn > n / 2) {
				OK = false;
			}
		}
		cout << (int)OK;
	}
	cout << endl;
	return 0;
}