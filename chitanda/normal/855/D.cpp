#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 100100;
int n;
int par[maxn];
int ty[maxn];
int fa[maxn][20];
int top0[maxn], top1[maxn];
int dep[maxn];

int find(int x){
	return par[x] == x ? x : par[x] = find(par[x]);
}

void merge(int u, int v){
	par[find(u)] = find(v);
}

int lca(int u, int v){
	if(dep[u] > dep[v]) swap(u, v);
	for(int i = 16; i >= 0; --i)
		if(dep[fa[v][i]] >= dep[u]) v = fa[v][i];
	if(u == v) return u;
	for(int i = 16; i >= 0; --i)
		if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}


int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) par[i] = i;
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", &fa[i][0], ty + i);
		if(fa[i][0] == -1) fa[i][0] = 0;
		dep[i] = dep[fa[i][0]] + 1;
		for(int j = 1; ; ++j)
			if((fa[i][j] = fa[fa[i][j - 1]][j - 1]) == 0) break;
		if(fa[i][0]) merge(fa[i][0], i);
		top0[i] = top1[i] = i;
		if(ty[i] == 0) top0[i] = top0[fa[i][0]];
		else if(ty[i] == 1) top1[i] = top1[fa[i][0]];
	}
	
	int q; 
	scanf("%d", &q);
	while(q--){
		int type, u, v;
		scanf("%d%d%d", &type, &u, &v);
		if(find(u) != find(v) || u == v) { puts("NO"); continue; }
		if(type == 1){
			int c = lca(u, v);
			if(c == u && dep[c] >= dep[top0[v]]) puts("YES");
			else puts("NO");
		}else{
			int c = lca(u, v);
			if(dep[c] >= dep[top0[u]] && dep[c] >= dep[top1[v]] && c != v) puts("YES");
			else puts("NO");
		}
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}