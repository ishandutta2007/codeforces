#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 100005;
int e[maxn][2], fa[maxn];
bool vis[maxn];
vector <int> G[maxn];
void dfs(int u, int rt){
	vis[u] = 1;
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i];
		if (! fa[v] && v != rt)
			fa[v] = u;
		if (! vis[v])
			dfs(v, rt);
	}
}
bool isfa(int f, int u){
	while (u){
		if (u == f)
			return true;
		u = fa[u];
	}
	return false;
}
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++ i){
		int u, v;
		cin >> u >> v;
		e[i][0] = u, e[i][1] = v;
		G[u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i)
		if (! vis[i])
			dfs(i, i);
	bool flag = false;
	for (int i = 1; i <= m; ++ i)
		if (isfa(e[i][1], e[i][0]))
			flag = true;
	if (! flag){
		cout << 1 << endl;
		for (int i = 1; i <= m; ++ i)
			printf("1 ");
	}
	else{
		cout << 2 << endl;
		for (int i = 1; i <= m; ++ i)
			if (isfa(e[i][1], e[i][0]))
				printf("2 ");
			else
				printf("1 ");	
	}
}