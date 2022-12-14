#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;
int n, Q, h[N], p[N * 2], w[N * 2], deg[N], n1[N * 2], ee, root, st[N], top, tag[N];
ll d[N], g[N], mx[N], mx2[N], L;

void ae(int x, int y, int z){
	p[ee] = y; n1[ee] = h[x]; w[ee] = z; h[x] = ee ++;
}

void dfs(int u, int fa){
	mx[u] = d[u];
	mx2[u] = -1e12;
	for(int i = h[u];~i;i = n1[i]) if(p[i] != fa){
		d[p[i]] = d[u] + w[i];
		dfs(p[i], u);
		if(mx[p[i]] > mx[u]) mx2[u] = mx[u], mx[u] = mx[p[i]];
		else if(mx[p[i]] == mx[u]) mx2[u] = mx[p[i]];
		else if(mx[p[i]] > mx2[u]) mx2[u] = mx[p[i]];
	}
}

void dfs2(int u, int fa){
	for(int i = h[u];~i;i = n1[i]) if(p[i] != fa){
		ll t;
		if(mx[p[i]] == mx[u]) t = mx2[u]; else t = mx[u];
		g[p[i]] = max(g[u] + w[i], t - d[u] + w[i]);
		dfs2(p[i], u);
	}
}

void dfs3(int u, int fa){
	st[++ top] = u;
	int l = 1, r = top, mid;
	while(l <= r) if(g[st[mid = (l + r) >> 1]] + L < g[u]) l = mid + 1; else r = mid - 1;
	tag[st[r]] --;
	tag[u] ++;
	for(int i = h[u];~i;i = n1[i]) if(p[i] != fa) dfs3(p[i], u);
	top --;
}

void dfs4(int u, int fa){
	for(int i = h[u];~i;i = n1[i]) if(p[i] != fa){
		dfs4(p[i], u);
		tag[u] += tag[p[i]];
	}
}

int main(){
	scanf("%d", &n);
	int x, y, z;
	memset(h, -1, sizeof(h));
	for(int i = 1;i < n;i ++){
		scanf("%d%d%d", &x, &y, &z);
		ae(x, y, z);
		ae(y, x, z);
		deg[x] ++;
		deg[y] ++;
	}
	root = 1;
	for(int i = 1;i <= n;i ++) if(deg[i] > 1){ root = i; break;}
	dfs(root, 0);
	dfs2(root, 0);
	for(int i = 1;i <= n;i ++) g[i] = max(g[i], mx[i] - d[i]);
	for(int i = 1;i <= n;i ++) if(g[root] > g[i]) root = i;
	scanf("%d", &Q);
	while(Q --){
		cin >> L;
		memset(tag, 0, sizeof(tag));
		dfs3(root, 0);
		dfs4(root, 0);
		int ans = 0;
		for(int i = 1;i <= n;i ++) ans = max(ans, tag[i]);
		printf("%d\n", ans);
	}
	return 0;
}