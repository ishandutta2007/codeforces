#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long 
using namespace std;
const int N=1e6+6;
int c[N],dfn[N],fa[N],s[N],dc; vector<int> G[N],v[N];
int que(int i,int l,int r){
	return upper_bound(v[i].begin(),v[i].end(),r)-lower_bound(v[i].begin(),v[i].end(),l); 
}
void dfs1(int u,int f){
	dfn[u]=++dc,s[u]=1,fa[u]=f;
	rep0(i,G[u].size()){
		int v=G[u][i]; if (v!=f) dfs1(v,u),s[u]+=s[v];
	}
}
int b[N],ans[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&c[i]),b[i]=c[i];
	sort(b+1,b+1+n); int m=unique(b+1,b+1+n)-b-1;
	rep(i,1,n) c[i]=lower_bound(b+1,b+1+m,c[i])-b;
	rep(i,1,n-1){
		int u,v; scanf("%d%d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs1(1,0); 
	rep(i,1,n) v[c[i]].push_back(dfn[i]);
	rep(i,1,m) sort(v[i].begin(),v[i].end());
	rep(i,1,n){
		int x=que(c[i],dfn[i],dfn[i]+s[i]-1);
		if (x<v[c[i]].size()) ++ans[dfn[i]],--ans[dfn[i]+s[i]];
		rep0(j,G[i].size()){
			int v=G[i][j]; if (v==fa[i]) continue;
			x=que(c[i],dfn[v],dfn[v]+s[v]-1);
			if (x) ++ans[1],--ans[dfn[v]],++ans[dfn[v]+s[v]];
		}
	}
	int t=0; rep(i,1,n) t+=(ans[i]+=ans[i-1])==0;
	printf("%d\n",t);
	return 0;
}