#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n, m, a, b, col[200000], par[200000]; vector<int>x[200000]; bool used[200000];
void dfs(int pos) {
	if (used[pos] == true)return;
	used[pos] = true;
	int V = 1;
	for (int i = 0; i < x[pos].size(); i++) {
		if (used[x[pos][i]] == false) { par[x[pos][i]] = pos; }
		else { continue; }
		while ((pos >= 1 && col[par[pos]] == V) || col[pos] == V)V++;
		col[x[pos][i]] = V; V++;
	}
	for (int i = 0; i < x[pos].size(); i++)dfs(x[pos][i]);
}
int main() {
	cin >> n; for (int i = 0; i < n - 1; i++) { cin >> a >> b; a--; b--; x[a].push_back(b); x[b].push_back(a); }
	col[0] = 1; par[0] = -1; dfs(0);
	int maxn = 0; for (int i = 0; i < n; i++)maxn = max(maxn, col[i]);
	cout << maxn << endl;
	for (int i = 0; i < n; i++) { if (i)cout << ' '; cout << col[i]; }cout << endl;
	return 0;
}