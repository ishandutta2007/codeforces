#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, K, x[100009], y[100009], col[200009], I[200009], cnts; vector<int>X, Y, G[200009], L[200009];
long long ret = 1, mod = 1000000007;

void dfs(int pos) {
	if (col[pos] >= 1) return;
	col[pos] = cnts; L[cnts].push_back(pos);
	for (int i = 0; i < G[pos].size(); i++) {
		dfs(G[pos][i]);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		X.push_back(x[i]);
		Y.push_back(y[i]);
	}
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int i = 0; i < n; i++) {
		x[i] = lower_bound(X.begin(), X.end(), x[i]) - X.begin();
		y[i] = lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();
		y[i] += X.size();
		G[x[i]].push_back(y[i]);
		G[y[i]].push_back(x[i]);
	}
	K = X.size() + Y.size();
	for (int i = 0; i < K; i++) {
		if (col[i] >= 1) continue;
		cnts++; dfs(i);
	}
	for (int i = 0; i < n; i++) I[col[x[i]]]++;
	for (int i = 1; i <= cnts; i++) {
		long long V = 1; for (int j = 0; j < L[i].size(); j++) { V *= 2; V %= mod; }
		if (I[i] < L[i].size()) V--; V += mod; V %= mod;
		ret *= V; ret %= mod;
	}
	cout << ret << endl;
	return 0;
}