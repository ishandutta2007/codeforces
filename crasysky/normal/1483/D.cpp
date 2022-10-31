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
using namespace std;
const int N=602; const ll INF=1e18;
ll G[N][N],f[N][N]; int e[N*N][3];
int main(){
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,n) G[i][j]=i==j?0:INF;
	rep(i,1,m){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		G[u][v]=G[v][u]=min(G[u][v],(ll)w);
		e[i][0]=u,e[i][1]=v,e[i][2]=w;
	}
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	rep(u,1,n) rep(i,1,n) f[u][i]=-INF;
	int q; scanf("%d",&q);
	while (q--){
		int u,v,l; scanf("%d%d%d",&u,&v,&l);
		rep(i,1,n){
			f[i][v]=max(f[i][v],(ll)l-G[i][u]);//<i,t>+dis(t,v)<=l-dis(i,u)
			f[i][u]=max(f[i][u],(ll)l-G[i][v]);
		}
	}
	int ans=0;
	rep(t,1,m){
		int u=e[t][0],v=e[t][1],w=e[t][2]; bool tg=false;
		rep(i,1,n)
			if (G[u][i]+w<=f[v][i]||G[v][i]+w<=f[u][i]){ tg=true; break; }
		ans+=tg;
	}
	printf("%d\n",ans);
 	return 0;
}