#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 4e5 + 5;

int n, m, t;

vector <int> e[maxn];
int dfn[maxn];
int low[maxn];
bool vis[maxn];
stack <int> s;
int cnt = 0;

int ccnt = 0;
int color[maxn];
int size[maxn];
int st;

long long w[maxn];
long long f[maxn];
long long g[maxn][2];
long long h[maxn];
vector <int> edge[maxn];

int dfs(int x, int fr){
	int y;
	
	vis[x] = true;
	s.push(x);
	dfn[x] = low[x] = ++cnt;
	
	for(auto y : e[x]){
		if(y == fr)continue;
		if(!dfn[y]){
			dfs(y, x);
			low[x] = min(low[x], low[y]);
		}else if(vis[y]){
			low[x] = min(low[x], low[y]);
		}
	}
	
	if(dfn[x] == low[x]){
		size[++ccnt] = 1;
        color[x] = ccnt;
        vis[x] = false;
        while(s.top() != x){
            size[ccnt]++;
			color[s.top()] = ccnt;
			vis[s.top()] = false;
			s.pop();
		}
		s.pop();
	}
	
	return 0;
}

int dfsb(int x, int fr){
	int y;
	long long maxx = 0;
	int sum = 0;
	h[x] = !(size[x] == 1 and fr != -1);
	
	if(edge[x].size() == 1 and size[x] == 1 and fr != -1){
		g[x][1] = f[x];
		g[x][0] = 0;
		return 0;
	}
	
	g[x][0] = 0;
	g[x][1] = f[x];
	
	for(auto y : edge[x]){
		if(y == fr)continue;
		sum++;
		dfsb(y, x);
		if(h[y])h[x] = true;
		g[x][0] += g[y][0];
		maxx = max(maxx, g[y][1] - g[y][0]);
	}
	
	g[x][1] = g[x][0] + f[x] + maxx;
	if(h[x])g[x][0] += f[x];
	
	return 0;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	long long sum = 0;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		w[i] = read();
		sum += w[i];
	}
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	st = read();
	
	dfs(st, -1);
	
	for(i=1;i<=n;i++){
		f[color[i]] += w[i];
	}
	
	for(i=1;i<=n;i++){
		for(auto x : e[i]){
			if(color[x] == color[i])continue;
			edge[color[x]].push_back(color[i]);
		}
	}
	
	dfsb(color[st], -1);
	
	long long ans = max(g[color[st]][0], g[color[st]][1]);
	
	printf("%lld\n", ans);
	
	return 0;
}