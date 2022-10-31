#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define fi first
#define se second
using namespace std;
const int N=2e3+3,INF=1e9;
int a[N]; vector<int> G[N],p[N];
void dfs(int u){
	rep0(i,G[u].size()){
		int v=G[u][i]; dfs(v);
		rep0(j,p[v].size()) p[u].push_back(p[v][j]);
	}
	if (a[u]>p[u].size()){ puts("NO"); exit(0); }
	if (!p[u].size()){ p[u].push_back(u); return; }
	int x=p[u][p[u].size()-1]; p[u].push_back(x);
	per(i,p[u].size()-1,a[u]+1) p[u][i]=p[u][i-1];
	p[u][a[u]]=u;
}
int ans[N];
int main(){
	int n,rt=0; scanf("%d",&n);
	rep(i,1,n){
		int f; scanf("%d%d",&f,&a[i]);
		if (f) G[f].push_back(i); else rt=i;
	}
	dfs(rt); rep0(i,p[rt].size()) ans[p[rt][i]]=i+1;
	puts("YES"); rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}