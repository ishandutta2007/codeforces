#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t, k;

bool v[maxn];

struct tree {
	int root;
	//int dep[maxn];
	vector <int> e[maxn];
	vector <int> w[maxn];
	bool vis[maxn];
	bool del[maxn];
	int ecnt[maxn];
	//int fa[maxn][21];
	
	int addedge(int x, int y, int ww){
		e[x].push_back(y);
		e[y].push_back(x);
		w[x].push_back(ww);
		w[y].push_back(ww);
		return 0;
	}
	
	/*int dfs(int x, int f){
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
	}*/
	
	int dfs(int x, int f){
		int i, j;
		int y, ww;
		int ret = 0;
		
		for(i=0;i<e[x].size();i++){
			y = e[x][i];
			ww = w[x][i];
			if(y != f and !del[y]){
				ret = max(ret, ww);
				ret = max(ret, dfs(y, x));
			}
		}
		
		return ret;
	}
	
	int getans(){
		int i, j;
		int x, y;
		
		queue <int> q;
		
		for(i=1;i<=n;i++){
			ecnt[i] = e[i].size();
			if(e[i].size() == 1){
				q.push(i);
				vis[i] = true;
			}
		}
		
		while(!q.empty()){
			x = q.front();
			q.pop();
			
			if(v[x]){
				continue;
			}
			
			del[x] = true;
			
			for(i=0;i<e[x].size();i++){
				y = e[x][i];
				if(vis[y]){
					continue;
				}
				
				ecnt[y]--;
				
				if(ecnt[y] == 1){
					vis[y] = true;
					q.push(y);
				}
			}
			
		}
		
		for(i=1;i<=n;i++){
			if(v[i]){
				return dfs(i, -1);
			}
		}
	}
};

int fa[maxn];
struct ex {
	int x;
	int y;
	int w;
} e[maxn];

tree f;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	
	return fa[x];
}

int join(int x, int y){
	int ra = find(x);
	int rb = find(y);
	
	if(ra != rb){
		fa[ra] = rb;
	}
	
	return 0;
}

int init(){
	int i, j;
	for(i=1;i<=n;i++){
		fa[i] = i;
	}
	
	return 0;
}

int cmp(ex x, ex y){
	return x.w < y.w;
}

int main(){
	int i, j;
	int ans;
	int x, y;
	
	n = read();
	m = read();
	k = read();
	
	init();
	
	for(i=1;i<=k;i++){
		v[read()] = true;
	}
	
	for(i=1;i<=m;i++){
		e[i].x = read();
		e[i].y = read();
		e[i].w = read();
	}
	
	sort(e + 1, e + m + 1, cmp);
	
	for(i=1;i<=m;i++){
		x = e[i].x;
		y = e[i].y;
		
		if(find(x) != find(y)){
			f.addedge(x, y, e[i].w);
			join(x, y);
		}
	}
	
	ans = f.getans();
	
	for(i=1;i<=k;i++){
		printf("%d ", ans);
	}
	printf("\n");
	
	return 0;
}