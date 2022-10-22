#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n;
vector<int> adj[MAXN], _adj[MAXN];

int dfs(int v, int p = -1){
	int cnt = 0, c = 0;
	for (int u:adj[v])
		if (u^p) {
			c += dfs(u, v);
			cnt++;
		}
	if (!v) return 0;

	if (c & 1)
		_adj[v].push_back(p);
	else
		_adj[p].push_back(v);
	return !(c & 1);
}

int vis[MAXN];
int sec[MAXN], sz;
void go(int v){
	if (vis[v]){
		if (vis[v] == 1){
			cout << "NO\n";
			exit(0);
		}
		return; 
	}

	vis[v] = 1;
	for (int u:_adj[v])
		go(u);
	vis[v] = 2;
	sec[sz++] = v;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		int p; cin >> p;
		adj[p].push_back(i);
		adj[i].push_back(p);
	}
	for (int i = 1; i <= n; i++) _adj[0].push_back(i);
	dfs(0);
	for (int v = 0; v <= n; v++)
		if (!vis[v])
			go(v);
	cout << "YES\n";
	reverse(sec, sec + sz);
	for (int i = 0; i < sz; i++)
		if (sec[i])
			cout << sec[i] << "\n";
	return 0;
}