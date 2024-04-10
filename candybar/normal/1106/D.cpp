#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector <int> adj[maxn],lis;
bool vis[maxn];
void prim(){
	priority_queue <int,vector<int>,greater<int> > que;
	que.push(1);
	vis[1] = true;
	while(!que.empty()){
		int u = que.top(); que.pop();
		lis.push_back(u);
		for(int i=0;i<(int)adj[u].size();i++){
			int v = adj[u][i];
			if(!vis[v]){
				que.push(v);
				vis[v] = true;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	prim();
	for(int i=0;i<n;i++){
		printf("%d%c",lis[i],i == n - 1 ? '\n' : ' ');
	}
	return 0;
}