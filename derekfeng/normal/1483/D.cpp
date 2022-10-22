#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
#define mkp make_pair
#define fi first
#define se second
const ll INF=1e18;
int n,m,q;
ll dis[603],dsi[603];
bool vis[603];
vector<pii>g[603],qry[603];
int res;
bool ans[603][603];
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(mkp(v,w)),g[v].push_back(mkp(u,w));  
	}
	scanf("%d",&q);
	while(q--){
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		qry[u].push_back(mkp(v,l));
	}
	for(int s=1;s<=n;s++){
		fill(dis+1,dis+n+1,INF);
		memset(vis,0,sizeof(vis));
		dis[s]=0;
		while(1){
			pli u=mkp(INF,0);
			for(int i=1;i<=n;i++)if(!vis[i])u=min(u,mkp(dis[i],i));
			if(u.fi<INF){
				ll w=u.fi;int x=u.se;
				vis[x]=1;
				for(auto y:g[x])if(dis[y.fi]>w+y.se)dis[y.fi]=w+y.se;
			}else break;
		}
		memset(dsi,-1,sizeof(dsi));
		memset(vis,0,sizeof(vis));
		for(auto x:qry[s])if(dis[x.fi]<=x.se)dsi[x.fi]=x.se;
		while(1){
			pli u=mkp(0,0);
			for(int i=1;i<=n;i++)if(!vis[i])u=max(u,mkp(dsi[i],i));
			if(u.fi>0){
				ll w=u.fi;int x=u.se;
				vis[x]=1;
				for(auto y:g[x])if(dsi[y.fi]<w-y.se)dsi[y.fi]=w-y.se;
			}else break;
		}
		for(int i=1;i<=n;i++)
			for(auto y:g[i])if(dis[i]+y.se<=dsi[y.fi])
				ans[i][y.fi]=ans[y.fi][i]=1;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(ans[i][j])res++;
	printf("%d",res/2);
}