#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, m;
vector<int> adj[MAXN];
bool vis[MAXN];
bool fl;

void dfs(int v){
	if (vis[v]) return;

	vis[v] = true;
	fl |= adj[v].size() != 2;
	for (int u:adj[v])
		dfs(u);
}

bool check(int v){
	fl = false;
	dfs(v);
	return !fl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int v = 0; v < n; v++)
		if (!vis[v])
			ans += check(v);
	cout << ans << endl;
	return 0;
}