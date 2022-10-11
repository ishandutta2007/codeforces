#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[200009], col[200009], cnt; vector<int>X, x[200009], y[200009];
void dfs(int pos) {
	if (col[pos] >= 1)return;
	col[pos] = cnt; y[cnt].push_back(pos);
	for (int i = 0; i < x[pos].size(); i++)dfs(x[pos][i]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; X.push_back(a[i]); }
	sort(X.begin(), X.end());
	for (int i = 0; i < n; i++) { a[i] = lower_bound(X.begin(), X.end(), a[i]) - X.begin(); }
	for (int i = 0; i < n; i++) { x[i].push_back(a[i]); x[a[i]].push_back(i); }
	for (int i = 0; i < n; i++) {
		if (col[i] == 0) { cnt++; dfs(i); }
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++) {
		cout << y[i].size(); for (int j = 0; j < y[i].size(); j++)cout << " " << y[i][j] + 1; cout << endl;
	}
	return 0;
}