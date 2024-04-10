#include<iostream>
#include<vector>
using namespace std;
int n, a, b, col[200009], rv[200009], rd[200009], G[200009], cnt; vector<int>X[200009];
void dfs(int pos) {
	if (col[pos] >= 1)return;
	col[pos] = cnt; rv[cnt]++;
	for (int i = 0; i < X[pos].size(); i++) {
		if (pos == X[pos][i])G[cnt] = 1;
		dfs(X[pos][i]);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> a >> b; X[a].push_back(b); X[b].push_back(a); }
	for (int i = 1; i <= 2 * n; i++) { if (col[i] == 0) { cnt++; dfs(i); } }
	for (int i = 1; i <= 2 * n; i++)rd[col[i]] += X[i].size();
	for (int i = 1; i <= cnt; i++)rd[i] /= 2;
	long long ret = 1, mod = 1000000007;
	for (int i = 1; i <= cnt; i++) {
		if (rv[i] == rd[i]) {
			if (G[i] == 0)ret *= 2;
		}
		else ret *= rv[i];
		ret %= mod;
	}
	cout << ret << endl;
	return 0;
}