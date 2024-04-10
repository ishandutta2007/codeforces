//started reading on 3.36pm
//started coding on 4.13pm
#include <bits/stdc++.h>
using namespace std;

const int N = 220000;
unordered_map<int, bool> H[N];
bitset<N> b;
int ptr, vis[N], cn[N], T, n;
set<int> S;
set<int> :: iterator it;
void dfs(int u) {
	vis[u] = T;
	S.erase(u);
	b[u] = 0;
	cn[T]++;
	for (it = S.begin(); it != S.end(); ) {
		int v = *it;
		if (!H[u][v]) {
			dfs(v);
			it = S.lower_bound(v);
		} else it++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int m; cin >> n >> m;
	for (int i = 1; i <= n; i++) S.insert(i);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		H[u][v] = H[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) ++T, dfs(i);
	cout << T << endl;
	sort(cn + 1, cn + T + 1);
	for (int i = 1; i <= T; i++) cout << cn[i] << " \n"[i == T];
	return 0;
}