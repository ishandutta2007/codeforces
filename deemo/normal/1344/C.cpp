#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 2e5 + 10;

int n, m;
vector<int> adj[2][MAXN];
int vis[MAXN];

void dfs(int v) {
	if (vis[v]) {
		if (vis[v] == 1) {
			cout << "-1\n";
			exit(0);
		}
		return;
	}
	vis[v] = 1;
	for (int u: adj[0][v])
		dfs(u);
	vis[v] = 2;
}

void dfs(int v, int type) {
	if (vis[v] & (1<<type)) return;
	vis[v] |= 1<<type;

	for (int u: adj[type][v])
		dfs(u, type);
}

int ans[MAXN];
void solve() {
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b, a--, b--;
		adj[0][a].push_back(b);
		adj[1][b].push_back(a);
	}
	for (int v = 0; v < n; v++)
		if (!vis[v])
			dfs(v);

	memset(vis, 0, sizeof(vis));
	for (int v = 0; v < n; v++) {
		if (!vis[v])
			ans[v]  = 1;
		dfs(v, 0);
		dfs(v, 1);
	}
	
	int tot = 0;
	for (int v = 0; v < n; v++)
		tot += ans[v];
	cout << tot << "\n";
	for (int v = 0; v < n; v++)
		cout << (ans[v]? 'A': 'E');
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}