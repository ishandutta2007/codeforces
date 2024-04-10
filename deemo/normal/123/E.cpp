#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 10;

int n, sz[MAXN];
vector<int>	adj[MAXN];
int x[MAXN], y[MAXN];
ld xx[MAXN], yy[MAXN], gg, ans;

void dfs(int v, int p = -1){
	sz[v] = 1;
	for (int u:adj[v])
		if (u^p)
			dfs(u, v), sz[v] += sz[u];
}

void init(int v, int p = -1, ld c = 0){
	gg += c * yy[v];
	for (int u:adj[v])
		if (u^p)
			init(u, v, c + (sz[v] - 1 - sz[u]) + 1);
}

void go(int v, int p = -1){
	ans += gg * xx[v];
	for (int u:adj[v])
		if (u^p){
			gg += sz[u] * yy[v];
			gg -= ld(n - sz[u]) * yy[u];
			go(u, v);

			gg -= sz[u] * yy[v];
			gg += ld(n - sz[u]) * yy[u];
		}
}

int main(){
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int sx = 0, sy = 0;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i], sx += x[i], sy += y[i];
	for (int i = 0; i < n; i++)
		xx[i] = x[i]/ ld(sx), yy[i] = y[i]/ ld(sy);
	dfs(0);
	init(0);
	go(0);

	cout << ans << endl;
	return 0;
}