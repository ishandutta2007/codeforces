#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

long long a[maxn];

struct graph {
	vector <int> e[maxn];
	vector <long long> w[maxn];
	long long dis[maxn];
	int f[maxn];
	bool vis[maxn];
	priority_queue <pair <long long, int> > q;
	
	int addedge(int x, int y, long long ww){
		e[x].push_back(y);
		e[y].push_back(x);
		w[x].push_back(ww);
		w[y].push_back(ww);
	}
	
	int getdis(){
		int x, y;
		int i, j;
		
		for(i=1;i<=n;i++){
			dis[i] = a[i];
			q.push(make_pair(-a[i], i));
		}
		
		while(!q.empty()){
			x = q.top().second;
			q.pop();
			
			if(vis[x]){
				continue;
			}
			
			vis[x] = true;
			
			for(i=0;i<e[x].size();i++){
				y = e[x][i];
				
				if(dis[y] > dis[x] + w[x][i] * 2){
					dis[y] = dis[x] + w[x][i] * 2;
					q.push(make_pair(-dis[y], y));
				}
			}
		}
		
		return 0;
	}
};

graph g;

long long read(){
	long long x;
	scanf("%lld", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	long long w;
	
	n = read();
	m = read();
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		w = read();
		g.addedge(x, y, w);
	}
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	g.getdis();
	
	for(i=1;i<=n;i++){
		printf("%lld ", g.dis[i]);
	}
	printf("\n");
	
	return 0;
}