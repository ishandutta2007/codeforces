#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N,M;
ll D[300005];
int lnk[300005];
int pre[600005],tgt[600005],cnt;ll val[600005][2];
void add_E(int u,int v,ll w0,ll w1){
	pre[++cnt]=lnk[u],tgt[cnt]=v,lnk[u]=cnt,val[cnt][0]=w0,val[cnt][1]=w1;
}

struct node{
	int u,v;
	ll w[2][2];
	node(){u=v=0;w[0][0]=w[1][0]=w[0][1]=w[1][1]=0;}
	node(int u0){u=v=u0;w[0][0]=w[1][1]=0;w[1][0]=w[0][1]=D[u0];}
	node operator +(const node b)const{
		node c;c.u=u;c.v=b.v;
		c.w[0][0]=min(w[0][0]+b.w[0][0],w[0][1]+b.w[1][0]);
		c.w[0][1]=min(w[0][0]+b.w[0][1],w[0][1]+b.w[1][1]);
		c.w[1][0]=min(w[1][0]+b.w[0][0],w[1][1]+b.w[1][0]);
		c.w[1][1]=min(w[1][0]+b.w[0][1],w[1][1]+b.w[1][1]);
		return c;
	}
};

int dep[300005];
int F[300005][19];node G[300005][19];
int predfs0(int x,int f){
	for(int e=lnk[x];e;e=pre[e]) if(tgt[e]!=f)
		predfs0(tgt[e],x),D[x]=min(D[x],val[e][0]+D[tgt[e]]+val[e][1]);
}
int predfs1(int x,int f){
	for(int e=lnk[x];e;e=pre[e]) if(tgt[e]!=f)
		D[tgt[e]]=min(D[tgt[e]],val[e][0]+D[x]+val[e][1]),predfs1(tgt[e],x);
}
int dfs(int x,int f,int fe){
	dep[x]=dep[f]+1;
	F[x][0]=f;
	G[x][0].u=x,G[x][0].v=f;
	G[x][0].w[0][0]=min(val[fe][0],D[x]+val[fe][1]+D[f]);
	G[x][0].w[1][1]=min(val[fe][1],D[x]+val[fe][0]+D[f]);
	G[x][0].w[0][1]=min(val[fe][0]+D[f],D[x]+val[fe][1]);
	G[x][0].w[1][0]=min(val[fe][1]+D[f],D[x]+val[fe][0]);
	for(int k=1;k<=18;k++)
		F[x][k]=F[F[x][k-1]][k-1],
		G[x][k]=G[x][k-1]+G[F[x][k-1]][k-1];
	for(int e=lnk[x];e;e=pre[e]) if(tgt[e]!=f)
		dfs(tgt[e],x,e);
}
node LCA(int x,int y){
	node ansx(x),ansy(y);
	if(x==y) return ansx;
	for(int k=18;~k;k--) if(dep[F[x][k]]>=dep[y])
		ansx=ansx+G[x][k],x=F[x][k];
	for(int k=18;~k;k--) if(dep[F[y][k]]>=dep[x])
		ansy=ansy+G[y][k],y=F[y][k];
	for(int k=18;~k;k--) if(F[x][k]!=F[y][k])
		ansx=ansx+G[x][k],ansy=ansy+G[y][k],x=F[x][k],y=F[y][k];
	if(x!=y) ansx=ansx+G[x][0],ansy=ansy+G[y][0];
	swap(ansy.u,ansy.v);swap(ansy.w[0][1],ansy.w[1][0]);
	return ansx+ansy;
}

int main(){
//	freopen("work.in","r",stdin);
//	freopen("work.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%lld",&D[i]);
	for(int i=1;i<N;i++){
		int u,v;ll w0,w1;scanf("%d%d%lld%lld",&u,&v,&w0,&w1);
		add_E(u,v,w0,w1);add_E(v,u,w0,w1);
	}
	predfs0(1,0);
	predfs1(1,0);
	dfs(1,0,0);
	scanf("%d",&M);
	while(M--){
		int u,v;scanf("%d%d",&u,&v);
		int uu=(u+1)/2,vv=(v+1)/2,tu=(u&1)^1,tv=(v&1)^1;
		printf("%lld\n",LCA(uu,vv).w[tu][tv]);
	}
}