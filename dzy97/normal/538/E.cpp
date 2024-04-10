#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

const int N = 200010, inf = 0x3f3f3f3f;
int h[N], n1[N * 2], p[N * 2], ee, sz[N], f[N], g[N], n;
void ae(int x, int y){
	p[ee] = y; n1[ee] = h[x]; h[x] = ee ++;
}

void dfs(int u, int fa, int c){
	sz[u] = 0;
	if(c) f[u] = 0, g[u] = inf; else f[u] = inf, g[u] = 0;
	for(int i = h[u];~i;i = n1[i]) if(p[i] != fa){
		dfs(p[i], u, c ^ 1);
		sz[u] += sz[p[i]];
		if(c){
			f[u] += f[p[i]];
			g[u] = min(g[u], sz[p[i]] - g[p[i]]);
		}else{
			f[u] = min(f[u], f[p[i]]);
			g[u] += g[p[i]] - 1;
		}
	}
	if(!sz[u]){
		sz[u] = f[u] = g[u] = 1;
	}else{
		if(c) g[u] = sz[u] - g[u]; else g[u] ++;
	}
}

int main(){
	scanf("%d", &n);
	memset(h, -1, sizeof(h));
	int x, y;
	for(int i = 1;i < n;i ++) scanf("%d%d", &x, &y), ae(x, y), ae(y, x);
	dfs(1, 0, 0);
	printf("%d %d\n", sz[1] - f[1] + 1, sz[1] - g[1] + 1);
	return 0;
}