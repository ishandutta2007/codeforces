#include<iostream>
#include<queue>
using namespace std;
int n, m, a[100009], d[100009]; vector<int>x[100009], y[100009], V; bool used[100009], I[100009]; queue<int>Q;
void dfs(int pos) {
	if (used[pos] == true)return;
	used[pos] = true;
	for (int i = 0; i < x[pos].size(); i++)dfs(x[pos][i]);
	V.push_back(pos);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int v; cin >> v;
		for (int j = 0; j < v; j++) { int w; cin >> w; x[i].push_back(w); y[w].push_back(i); }
	}
	for (int i = 1; i <= n; i++)d[i] = x[i].size();
	for (int i = 0; i < m; i++)dfs(a[i]);
	for (int i = 1; i <= n; i++) { if (x[i].size() == 0) { Q.push(i); I[i] = true; } }
	while (!Q.empty()) {
		int to = Q.front(); Q.pop();
		for (int i = 0; i < y[to].size(); i++) {
			if (I[y[to][i]] == true)continue;
			d[y[to][i]]--;
			if (d[y[to][i]] == 0) { I[y[to][i]] = true; Q.push(y[to][i]); }
		}
	}
	bool OK = true;
	for (int i = 1; i <= n; i++) { if (used[i] == true && I[i] == false)OK = false; }
	if (OK == false)cout << "-1" << endl;
	else {
		cout << V.size() << endl; for (int i = 0; i < V.size(); i++) { if (i)cout << ' '; cout << V[i]; }cout << endl;
	}
	return 0;
}