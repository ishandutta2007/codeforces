#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<int>x[120000]; int n, m, a, b, cnt, col[120000], G[120000], H[120000];
void dfs(int pos) {
	if (col[pos] != 0)return;
	col[pos] = cnt; G[cnt]++;
	for (int i = 0; i < x[pos].size(); i++)dfs(x[pos][i]);
}
int main() {
	cin >> n >> m; for (int i = 0; i < m; i++) { cin >> a >> b; x[a].push_back(b); x[b].push_back(a); }
	for (int i = 1; i <= n; i++) { if (col[i] != 0)continue; cnt++; dfs(i); }
	for (int i = 1; i <= n; i++) { H[col[i]] += x[i].size(); }
	int V = cnt;
	for (int i = 1; i <= V; i++) { H[i] /= 2; if (G[i] - 1 != H[i])cnt--; }
	cout << cnt << endl;
	return 0;
}