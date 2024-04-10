#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, m, s, cnt, a[N], b[N], f[N], fa[N], dfn[N];
vector<int> e[N], ans[3];
void solve(vector<int> &a, int x, int y){ while(y!=fa[x]) a.push_back(y), y=fa[y];}
void work(int x, int y){
	a[++s]=x, b[s]=y;
	int l=0, r=0;
	while(y!=x) if(f[y] && (!l || f[y]==f[l])) r=fa[y], l=l?l:y, y=fa[y];
	else f[y]=s, y=fa[y];
	if(l){
		puts("YES");
		solve(ans[0], r, l), reverse(ans[0].begin(), ans[0].end());
		solve(ans[1], a[f[l]], r), solve(ans[1], l, b[f[l]]);
		solve(ans[2], a[s], r), solve(ans[2], l, b[s]);
		for(int i=0; i<3; ++i, puts("")){
			printf("%d", (int)ans[i].size());
			for(int j:ans[i]) printf(" %d", j);
		}
		exit(0);
	}
}
void dfs(int u){
	dfn[u]=++cnt;
	for(int v:e[u]) if(v!=fa[u]){
		if(!dfn[v]) fa[v]=u, dfs(v); else if(dfn[v]<dfn[u]) work(v, u);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1, x, y; i<=m; ++i)
		scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x);
	for(int i=1; i<=n; ++i) if(!dfn[i]) dfs(i);
	puts("NO");
	return 0;
}