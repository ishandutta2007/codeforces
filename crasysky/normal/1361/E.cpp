#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<db,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
using namespace std;
const int N=1e6+6; mt19937 rnd(0);
int dfn[N],low[N],id[N],vis[N],dc,cnt; vector<int> G[N];
bool dfs1(int u){
	dfn[u]=low[u]=++dc,id[dc]=u,vis[u]=-1,++cnt;
	rep0(i,G[u].size()){
		int v=G[u][i];
		if (!dfn[v]){
			if (dfs1(v)) return true; 
			low[u]=min(low[u],low[v]);
		}
		else if (vis[v]==-1) low[u]=min(low[u],dfn[v]);
		else return true;
	}
	vis[u]=1; return false;
}
int tg[N];
void dfs2(int u){
	rep0(i,G[u].size()){
		int v=G[u][i]; if (dfn[v]>dfn[u]) dfs2(v),tg[u]+=tg[v];
	}
}
int k,ok[N];
void solve(int u){
	if (ok[u]) ++k;
	rep0(i,G[u].size()){
		int v=G[u][i];
		if (dfn[v]>dfn[u]){
			if (tg[v]>=2) ok[v]=false,solve(v);
			else if (!tg[v]) continue;
			else ok[v]=ok[id[low[v]]],solve(v);
		}
	}
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; scanf("%d%d",&n,&m);
		rep(i,1,n) G[i].clear(),tg[i]=0;
		rep(i,1,m){
			int u,v; scanf("%d%d",&u,&v); G[u].pb(v);
		}
		int rt=0;
		rep(t,1,100){
			int u=rnd()%n+1;
			rep(i,1,n) dfn[i]=0; dc=cnt=0;
			if (!dfs1(u)&&cnt==n){ rt=u; break; }
		}
		rep(u,1,n)
			rep0(i,G[u].size())
				if (dfn[G[u][i]]<dfn[u]) ++tg[u],--tg[G[u][i]];
		k=0; dfs2(rt),ok[rt]=true,solve(rt);
		if (!rt||5*k<n) puts("-1");
		else{
			rep(i,1,n) if (ok[i]) printf("%d ",i); putchar('\n');
		}
	}
	return 0;
}