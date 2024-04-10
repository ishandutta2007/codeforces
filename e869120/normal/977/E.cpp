#include <iostream>
#include <vector>
using namespace std;

int d[200009], n, m, a[200009], b[200009], col[200009], cnts; vector<int>x[200009], P[200009];

void dfs(int pos) {
	if (col[pos] >= 1) return;
	col[pos] = cnts; P[cnts].push_back(pos);
	for (int i = 0; i < x[pos].size(); i++) dfs(x[pos][i]);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
		x[a[i]].push_back(b[i]);
		x[b[i]].push_back(a[i]);
		d[a[i]]++; d[b[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (col[i] == 0) { cnts++; dfs(i); }
	}
	int ans = 0;
	for (int i = 1; i <= cnts; i++) {
		bool OK = true;
		for (int j = 0; j < P[i].size(); j++) { if (d[P[i][j]] != 2) OK = false; }
		if (OK == true) ans++;
	}
	cout << ans << endl;
	return 0;
}