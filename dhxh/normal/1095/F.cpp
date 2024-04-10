#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t, k;

long long a[maxn];

int fa[maxn];
struct ex {
	int x;
	int y;
	long long w;
} e[maxn * 2];

long long read(){
	long long x;
	scanf("%lld", &x);
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
	long long ans = 0;
	int x, y;
	long long minx = 1e18;
	
	n = read();
	m = read();
	
	init();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		if(a[i] < minx){
			minx = a[i];
			x = i;
		}
	}
	
	for(i=1;i<=m;i++){
		e[i].x = read();
		e[i].y = read();
		e[i].w = read();
	}
	
	for(i=1;i<=n;i++){
		e[++m].x = x;
		e[m].y = i;
		e[m].w = a[i] + a[x];
	}
	
	sort(e + 1, e + m + 1, cmp);
	
	for(i=1;i<=m;i++){
		x = e[i].x;
		y = e[i].y;
		
		if(find(x) != find(y)){
			ans += e[i].w;
			join(x, y);
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}