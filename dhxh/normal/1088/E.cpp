#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 3e5 + 5;

int n, m, t;

long long w[maxn];

vector <int> e[maxn];

long long ans;
long long cnt = 0;
long long g[maxn];
long long f[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int addedge(int x, int y){
	e[x].push_back(y);
	e[y].push_back(x);
	
	return 0;
}

long long dfs(int x, int fa){
	int y;
	int i, j;
	long long ret = -1e10;
	
	g[x] = w[x];
	
	for(i=0;i<e[x].size();i++){
		y = e[x][i];
		if(y != fa){
			ret = max(ret, dfs(y, x));
			if(g[y] > 0){
				g[x] += g[y];
			}
		}
	}
	
	return max(g[x], ret);
}

int dfsb(int x, int fa){
	int y;
	int i, j;
	long long ret = -1e10;
	
	f[x] = w[x];
	
	for(i=0;i<e[x].size();i++){
		y = e[x][i];
		if(y != fa){
			dfsb(y, x);
			if(f[y] > 0){
				f[x] += f[y];
			}
		}
	}
	
	if(f[x] == ans){
		cnt++;
		f[x] = 0;
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<=n;i++){
		w[i] = read();
	}
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		addedge(x, y);
	}
	
	ans = dfs(1, -1);
	dfsb(1, -1);
	
	printf("%lld %lld\n", ans * cnt, cnt);
	
	return 0;
}