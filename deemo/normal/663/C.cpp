#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 10;
const int INF = 1e8;

int n, m, ans[MAXN], cc, sec[MAXN];
bool vis[MAXN], col[MAXN];
vector<pair<int, bool>>	adj[MAXN];

int dfs(int v, bool t, bool res){
	vis[v] = 1;
	col[v] = t;
	sec[cc++] = v;
	int ret = t;
	for (auto e:adj[v]){
		int u = e.first;	bool c = e.second;
		if (vis[u]){
			if (col[v] ^ col[u] ^ res != c)	ret = INF;
			continue;
		}
		ret = min(INF, ret + dfs(u, c^t^res, res));
		if (ret >= INF)	return ret;
	}
	return ret;
}

int solve(bool type){
	int sz = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			cc = 0;
			int t = dfs(i, 0, type);
			for (int j = 0; j < cc; j++){
				if (col[sec[j]])	ans[sz++] = sec[j];
				vis[sec[j]] = 0;
			}
			cc = 0;
			int temp = dfs(i, 1, type);
			if (min(t, temp) >= INF)	return INF;
			if (t > temp){
				sz -= t;
				for (int j = 0; j < cc; j++)
					if (col[sec[j]])	ans[sz++] = sec[j];
			}
		}
	return sz;
}

int main(){
	scanf("%d %d", &n, &m);
	while (m--){
		int a, b; char c;	scanf("%d %d %c", &a, &b, &c), a--, b--;
		bool t = (c == 'R');
		adj[a].push_back({b, t});
		adj[b].push_back({a, t});
	}
	pair<int, int>	mn(INF, -1);
	for (int i = 0; i < 2; i++)
		mn = min(mn, {solve(i), i});
	if (mn.first == INF){
		printf("-1\n");
		return 0;
	}

	solve(mn.second);
	printf("%d\n", mn.first);
	for (int i = 0; i < mn.first; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");
	return 0;
}