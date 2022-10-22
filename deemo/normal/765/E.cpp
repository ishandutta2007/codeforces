#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, sz[MAXN];
bool mark[MAXN];
vector<int> adj[MAXN], vec[MAXN];

void dfs(int v, int p = -1){
	sz[v] = 1;
	for (int u:adj[v])
		if (u^p){
			dfs(u, v);
			if (mark[u]){
				cout << "-1\n";
				exit(0);
			}
			vec[v].push_back(sz[u]);
		}
	sort(vec[v].begin(), vec[v].end());
	vec[v].resize(unique(vec[v].begin(), vec[v].end()) - vec[v].begin());
	for (int x:vec[v]) sz[v] += x;
	if (vec[v].size() > 1)
		mark[v] = 1;
}

pair<int, int> tt(-1, -1);
int par[MAXN];
void go(int v, int p = -1, int de = 0){
	par[v] = p;
	tt = max(tt, {de, v});
	for (int u:adj[v])
		if (u^p)
			go(u, v, de+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (n == 2){
		cout << "1\n";
		return 0;
	}
	go(0);
	int v = tt.S; tt = {-1, -1};
	go(v);
	v = tt.S;
	int temp = tt.F/2;
	while (temp--) v = par[v];
	
	dfs(v);
	if (vec[v].size() > 2){
		cout << "-1\n";
		return 0;
	}
	int ans = sz[v] - 1;
	while (ans % 2 == 0) ans /= 2;
	cout << ans << "\n";
	return 0;
}