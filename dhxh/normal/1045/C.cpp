#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t, q;

struct graph {
	vector <int> e[maxn];
	
	int addedge(int x, int y){
		e[x].push_back(y);
		e[y].push_back(x);
		return 0;
	}
	
	int init(){
		int i, j;
		for(i=1;i<=n;i++){
			sort(e[i].begin(), e[i].end());
		}
		return 0;
	}
	
	bool find(int x, int y){
		int l = 0, r = e[x].size() - 1;
		int mid;
		
		while(l < r){
			mid = (l + r) / 2;
			if(e[x][mid] < y){
				l = mid + 1;
			}else{
				r = mid;
			}
		}
		
		if(l >= e[x].size() or e[x][l] != y){
			return false;
		}else{
			return true;
		}
	}
};

struct tree {
	int root;
	int dep[maxn];
	vector <int> e[maxn];
	int fa[maxn][21];
	
	int addedge(int x, int y){
		e[x].push_back(y);
		e[y].push_back(x);
		return 0;
	}
	
	int dfs(int x, int f){
		int i, j;
		int y;
		
		for(i=0;fa[fa[x][i]][i];i++){
			fa[x][i + 1] = fa[fa[x][i]][i];
		}
		
		for(i=0;i<e[x].size();i++){
			y = e[x][i];
			if(y != f){
				fa[y][0] = x;
				dep[y] = dep[x] + 1;
				dfs(y, x);
			}
		}
		
		return 0;
	}
	
	int lca(int x, int y){
		int i, j;
		if(dep[y] > dep[x]){
			swap(x, y);
		}
		
		if(dep[x] > dep[y]){
			for(i=20;i>=0;i--){
				if(dep[x] - (1 << i) >= dep[y]){
					x = fa[x][i];
				}
			}
		}
		
		if(x == y){
			return x;
		}
		
		for(i=20;i>=0;i--){
			if(fa[x][i] != fa[y][i]){
				x = fa[x][i];
				y = fa[y][i];
			}
		}
		
		return fa[x][0];
	}
	
	int getdis(int x, int y){
		return dep[x] + dep[y] - 2 * dep[lca(x, y)];
	}
	
	int init(){
		dep[root] = 1;
		dfs(root, -1);
		
		return 0;
	}
};

graph g;
tree f;
queue <int> que;

int dis[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int build(){
	int x, y;
	int i, j;
	
	x = 1;
	
	dis[x] = 1;
	que.push(x);
	
	while(!que.empty()){
		x = que.front();
		que.pop();
		for(i=0;i<g.e[x].size();i++){
			y = g.e[x][i];
			if(!dis[y]){
				dis[y] = dis[x] + 1;
				f.addedge(x, y);
				que.push(y);
			}
		}
	}
	
	f.root = 1;
	f.init();
	
	return 0;
}

int getans(int x, int y){
	int i, j;
	int ans = 0;
	if(f.dep[y] > f.dep[x]){
		swap(x, y);
	}
	
	if(f.dep[x] > f.dep[y]){
		for(i=20;i>=0;i--){
			if(f.dep[x] - (1 << i) >= f.dep[y]){
				x = f.fa[x][i];
				ans += (1 << i);
			}
		}
	}
	
	if(x == y){
		return ans;
	}
	
	for(i=20;i>=0;i--){
		if(f.fa[x][i] != f.fa[y][i]){
			x = f.fa[x][i];
			y = f.fa[y][i];
			ans += (1 << (i + 1));
		}
	}
	
	if(g.find(x, y)){
		ans += 1;
	}else{
		ans += 2;
	}
	
	return ans;
}

int solve(){
	int i, j;
	int x, y;
	
	build();
	
	while(q--){
		x = read();
		y = read();
		printf("%d\n", getans(x, y));
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	m = read();
	q = read();
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		g.addedge(x, y);
	}
	
	g.init();
	
	solve();
	
	return 0;
}