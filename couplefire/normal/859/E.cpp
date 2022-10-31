/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5, P = 1e9 + 7;
int n, c, ans = 1, nxt[N], mark[N];
vector<int> adj[N];
 
void dfs1(int u) {
	mark[u] = c;
	if (nxt[u] == u)
		return;
	adj[nxt[u]].push_back(u);
	if (mark[nxt[u]] == c)
		(ans *= 2) %= P;
	if (!mark[nxt[u]])
		dfs1(nxt[u]);
}
 
int dfs2(int u) {
	int res = 1;
	for (auto v: adj[u])
		res += dfs2(v);
	return res;
}
 
int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
	cin >> n;
	for (int i = 0, u; i < n; i++)
		cin >> u >> nxt[u];
 
	for (int u = 0; u <= 2 * n; u++)
		if (!mark[u] && nxt[u])
			c++, dfs1(u);
	for (auto u: adj[0])
		ans = 1LL * ans * dfs2(u) % P;
	cout << ans << endl;
 
	return 0;
}