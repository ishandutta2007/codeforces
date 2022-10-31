#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector <int> G[1000006];
priority_queue <int> Q;
bool vis[1000006];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++ i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	Q.push(-1);
	while (! Q.empty()){
		int u = -Q.top();
		while (vis[u] && ! Q.empty()){
			Q.pop();
			u = -Q.top();
		}
		if (Q.empty())
			break;
		printf("%d ", u);
		vis[u] = true;
		Q.pop();
		for (int i = 0; i < G[u].size(); ++ i)
			if (! vis[G[u][i]])
				Q.push(-G[u][i]);
	}
}