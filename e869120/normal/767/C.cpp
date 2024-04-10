#include<iostream>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
vector<pair<int, int>>x[1000009]; int n, a, b, s = 0, u = 0, par[1000009], t[1000009], dp[1000009], ret[1000009]; bool used[1000009]; vector<int>ans;
int dfs(int pos) {
	used[pos] = true;
	for (int i = 0; i < x[pos].size(); i++) {
		if (used[x[pos][i].first] == true)continue;
		par[x[pos][i].first] = x[pos][i].second;
		dp[pos] += dfs(x[pos][i].first);
	}
	dp[pos] += t[pos];
	return dp[pos];
}
int score(int pos) {
	used[pos] = false;
	for (int i = 0; i < x[pos].size(); i++) {
		if (used[x[pos][i].first] == false)continue;
		ret[pos] += score(x[pos][i].first);
	}
	if (dp[pos] == (ret[pos] + 1)*u) { ans.push_back(par[pos]); ret[pos]++; }
	return ret[pos];
}
int main() {
	cin >> n; int root = 0;
	for (int i = 1; i <= n; i++) { scanf("%d%d", &a, &t[i]); s += t[i]; if (a == 0)root = i; if (a >= 1) { x[i].push_back(make_pair(a, i)); x[a].push_back(make_pair(i, i)); } }
	if (s % 3 != 0) { cout << "-1" << endl; return 0; }
	u = s / 3; dfs(root); score(root);
	if (ans.size() < 3)cout << "-1" << endl;
	else { cout << ans[0] << " " << ans[1] << endl; }
	return 0;
}