#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 2e3 + 20;

int n, in[MAXN][MAXN], t[MAXN];
int res[MAXN][MAXN], depth[MAXN], par[MAXN];
bool mark[MAXN], vis[MAXN][MAXN];
pair<int, int>	sec[MAXN][MAXN];

void dfs(int v, int p = -1, int de = 0){
	mark[v] = 1;
	for (int u = 0; u < n; u++)
		if (!mark[u] && (p == -1 || in[v][u] <= in[p][u]))
			sec[v][t[v]++] = {in[v][u], u};
	sort(sec[v], sec[v] + t[v]);

	depth[v] = de;
	for (int i = 0; i < t[v]; i++){
		int u = sec[v][i].second;
		if (mark[u])	continue;
		par[u] = v;
		dfs(u, v, de + 1);
	}
}

ll get(int a, int b){
	if (depth[a] > depth[b])	swap(a, b);
	if (vis[a][b])	return	res[a][b];
	vis[a][b] = 1;
	if (a == b)	return	res[a][b] = 0;
	return	res[a][b] = get(a, par[b]) + in[b][par[b]];
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			scanf("%d", &in[i][j]);
			if (i == j && in[i][j] != 0){
				printf("NO\n");
				return	0;
			}

			if (i != j && in[i][j] == 0){
				printf("NO\n");
				return	0;
			}

			if (i > j && in[i][j] != in[j][i]){
				printf("NO\n");
				return	0;
			}
		}
	fill(par, par + n, -1);
	dfs(0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (get(i, j) != in[i][j]){
				printf("NO\n");
				return	0;
			}
	printf("YES\n");
	return	0;
}