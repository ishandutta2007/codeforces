#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 100 + 2;
const int MAXK = 20 + 6;
const int MOD = 1e9 + 7;

int n, k, d[MAXN][MAXK][MAXN], sec[MAXK][MAXK];
vector<int>	adj[MAXN];

void dfs(int v, int p = -1){
	d[v][0][k+1] = 1;
	d[v][k+2][0] = 1;
	for (int u:adj[v])
		if (u^p){
			dfs(u, v);
			
			memset(sec, 0, sizeof(sec));
			for (int i = 0; i <= k+2; i++)
				for (int j = 0; j <= k+1; j++)
					for (int i2 = 0; i2 <= k+2; i2++)
						for (int j2 = 0; j2 <= k+1; j2++){
							if (i == k + 1 || i2 == k + 1)	continue;
							
							int _i = i, _j = j, _i2 = i2+1, _j2 = j2;
							if (j + i2 + 1 <= k || j == k+1)	_j = -1;
							if (j2 + i + 1 <= k || j2 == k+1)	_j2 = -1;
							else	_j2++;
							if (_j == k+1)	_j = k+2;
							if (_j2 == k+1)	_j2 = k+2;

							int &x = sec[min(_i, _i2)==k+1?k+2:min(_i,_i2)][max(_j2, _j)==-1?k+1:max(_j2, _j)];
							x = (x + 1ll * d[v][i][j] * d[u][i2][j2]) % MOD;
						}
			for (int i = 0; i < MAXK; i++)
				for (int j = 0; j < MAXK; j++)
					d[v][i][j] = 0;

			for (int i = 0; i < MAXK; i++)
				for (int j = 0; j <= k + 1; j++)
					if (i > k+1){
						d[v][k + 2][j] += sec[i][j];
						if (d[v][k + 2][j] >= MOD)
							d[v][k + 2][j] -= MOD;
					}
					else{
						d[v][i][j] += sec[i][j];
						if (d[v][i][j] >= MOD)
							d[v][i][j] -= MOD;
					}
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	int ans = 0;
	for (int i = 0; i <= k; i++){
		ans += d[0][i][k+1];
		if (ans >= MOD)
			ans -= MOD;
	}
	cout << ans << "\n";
	return 0;
}