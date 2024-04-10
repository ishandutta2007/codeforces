#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
using namespace std;
const int N=1e6+6;
int fa[N],d[N][2],d2[N],a[N],cnt[N],mx[N],ans[N]; 
vector<int> G[N],vec[N];
void dfs1(int u,int f){
	d[u][1]=-1e9;
	rep0(i,G[u].size()){
		int v=G[u][i];
		if (v!=f){
			dfs1(v,u),fa[v]=u;
			if (d[v][0]+1>d[u][0]) d[u][1]=d[u][0],d[u][0]=d[v][0]+1;
			else if (d[v][0]+1>d[u][1]) d[u][1]=d[v][0]+1;
		}
	}
}
void dfs2(int u,int f){
	rep0(i,G[u].size()){
		int v=G[u][i];
		if (v!=f){
			d2[v]=max(d2[u],d[v][0]+1==d[u][0]?d[u][1]:d[u][0])+1;
			dfs2(v,u);
		}
	}
}
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n-1){
		int u,v; scanf("%d%d",&u,&v);
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0),dfs2(1,0);
	rep(u,1,n){
		rep0(i,G[u].size()){
			int v=G[u][i]; if (v!=fa[u]) vec[d[v][0]+1].pb(u);
		}
		if (fa[u]){
			vec[d2[u]].pb(u);
		}
	}
	per(i,n,1){	
		rep0(j,vec[i].size()){
			int u=vec[i][j];
			ans[2*i+1]=max(ans[2*i+1],cnt[u]+1);
		}
		rep0(j,vec[i].size()){
			int u=vec[i][j];
			mx[fa[u]]=max(mx[fa[u]],++cnt[u]);
			ans[2*i]=max(ans[2*i],cnt[u]);
			ans[2*i-1]=max(ans[2*i-1],cnt[u]);
			ans[2*i]=max(ans[2*i],cnt[fa[u]]+cnt[u]-2);
			ans[2*i]=max(ans[2*i],mx[u]+cnt[u]-2);
		}
	}
	per(i,n,1) ans[i]=max(ans[i],ans[i+2]);
	rep(u,1,n) ans[1]=max(ans[1],1+(int)G[u].size());
	rep(i,1,n) printf("%d ",max(ans[i],1));
	return 0;
}