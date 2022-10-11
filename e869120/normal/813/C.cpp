#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
int n, a, b, c, dist[200001], dist2[200001]; vector<int>x[200009];

void dfs2(int pos, int depth) {
	if (dist[pos] < 1e8)return;
	dist[pos] = depth;
	for (int i = 0; i < x[pos].size(); i++)dfs2(x[pos][i], depth + 1);
}
void dfs1(int pos, int depth) {
	if (dist2[pos] < 1e8)return;
	dist2[pos] = depth;
	for (int i = 0; i < x[pos].size(); i++)dfs1(x[pos][i], depth + 1);
}
int main() {
	cin >> n >> c;
	for (int i = 0; i < n - 1; i++) { scanf("%d%d", &a, &b); x[a].push_back(b); x[b].push_back(a); }
	for (int i = 1; i <= n; i++)dist[i] = 1e9, dist2[i] = 1e9;
	dfs1(c, 0); dfs2(1, 0);
	int maxn = 0; for (int i = 1; i <= n; i++) { if (dist[i] > dist2[i])maxn = max(maxn, dist[i]); }
	cout << maxn * 2 << endl;
	return 0;
}