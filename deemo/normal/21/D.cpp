#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 15 + 2;

int n, m, ans, dis[MAXN][MAXN], d[1<<MAXN];
int sec[MAXN], sz;
vector<int>	adj[MAXN];
bool vis[MAXN];

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	for (int u:adj[v])
		dfs(u);
}

int main(){
	cin >> n >> m;
	memset(dis, 63, sizeof(dis));
	for (int i = 0; i < n; i++)	dis[i][i] = 0;

	for (int i = 0; i < m; i++){
		int a, b, c;	cin >> a >> b >> c, a--, b--;
		ans += c;
		dis[a][b] = dis[b][a] = min(dis[a][b], c);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if (m == 0){
		cout << "0\n";
		return 0;
	}

	if (adj[0].empty()){
		cout << "-1\n";
		return 0;
	}

	int g = 0;
	for (int i =0; i < n; i++)
		if (!vis[i] && adj[i].size())
			g++, dfs(i);

	if (g > 1){
		cout << "-1\n";
		return 0;
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	for (int i = 0; i < n; i++)
		if (adj[i].size() & 1)	sec[sz++] = i;

	memset(d, 63, sizeof(d));
	d[0] = 0;
	for (int ms = 1; ms < 1<<sz; ms++){
		int t = __builtin_popcount(ms);
		if (t&1)	continue;
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				if (i^j && ms>>i & 1 && ms>>j & 1)
					d[ms] = min(d[ms], dis[sec[i]][sec[j]] + d[ms^1<<i^1<<j]);
	}
	cout << ans + d[(1<<sz)-1] << "\n";
	return 0;
}