#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

vector <int> e[maxn];

long long w[maxn];
long long f[maxn];
long long g[maxn];

long long ans;

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

int dfs(int x, int fa){
	w[x] = 1;
	f[x] = 0;
	for(int y : e[x]){
		if(y == fa)continue;
		dfs(y, x);
		w[x] += w[y];
		f[x] += f[y];
	}
	f[x] += w[x];
	
	return 0;
}

int dfsb(int x, int fa, long long sum, long long cnt){
	ans = max(ans, sum + f[x] - w[x] + n);
	for(int y : e[x]){
		if(y == fa)continue;
		dfsb(y, x, sum + f[x] - f[y] + cnt - w[y], cnt + w[x] - w[y]);
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		addedge(x, y);
	}
	
	dfs(1, -1);
	
	ans = f[1];
	
	dfsb(1, -1, 0, 0);
	
	printf("%lld\n", ans);
	
	return 0;
}