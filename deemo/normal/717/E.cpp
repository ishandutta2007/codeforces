#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n;
bool col[MAXN];
vector<int>	adj[MAXN];

void dfs(int v, int p = -1){
	printf("%d ", v + 1);
	for (int u:adj[v])
		if (u^p){
			col[u] = !col[u];
			dfs(u, v);
			printf("%d ", v + 1);
		}
	if (!col[v]){
		if (~p){
			col[p] = !col[p];
			printf("%d ", p + 1);
			col[v] = !col[v];
			printf("%d ", v + 1);
		}
		else{
			int u = adj[v][0];
			col[u] = !col[u];
			printf("%d ", u + 1);
			col[v] = !col[v];
			printf("%d ", v + 1);
			col[u] = !col[u];
			printf("%d ", u + 1);
		}
	}
		
	if (~p)
		col[p] = !col[p];
}

int main(){
	scanf("%d", &n);
	bool fl = 0;
	for (int i = 0; i < n; i++){
		int temp;	scanf("%d", &temp);
		if (temp == 1)
			col[i] = 1;
		else
			col[i] = 0;
		fl |= col[i];
	}
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (!fl){
		printf("1\n");
		return 0;
	}
	dfs(0);
	printf("\n");
	return 0;
}