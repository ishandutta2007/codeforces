#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t, q;

struct ex {
	int x;
	int y;
	long long w;
	
	ex(int xx, int yy, long long ww){
		x = xx;
		y = yy;
		w = ww;
	}
};

struct unionset {
	int fa[maxn];
	
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
};

struct graph {
	vector <int> e[maxn];
	vector <int> w[maxn];
	long long dis[maxn];
	int f[maxn];
	bool vis[maxn];
	priority_queue <pair <long long, int> > q;
	
	int addedge(int x, int y, long long ww){
		e[x].push_back(y);
		e[y].push_back(x);
		w[x].push_back(ww);
		w[y].push_back(ww);
		return 0;
	}
	
	int getdis(){
		int x, y;
		int i, j;
		memset(dis, 0x3f, sizeof(dis));
		
		dis[1] = 0;
    
    	q.push(make_pair(0, 1));
    
    	while(!q.empty()){
    	    x = q.top().second;
    	    q.pop();
    	    
    	    if(vis[x]){
    	        continue;
    	    }
    	    
    	    vis[x] = true;
    	    
    	    for(i=0;i<e[x].size();i++){
    	        y = e[x][i];
    	        
    	        if(dis[y] > dis[x] + w[x][i]){
    	            dis[y] = dis[x] + w[x][i];
    	            f[y] = x;
    	            q.push(make_pair(-dis[y], y));
    	        }
    	    }
		}
		
		return 0;
	}
};

struct tree {
	int root;
	int dep[maxn];
	vector <int> e[maxn];
	vector <long long> w[maxn];
	int fa[maxn][21];
	long long dis[maxn][21];
	
	int addedge(int x, int y, int ww){
		e[x].push_back(y);
		e[y].push_back(x);
		w[x].push_back(ww);
		w[y].push_back(ww);
		return 0;
	}
	
	int dfs(int x, int f){
		int i, j;
		int y;
		
		for(i=0;fa[fa[x][i]][i];i++){
			fa[x][i + 1] = fa[fa[x][i]][i];
			dis[x][i + 1] = dis[x][i] + dis[fa[x][i]][i];
		}
		
		for(i=0;i<e[x].size();i++){
			y = e[x][i];
			if(y != f){
				fa[y][0] = x;
				dis[y][0] = w[x][i];
				dep[y] = dep[x] + 1;
				dfs(y, x);
			}
		}
		
		return 0;
	}
	
	long long getdis(int x, int y){
		int i, j;
		long long ret = 0;
		if(dep[y] > dep[x]){
			swap(x, y);
		}
		
		if(dep[x] > dep[y]){
			for(i=20;i>=0;i--){
				if(dep[x] - (1 << i) >= dep[y]){
					ret += dis[x][i];
					x = fa[x][i];
				}
			}
		}
		
		if(x == y){
			return ret;
		}
		
		for(i=20;i>=0;i--){
			if(fa[x][i] != fa[y][i]){
				ret += dis[x][i];
				ret += dis[y][i];
				x = fa[x][i];
				y = fa[y][i];
			}
		}
		
		ret += dis[x][0];
		ret += dis[y][0];
		
		return ret;
	}
	
	int init(){
		dep[root] = 1;
		dfs(root, -1);
		
		return 0;
	}
};

graph g;
tree f;
unionset s;

struct shortpath {
	int st;
	long long dis[maxn];
	int f[maxn];
	bool vis[maxn];
	priority_queue <pair <long long, int> > q;
	
	int getdis(){
		int x, y;
		int i, j;
		memset(dis, 0x3f, sizeof(dis));
		
		dis[st] = 0;
    
    	q.push(make_pair(0, st));
    
    	while(!q.empty()){
    	    x = q.top().second;
    	    q.pop();
    	    
    	    if(vis[x]){
    	        continue;
    	    }
    	    
    	    vis[x] = true;
    	    
    	    for(i=0;i<g.e[x].size();i++){
    	        y = g.e[x][i];
    	        
    	        if(dis[y] > dis[x] + g.w[x][i]){
    	            dis[y] = dis[x] + g.w[x][i];
    	            f[y] = x;
    	            q.push(make_pair(-dis[y], y));
    	        }
    	    }
		}
		
		return 0;
	}
};

shortpath sp[55];
int spc = 0;

vector <ex> edge;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y, w;
	
	n = read();
	m = read();
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		w = read();
		g.addedge(x, y, w);
		edge.push_back(ex(x, y, w));
	}
	
	s.init();
	
	for(i=1;i<=m;i++){
		if(s.find(edge[i - 1].x) == s.find(edge[i - 1].y)){
			spc++;
			sp[spc].st = edge[i - 1].x;
			sp[spc].getdis();
			spc++;
			sp[spc].st = edge[i - 1].y;
			sp[spc].getdis();
		}else{
			f.addedge(edge[i - 1].x, edge[i - 1].y, edge[i - 1].w);
			s.join(edge[i - 1].x, edge[i - 1].y);
		}
	}
	
	f.root = 1;
	f.init();
	
	q = read();
	
	while(q--){
		x = read();
		y = read();
		
		long long ans = f.getdis(x, y);
		
		for(i=1;i<=spc;i++){
			ans = min(ans, sp[i].dis[x] + sp[i].dis[y]);
		}
		
		printf("%I64d\n", ans);
	}
	
	return 0;
}