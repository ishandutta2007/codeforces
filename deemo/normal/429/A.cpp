#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, ans[MAXN], sz;
bool f[MAXN], g[MAXN];
vector<int>	adj[MAXN];

void dfs(int v, int p = -1, bool c = 0, bool d = 0){
	f[v] ^= c;
	if (f[v]^g[v]){
		c = !c;
		ans[sz++] = v + 1;
	}
	
	for (int u:adj[v])
		if (u^p)
			dfs(u, v, d, c);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &f[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &g[i]);
	dfs(0);
	printf("%d\n", sz);
	for (int i = 0; i < sz; i++)
		printf("%d\n", ans[i]);
	return 0;
}