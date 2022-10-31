#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,ll>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=5e4+4; const ll INF=1e18; 
pr edges[N]; vector<int> G[N]; int m;
void adde(int u,int v,ll c){
	edges[m++]=mp(v,c),edges[m++]=mp(u,0);
	G[u].pb(m-2),G[v].pb(m-1);
}
int d[N],cur[N];
bool bfs(int s,int t){
	rep(i,0,t) d[i]=t+1,cur[i]=0;
	static int q[N]; int l=1,r=1; q[r]=s,d[s]=0;
	while (l<=r){
		int u=q[l++]; 
		rep0(i,G[u].size()){
			pr e=edges[G[u][i]];
			if (e.se&&d[u]+1<d[e.fi]) d[e.fi]=d[u]+1,q[++r]=e.fi;
		}
	}
	return d[t]!=t+1;
}
ll dfs(int u,ll a,int t){
	if (u==t||!a) return a;
	ll f=0,p;
	for (int& i=cur[u];i<G[u].size();++i){
		pr& e=edges[G[u][i]];
		if (d[e.fi]==d[u]+1&&(p=dfs(e.fi,min(a,e.se),t))){
			f+=p,a-=p,e.se-=p,edges[G[u][i]^1].se+=p;
			if (!a) break;
		}
	}
	return f;
}
ll dinic(int s,int t){
	ll ans=0;
	while (bfs(s,t)) ans+=dfs(s,INF,t); 
	return ans;
}
map<pair<int,int>,int> p;
int main(){
	int n,nd=0; scanf("%d",&n);
	int s=2*n,t=2*n+1; ll sum=0;
	rep(i,1,n){
		int x,y,w; scanf("%d%d%d",&x,&y,&w);
		sum+=w,p[mp(x,y)]=nd,adde(nd,nd+1,w);
		#define link(dx,dy,op) \
			if (p.count(mp(x+dx,y+dy))){ \
				int u=p[mp(x+dx,y+dy)]; \
				if (op) adde(nd+1,u,INF); \
				else adde(u+1,nd,INF); \
			}
		if (x%2&&y%2==0) adde(s,nd,INF);
		else if (x%2&&y%2) adde(nd+1,t,INF);
		link(-1,0,(x%2!=0)^(y%2!=0))
		link(1,0,(x%2!=0)^(y%2!=0))
		if (x%2==0){
			link(0,-1,y%2==0)
			link(0,1,y%2==0)
		}
		nd+=2;
	}
	printf("%lld\n",sum-dinic(s,t));
	return 0;
}