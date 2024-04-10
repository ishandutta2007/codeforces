#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, h, a[200009], b[200009], t[100009], cmp[100009], num[100009], cnts; bool used[100009];
vector<int>x[100009], y[100009], z[100009], G;

void dfs(int pos) {
	if (used[pos] == true) return;
	used[pos] = true;
	for (int i = 0; i < x[pos].size(); i++) dfs(x[pos][i]);
	G.push_back(pos);
}
void rdfs(int pos) {
	if (cmp[pos] >= 1) return;
	cmp[pos] = cnts; num[cnts]++;
	for (int i = 0; i < y[pos].size(); i++) rdfs(y[pos][i]);
}

int main() {
	cin >> n >> m >> h;
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
		if (t[a[i]] == (t[b[i]] + h - 1) % h) {
			// a -> b
			x[a[i]].push_back(b[i]);
			y[b[i]].push_back(a[i]);
		}
		if (t[b[i]] == (t[a[i]] + h - 1) % h) {
			// b -> a
			x[b[i]].push_back(a[i]);
			y[a[i]].push_back(b[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (used[i] == true) continue;
		dfs(i);
	}
	reverse(G.begin(), G.end());
	for (int i = 0; i < G.size(); i++) {
		if (cmp[G[i]] >= 1) continue;
		cnts++; rdfs(G[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < x[i].size(); j++) {
			if (cmp[i] == cmp[x[i][j]]) continue;
			z[cmp[i]].push_back(cmp[x[i][j]]);
		}
	}
	int minx = (1 << 30), minid = 0;
	for (int i = 1; i <= cnts; i++) {
		if (minx > num[i] && z[i].size() == 0) {
			minx = num[i]; minid = i;
		}
	}
	cout << minx << endl;
	vector<int>Y;
	for (int i = 1; i <= n; i++) {
		if (cmp[i] == minid) Y.push_back(i);
	}
	for (int i = 0; i < Y.size(); i++) {
		if (i) cout << " "; cout << Y[i];
	}
	cout << endl;
	return 0;
}