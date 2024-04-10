#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,m,fa[200004],deg[400004];
pair<int,pii>e[200004];
vector<pii>edg[200004];
int N,pa[400004],sz[400004];
int s[2][400004],val[400004];
vector<int>cc[200004];
int F(int u){
	return fa[u]==u?u:fa[u]=F(fa[u]);
}
int P(int u){
	return pa[u]==u?u:pa[u]=P(pa[u]);
}
vector<int>cht[400004];
void merge(int u,int v,int w){
	if(edg[u].size()<edg[v].size())swap(u,v);
	for(auto i:cc[v])cht[i].clear();
	for(auto [x,y]:edg[v])
		cht[P(x)].push_back(y);
	for(auto i:cc[v]){
		vector<int>ncc;
		int t=sz[i],cur=i;
		for(auto j:cc[u])deg[j]=0;
		for(auto j:cht[i])deg[P(j)]++;
		for(auto j:cc[u]){
			if((ll)t*sz[j]==deg[j])ncc.push_back(j);
			else{
				++N,s[0][N]=cur,s[1][N]=j,sz[N]=sz[cur]+sz[j];
				pa[N]=pa[cur]=pa[j]=N,val[N]=w,cur=N;
			}
		}
		ncc.push_back(cur);
		cc[u]=ncc;
	}
	fa[v]=u;
	for(auto x:edg[v])edg[u].push_back(x);
}
int par[400004][19],ans[200004];
int ue[200004],ve[200004],dep[4000004];
void dfs(int u,int d){
	dep[u]=d;
	for(int i=1;i<19;i++){
		par[u][i]=0;
		if(par[u][i-1])par[u][i]=par[par[u][i-1]][i-1];
	}
	if(u>n){
		par[s[0][u]][0]=u,dfs(s[0][u],d+1);
		par[s[1][u]][0]=u,dfs(s[1][u],d+1);
	}
}
int lca(int u,int v){
	if(dep[v]<dep[u])swap(u,v);
	for(int i=18;~i;i--)if((dep[v]-dep[u])&(1<<i))
		v=par[v][i];
	for(int i=18;~i;i--)if(par[u][i]!=par[v][i])
		u=par[u][i],v=par[v][i];
	return par[u][0];
}
void sol(){
	scanf("%d%d",&n,&m),N=n;
	for(int i=1;i<=n;i++){
		edg[i].clear(),cc[i].clear();
		fa[i]=i,cc[i].push_back(i);
		pa[i]=i,sz[i]=1;
		s[0][i]=s[1][i]=0;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		e[i]={w,{u,v}},ue[i]=u,ve[i]=v;
		edg[u].push_back({u,v}),edg[v].push_back({v,u});
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		auto [u,v]=e[i].se;
		u=F(u),v=F(v);
		if(u==v)continue;
		merge(u,v,e[i].fi);
	}
	par[N][0]=0,dfs(N,0);
	for(int i=1;i<=m;i++)
		ans[i]=val[lca(ue[i],ve[i])];
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);puts("");
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}