#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e5 + 10;

int n, m, q;
vector<int> adj[MAXN];

bool vis[MAXN];
void dfs(int v){
	if (vis[v]) return;
	vis[v] = true;
	for (int u:adj[v])
		dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	while (q--){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b+n);
		adj[b+n].push_back(a);
	}
	int ans = -1;
	for (int i = 0; i < n+m; i++)
		if (!vis[i])
			dfs(i), ans++;
	cout << ans << endl;
	return 0;
}