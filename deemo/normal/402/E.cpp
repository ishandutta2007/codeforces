#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 2e3 + 10;

int n, cnt, g;
bool vis[MAXN];
vector<int>	adj[MAXN], rev_adj[MAXN], st;

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	for (int u:adj[v])
		dfs(u);
	st.push_back(v);
}	

void kosaraju(int v){
	if (vis[v])	return;
	vis[v] = 1;
	for (int u:rev_adj[v])
		kosaraju(u);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			int x;	scanf("%d", &x);
			if (x)	adj[i].push_back(j), rev_adj[j].push_back(i);
		}

	for (int i = 0; i < n; i++)	dfs(i);
	reverse(st.begin(), st.end());
	memset(vis, 0, sizeof(vis));
	for (int u:st)
		if (!vis[u])
			g++, kosaraju(u);

	if (g == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return	0;
}