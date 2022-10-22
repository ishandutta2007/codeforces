#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,m,fa[300004],f[300004],g[300004];
ll dis[300004];
vector<pii>tr[300004];
bool vis[300004];
int N,a[300004];
void dfs(int u){
	for(auto v:tr[u])if(v.fi!=fa[u]){
		fa[v.fi]=u,f[v.fi]=v.se;
		dis[v.fi]=dis[u]+v.se;
		dfs(v.fi);
	}
}
void got(int u){
	vis[u]=1;
	if(fa[u]>0)got(fa[u]);
	a[++N]=u;
}
int getsz(int u){
	int num=0;
	for(auto v:tr[u])if(!vis[v.fi]){
		vis[v.fi]=1;
		num+=getsz(v.fi)+1;
	}
	return num;
}
int getlg(int u){
	int num=0;
	for(auto v:tr[u])if(!vis[v.fi]){
		num=v.se;
		vis[v.fi]=1;
	}
	return num;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		tr[u].push_back({v,w});
		tr[v].push_back({u,w});
	}
	dfs(1);
	got(n);
	bool ok=0;
	for(int i=1;i<=N&&!ok;i++)ok|=(getsz(a[i])>1);
	if(ok){
		while(m--)printf("%lld\n",dis[n]);
		return 0;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=N;i++)vis[a[i]]=1;
	for(int i=1;i<=N;i++)g[i]=getlg(a[i]);
	ll F=-1e18,G=-1e18,MX=-1e18;
	for(int i=N-1;i;i--){
		F=max(F,G);
		if(g[i+1]>0)F=max(F,(ll)g[i+1]);
		F-=f[a[i+1]];
		G=max(G,0ll);
		G-=f[a[i+1]];
		if(g[i]>0)MX=max(MX,G+g[i]);
		MX=max(MX,F+g[i]);
	}
	while(m--){
		int x;scanf("%d",&x);
		printf("%lld\n",dis[n]+min(0ll,MX+x));
	}
}