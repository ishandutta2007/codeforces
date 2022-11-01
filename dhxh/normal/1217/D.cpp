#include <bits/stdc++.h>
const int maxn = 1e5;
using namespace std;

int n, m;

struct ex {
	int x;
	int y;
	int z;
};

vector <ex> edge;

vector <pair<int,int> > e[maxn];

int color[maxn];
int vis[maxn];
int id;
void dfs(int v,int sign) {
	vis[v] = sign;
	for(auto y : e[v]) {
		int to = y.first;
		int num = y.second;
		if(color[num] == 1) continue;
		if(vis[to] == sign) {
			color[num] = 1;
			id = 1;
		}
		else if(!vis[to]) dfs(to,sign);
	}
	vis[v] = -sign;
	return;
}
int main(){
	int i, j;
	scanf("%d%d",&n,&m);
	for(int i = 1,x,y;i <= m;i++) {
		scanf("%d%d",&x,&y);
		e[x].push_back(make_pair(y,i));
	}
	for(int i = 1;i <= n;i++) {
		if(!vis[i]) {
			dfs(i,i);
		}
	}
	printf("%d\n",id + 1);
	for(int i = 1;i <= m;i++) {
		printf("%d ",color[i] + 1);
	}
	return 0;
}