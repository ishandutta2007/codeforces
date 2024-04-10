#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, from[MAXN], to[MAXN], c[MAXN], hld[MAXN];
vector<int>	adj[MAXN];
vector<int>	ans;

void dfs(int v, int p = -1, int t = 0){
	hld[v] = 0;
	for (int e:adj[v])
		if (e^p){
			int u = from[e]^to[e]^v;
			dfs(u, e, c[e] - 1);
			hld[v] += hld[u];
		}
	
	if (!hld[v] && t)	ans.push_back(v + 1);
	hld[v] += t;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		scanf("%d %d %d", &from[i], &to[i], &c[i]), from[i]--, to[i]--;
		adj[from[i]].push_back(i);
		adj[to[i]].push_back(i);
	}
	dfs(0);
	printf("%d\n", (int)ans.size());
	for (auto v:ans)
		printf("%d ", v);
	printf("\n");
	return 0;
}