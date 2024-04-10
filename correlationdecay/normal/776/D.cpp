#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <stack>
#define maxn 300009
using namespace std;
const long long INF = 1e17;
int n, m, r[maxn];
vector<int>G[maxn],sw[maxn];
int dfn[maxn], low[maxn], id[maxn], bcnt, in[maxn], dfs_time;
stack<int>stk;
void tarjan(int u){
	dfn[u] = low[u] = ++dfs_time;
	in[u] = 1;
	stk.push(u);
	for(auto v:G[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(in[v]){
			low[u]= min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]){
		int x;
		bcnt++;
		do{
			x = stk.top();
			id[x] = bcnt;
			in[x] = 0;
			stk.pop();
		}while(x != u);
	}
}
bool check(){
	for(int i = 1; i <= m ;i++){
		if(id[i] == id[i + m])
			return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d" ,&n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &r[i]);
	}
	for(int i = 1;i <= m; i++){
		int num,x;
		scanf("%d", &num);
		for(int j = 0; j < num; j++){
			scanf("%d", &x);
			sw[x].push_back(i);
		}
	}
	for(int i = 1;i <= n; i++){
		int u = sw[i][0];
		int v = sw[i][1];
		//cout << u << " " << v << endl;
		if(r[i] == 1){
			G[u].push_back(v);
			G[v].push_back(u);
			G[u + m].push_back(v + m);
			G[v + m].push_back(u + m);
		}
		else{
			G[u + m].push_back(v);
			G[v + m].push_back(u);
			G[u].push_back(v + m);
			G[v].push_back(u + m);
		}
	}
	for(int i = 1; i <= 2 * m; i++){
		if(!dfn[i])
			tarjan(i);
	}
	if(check())
		puts("YES");
	else
		puts("NO");
	return 0;
	
}