#include <bits/stdc++.h>

#define MAXN (100010)

int n, m;
int dfn[MAXN], low[MAXN], ncnt;
bool flag, instack[MAXN], vis[MAXN];
std::vector<int> vec[MAXN];
std::vector<int> bid[MAXN];
std::stack<int> stack;

void tarjan(int u){
	dfn[u] = low[u] = ++ ncnt;
	stack.push(u);
	instack[u] = true;
	for(auto v : vec[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		}
		else if(instack[v]){
			low[u] = std::min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		int v;
		do{
			v = stack.top(); stack.pop();
			if(v != u) flag = true;
			instack[v] = false;
		}while(v != u);
	}
}

void dfs(int u){
	vis[u] = true;
	if(!dfn[u]) tarjan(u);
	for(auto v : bid[u]){
		if(vis[v]) continue;
		dfs(v);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++ i){
		int u, v;
		scanf("%d%d", &u, &v);
		vec[u].push_back(v);
		bid[u].push_back(v);
		bid[v].push_back(u);
	}
	int ans = n;
	for(int i = 1; i <= n; ++ i){
		if(vis[i]) continue;
		flag = false;
		dfs(i);
		if(!flag) -- ans;
	}
	printf("%d\n", ans);
    return 0;
}