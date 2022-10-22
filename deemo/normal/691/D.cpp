#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e6 + 10;

int n, m, p[MAXN], ans[MAXN];
vector<int>	adj[MAXN];
int sec[MAXN], gec[MAXN], sz;
bool vis[MAXN];

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	sec[sz] = p[v];
	gec[sz++] = v;
	for (int u:adj[v])
		dfs(u);
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)	scanf("%d", &p[i]);
	while (m--){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (!vis[i]){sz = 0;
			dfs(i);
			sort(sec, sec + sz);
			reverse(sec, sec + sz);
			sort(gec, gec + sz);
			for (int j = 0; j < sz; j++)
				ans[gec[j]] = sec[j];
		}

	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}