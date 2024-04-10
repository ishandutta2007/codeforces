#include<iostream>
#include<vector>
using namespace std;
int n, m, a[100009], c[100009]; vector<int>x[100009], Q; bool used[100009], I[100009], OK;
void dfs(int pos, int pre) {
	for (int i = 0; i < x[pos].size(); i++) {
		if (a[x[pos][i]] == x[pos][i])dfs(x[pos][i], x[pos][i]);
		else {
			if (a[x[pos][i]] != pre)OK = true;
			dfs(x[pos][i], pre);
		}
	}
	if (a[pos] == pos)Q.push_back(pos);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) { int p, q; cin >> p >> q; c[q] = p; x[p].push_back(q); }
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) { dfs(i, a[i]); }
	}
	if (OK == true) { cout << "-1" << endl; return 0; }
	cout << Q.size() << endl;
	for (int i = 0; i < Q.size(); i++)cout << Q[i] << endl;
	return 0;
}