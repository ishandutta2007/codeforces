#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 100010
#define M 800010

int n, m, h[N], p[M], n1[M], ee, st[N * 4], top, d[N], b[N], tot;
bool vis[M];

void ae(int x, int y){
	p[ee] = y; n1[ee] = h[x]; h[x] = ee ++;
}

void dfs(int u){
	for(;~h[u];h[u] = n1[h[u]]){
		int i = h[u], v = p[i];
		if(!vis[i]){
			vis[i] = vis[i ^ 1] = 1;
			dfs(p[i]);
			st[++ top] = u;
		}
		if(h[u] == -1) break;
	}
}

int main(){
//	freopen("data.in", "r", stdin);
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof(h));
	int x, y;
	for(int i = 1;i <= m;i ++){
		scanf("%d%d", &x, &y);
		ae(x, y);
		ae(y, x);
		d[x] ++;
		d[y] ++;
	}
	for(int i = 1;i <= n;i ++) if(d[i] & 1) b[++ tot] = i;
	for(int i = 1;i <= tot / 2;i ++){
		ae(b[i * 2 - 1], b[i * 2]);
		ae(b[i * 2], b[i * 2 - 1]);
		++ m;
	}
	if(tot & 1) ae(b[tot], b[tot]), ++ m;
	if(m & 1) ae(1, 1), ++m;
	dfs(1);
	printf("%d\n", m);
	for(int i = 1;i <= top;i ++){
		int u = st[i], v = (i == top) ? st[1] : st[i + 1];
		if(i & 1) swap(u, v);
		printf("%d %d\n", u, v);
	}
	return 0;
}