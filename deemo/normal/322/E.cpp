#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int max_n = 1e5 + 40;
const int LOG = 25;

int n, sz;
vector<int>	adj[max_n];
bool seen[max_n];
int mark[max_n], cnt[max_n];
int col;

void dfs(int v, int p){
	seen[v] = 1;
	sz++;
	cnt[v] = 1;
	for (int u:adj[v])
		if (u != p && mark[u] == 0 && seen[u] == 0){
			dfs(u, v);
			cnt[v] += cnt[u];
		}	
}

void find(int v, int p){
	bool fl = 0;
	for (int u:adj[v])
		if (u != p && mark[u] == 0)
			if (cnt[u] > sz/2){
				find(u, v);	
				fl = 1;
			}
	if (!fl)
		mark[v] = col;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int i = 0; i < LOG; i++){
		col = i + 'A';
		memset(seen, 0, sizeof(seen));
		for (int j = 0; j < n; j++){
			if (mark[j] || seen[j])	continue;
			sz = 0;
			dfs(j, -1);
			find(j, -1);
		}	
	}
	for (int i = 0; i < n; i++)
		printf("%c ", char(mark[i]));
	printf("\n");
	return 0;
}