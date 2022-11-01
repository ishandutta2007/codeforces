#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 3e5 + 5;

long long inf = 0x3f3f3f3f3f3f3f3f;

int n, m, t, k;

vector <pair <int, int> > edge;

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
	int fa[maxn];
	int son[maxn];
	int root = 1;
	
	int addfa(int x, int y){
		fa[y] = x;
		son[x]++;
		return 0;
	}
	
};

graph g;
tree f;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y, w;
	queue <int> q;
	
	n = read();
	m = read();
	k = read();
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		w = read();
		g.addedge(x, y, w);
		edge.push_back(make_pair(x, y));
	}
	
	g.getdis();
	
	for(i=2;i<=n;i++){
		f.addfa(g.f[i], i);
	}
	
	for(i=1;i<=n;i++){
		if(f.son[i] == 0){
			q.push(i);
		}
	}
	
	i = n - 1;
	
	while(i > k){
		i--;
		x = q.front();
		q.pop();
		
		f.son[f.fa[x]]--;
		f.son[x]--;
		
		if(f.son[f.fa[x]] == 0){
			q.push(f.fa[x]);
		}
		f.fa[x] = 0;
	}
	
	printf("%d\n", i);
	
	for(i=0;i<edge.size();i++){
		if(f.fa[edge[i].first] == edge[i].second or f.fa[edge[i].second] == edge[i].first){
			printf("%d ", i + 1);
		}
	}
	
	printf("\n");
	
	return 0;
}