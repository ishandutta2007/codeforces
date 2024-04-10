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

vector <int > e[maxn];

int a[maxn];

int f[maxn];
int g[maxn];
int h[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x){
	int p = 0, q = 0;
	if(!e[x].size()){
		f[x] = g[x] = 1;
		return 0;
	}
	
	for(int y : e[x]){
		dfs(y);
		g[x] += g[y];
		h[x] += h[y];
		if(!p or f[p] < f[y] or (f[p] == f[y] and h[y] < h[p])){
			p = y;
		}
		if(!q or g[q] - f[q] > g[y] - f[y] or (g[q] - f[q] == g[y] - f[y] and g[y] - h[y] < g[q] - h[q])){
			q = y;
		}
	}
	
	if(a[x]){
		f[x] = g[x] - (g[q] - f[q]);
		h[x] = g[x] - g[q] + h[q];
	}else{
		f[x] = f[p] + h[x] - h[p];
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	for(i=2;i<=n;i++){
		x = read();
		e[x].push_back(i);
	}
	
	dfs(1);
	
	printf("%d\n", f[1]);
	
	return 0;
}