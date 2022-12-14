#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int mo=1e9+7,N=2e5+10;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

int h[N], p[N * 2], n1[N * 2], ee, f[N], n, g[N];
map<int,int> ch[N];

void ae(int x, int y){
	p[ee] = y; n1[ee] = h[x]; h[x] = ee ++;
}

void dfs(int u, int fa){
	f[u] = 1;
	int cnt = 0, cur = 1;
	for(int i = h[u];~i;i = n1[i]) if(p[i] != fa){
		dfs(p[i], u);
		f[u] = 1LL * f[u] * (f[p[i]] + 1) % mo;
		if((f[p[i]] + 1) % mo == 0) cnt ++; else cur = 1LL * cur * (f[p[i]] + 1) % mo;
	}
	for(int i = h[u];~i;i = n1[i]) if(p[i] != fa){
		if(cnt > 1) ch[u][p[i]] = 0;
		else if((f[p[i]] + 1) % mo == 0) ch[u][p[i]] = cur;
		else ch[u][p[i]] = 1LL * f[u] * pow(f[p[i]] + 1, mo - 2, mo) % mo;
	}
}


void dfs2(int u, int fa){
	for(int i = h[u];~i;i = n1[i]) if(p[i] != fa){
		g[p[i]] = 1LL * (g[u] + 1) * ch[u][p[i]] % mo;
		dfs2(p[i], u);
	}
}

int main(){
	scanf("%d", &n);
	int x;
	memset(h, -1, sizeof(h));
	for(int i = 2;i <= n;i ++) scanf("%d", &x), ae(x, i), ae(i, x);
	dfs(1, 0);
	g[1] = 0;
	dfs2(1, 0);
	for(int i = 1;i <= n;i ++) printf("%d%c", (int)(1LL * f[i] * (g[i] + 1) % mo), (i < n) ? ' ' : '\n');
	return 0;
}