#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;
const int MOD = 998244353;

int n, d[MAXN][2], c[MAXN][2], _d[2], _c[2];
vector<int> adj[MAXN];

void dfs(int v, int p = -1){
	c[v][0] = 1;

	for (int u:adj[v])
		if (u^p){
			dfs(u, v);
			memset(_c, 0, sizeof(_c));
			memset(_d, 0, sizeof(_d));
			for (int ex = 0; ex < 2; ex++)
				for (int a = 0; a < 2; a++)
					for (int b = 0; b < 2; b++){
						if (!ex || a || b){
							_d[a] = (_d[a] + 1ll*d[v][a]*c[u][b]) % MOD;
							_d[a] = (_d[a] + 1ll*d[u][b]*c[v][a]) % MOD;
							_c[a] = (_c[a] + 1ll*c[v][a]*c[u][b]) % MOD;
						}
						else{
							_d[1] = (_d[1] + 1ll*d[v][a]*c[u][b]) % MOD;
							_d[1] = (_d[1] + 1ll*d[u][b]*c[v][a]) % MOD;
							_d[1] = (_d[1] + 1ll*c[v][a]*c[u][b]) % MOD;
							_c[1] = (_c[1] + 1ll*c[v][a]*c[u][b]) % MOD;
						}
					}

			for (int w = 0; w < 2; w++)
				d[v][w] = _d[w], c[v][w] = _c[w];
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	cout << ((d[0][0] + d[0][1]) % MOD)*2%MOD << "\n";
	return 0;
}