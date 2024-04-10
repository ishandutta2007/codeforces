#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define maxn 2009
using namespace std;
string s1[maxn],s2[maxn];
bool mark[maxn];
vector<int>G[maxn],V[maxn],node[maxn], K[maxn];
int color[maxn];
int n;
int dfn[maxn], low[maxn], in[maxn], id[maxn];
bool vis[maxn];
int bcnt, dfs_time;
stack<int>stk;
void tarjan(int u){
	dfn[u] = low[u] = ++dfs_time;
	stk.push(u);
	in[u] = 1;
	for(auto v: G[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(in[v]){
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		bcnt++;
		int x;
		do{
			x = stk.top();
			stk.pop();
			in[x] = 0;
			id[x] = bcnt;
			node[bcnt].push_back(x);
		}while(x != u);
	}
}
bool sat_2(){
	for(int i = 1; i <= 2 * n; i++){
		if(!dfn[i])
			tarjan(i);
	}
	for(int i = 1; i <= n; i++){
		if(id[i] == id[i + n])
			return 0;
	}
	return 1;
}
void dfs(int u){
	vis[u] = 1;
	for(auto v:G[u]){
		if(!vis[v])
			dfs(v);
	}
}
void topsort(){
	int d[maxn];
	memset(d, 0, sizeof(d));
	queue<int>Q;
	for(int i = 1; i <= bcnt; i++){
		for(auto v : V[i])
			d[v]++;
	}
	for(int i = 1; i <= bcnt; i++){
		if(d[i] == 0)
			Q.push(i);
	}
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		if(color[u] == 0){
			color[u] = 1;
		}
		if(color[u] == 1){
			for(auto x : node[u]){
				if(x > n)
					dfs(id[x - n]);
				else
					dfs(id[x + n]);
			}
		}
		//cout << u << " " << color[u] << endl;
		for(auto v: V[u]){
			d[v]--;
			if(d[v] == 0){
				Q.push(v);
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		string x, y;
		cin >> x >> y;
		for(int j = 0; j < 3; j++){
			s1[i].push_back(x[j]);
		}
		for(int j = 0; j < 2; j++){
			s2[i].push_back(x[j]);
		}
		s2[i].push_back(y[0]);
	}
	for(int i = 1; i <= n ; i++){
		for(int j = i + 1; j <= n; j++){
			if(s1[i] == s1[j]){
				G[i].push_back(i + n);
				G[j].push_back(j + n);
				mark[i] = mark[j] = 1;
			}
			if(s1[i] == s2[j]){
				G[i].push_back(j);
				G[j + n].push_back(i + n);
			}
			if(s2[i] == s1[j]){
				G[i + n].push_back(j + n);
				G[j].push_back(i);
			}
			if(s2[i] == s2[j]){
				G[i + n].push_back(j);
				G[j + n].push_back(i);
			}
		}
	}
	if(!sat_2())
		puts("NO");
	else{
		for(int i = 1; i <= n; i++){
			color[i] = 1;
			memset(vis, 0, sizeof(vis));
			for(int j = 1; j <= i; j++){
				if(color[j] == 1)
					dfs(j);
				else 
					dfs(j + n);
			}
			bool ok = 1;
			for(int j = 1; j <= n; j++){
				if(vis[j] && vis[j + n]){
					ok = 0;
					break;
				}
			}
			if(!ok)
				color[i] = 2;
		}
		memset(vis, 0, sizeof(vis));
		for(int j = 1; j <= n; j++){
			if(color[j] == 1)
				dfs(j);
			else 
				dfs(j + n);
		}
		bool ok = 1;
		for(int j = 1; j <= n; j++){
			if(vis[j] && vis[j + n]){
				ok = 0;
				break;
			}
		}
		if(!ok){
			puts("NO");
		}
		else{
			puts("YES");
			for(int i = 1; i <= n; i++){
				if(color[i] == 1)
					cout << s1[i] << endl;
				else
					cout << s2[i] << endl;
			}
		}
	}
	return 0;
}