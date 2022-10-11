#include<iostream>
#include<vector>
#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
vector<int>x[1200000], y[1200000]; int n, m, a[1200000], b[1200000], c[1200000], d[1200000], col[1200000], cnt;
void dfs(int pos) {
	if (col[pos] >= 1)return;
	col[pos] = cnt;
	for (int i = 0; i < x[pos].size(); i++)dfs(x[pos][i]);
}
int main() {
	cin >> n >> m; for (int i = 1; i <= n; i++)scanf("%d", &c[i]);
	for (int i = 1; i <= m; i++) { cin >> a[i] >> b[i]; x[a[i]].push_back(b[i]); x[b[i]].push_back(a[i]); }
	for (int i = 1; i <= n; i++) {
		if (col[i] >= 1)continue;
		cnt++; dfs(i);
	}
	for (int i = 1; i <= n; i++)y[col[i]].push_back(i);
	for (int i = 1; i <= cnt; i++) {
		vector<int>U; for (int j = 0; j < y[i].size(); j++)U.push_back(c[y[i][j]]);
		sort(U.begin(), U.end(), greater<int>());
		for (int j = 0; j < U.size(); j++)d[y[i][j]] = U[j];
	}
	for (int i = 1; i <= n; i++) { if (i >= 2)cout << ' '; cout << d[i]; }cout << endl;
	return 0;
}