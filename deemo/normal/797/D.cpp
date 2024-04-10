#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, val[MAXN];
vector<int> adj[MAXN];
bool root[MAXN];
set<int> st;

void dfs(int v, int mx = -1, int mn = 2e9){
	if (mx < val[v] && mn > val[v]) st.insert(val[v]);

	if (adj[v][0] >= 0)
		dfs(adj[v][0], mx, min(mn, val[v]));
	if (adj[v][1] >= 0)
		dfs(adj[v][1], max(mx, val[v]), mn);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int l, r; cin >> val[i] >> l >> r; l--, r--;
		adj[i].push_back(l);
		adj[i].push_back(r);
		if (l >= 0)
			root[l] = 1;
		if (r >= 0)
			root[r] = 1;
	}
	int rt = -1;
	for (int i = 0; i < n; i++)
		if (!root[i]) rt = i;
	dfs(rt);

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (st.find(val[i]) == st.end())
			ans++;
	cout << ans << endl;
	return 0;
}