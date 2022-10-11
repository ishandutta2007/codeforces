#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[200009]; vector<int>x[200009]; bool used[200009];
int G[200009]; vector<int>H[200009];
int gcd(int p, int q) {
	if (p == 0 || q == 0)return max(p, q);
	if (q == 0)return p;
	return gcd(q, p%q);
}
void dfs(int pos, int pre) {
	if (used[pos] == true)return;
	used[pos] = true;
	if (pre == -1) { G[pos] = a[pos]; H[pos].push_back(0); }
	else {
		for (int i = 0; i < H[pre].size(); i++)H[pos].push_back(gcd(H[pre][i], a[pos]));
		H[pos].push_back(G[pre]); G[pos] = gcd(G[pre], a[pos]);
		sort(H[pos].begin(), H[pos].end()); H[pos].erase(unique(H[pos].begin(), H[pos].end()), H[pos].end());
	}
	for (int i = 0; i < x[pos].size(); i++)dfs(x[pos][i], pos);
}
int main() {
	cin >> n; for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 0; i < n - 1; i++) { int p, q; cin >> p >> q; x[p].push_back(q); x[q].push_back(p); }
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		if (i >= 2)cout << ' ';
		cout << max(G[i], H[i][H[i].size() - 1]);
	}
	cout << endl;
	return 0;
}