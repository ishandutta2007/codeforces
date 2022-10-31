#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6;
int p[N],h[N],s[N],good[N],bad[N]; 
vector<int> G[N];
bool dfs(int u,int f){
	s[u]=p[u];
	rep0(i,G[u].size()){
		int v=G[u][i];
		if (v!=f){
			if (!dfs(v,u)) return false;
			s[u]+=s[v];
		}
	}
	if (s[u]+h[u]&1) return false;
	if (s[u]<h[u]) return false;
	good[u]=s[u]+h[u]>>1,bad[u]=s[u]-h[u]>>1;
	int sg=0,sb=0;
	rep0(i,G[u].size()){
		int v=G[u][i];
		if (v!=f) sg+=good[v],sb+=bad[v];
	}
	if (good[u]<sg) return false;
	if (bad[u]>sb+p[u]) return false;
	return true;
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; scanf("%d%d",&n,&m);
		rep(i,1,n) G[i].clear();
		rep(i,1,n) scanf("%d",&p[i]);
		rep(i,1,n) scanf("%d",&h[i]);
		rep(i,1,n-1){
			int u,v; scanf("%d%d",&u,&v);
			G[u].push_back(v),G[v].push_back(u);
		}
		puts(dfs(1,0)?"YES":"NO");
	}
	return 0;
}