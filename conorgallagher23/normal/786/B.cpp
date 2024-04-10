#include<bits/stdc++.h>
#define LL long long
#define pii pair<LL,int>
using namespace std;
const int N=1e5+5,S=4e6+5,M=S<<2;
const LL Inf=1e18;
struct Edge{int to,w,nxt;}e[M];
int n,m,s,fst[S],tote,lg[N],in[N][20],out[N][20],id;LL dis[S];bool vis[S];
void adde(int u,int v,int w){e[++tote]=(Edge){v,w,fst[u]};fst[u]=tote;}
priority_queue<pii>q;
void dij(){
	for(int i=0;i<S;i++)dis[i]=Inf;
	q.push(pii(0,s));dis[s]=0;
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;vis[u]=true;
		for(int i=fst[u],v,w;i;i=e[i].nxt){
			v=e[i].to;w=e[i].w;
			if(dis[v]>dis[u]+w)dis[v]=dis[u]+w,q.push(pii(-dis[v],v));
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	lg[0]=-1;for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)in[i][0]=out[i][0]=i;
	id=n;
	for(int k=1;k<=18;k++)for(int i=1;i+(1<<k)-1<=n;i++){
		out[i][k]=++id;in[i][k]=++id;
		adde(out[i][k],out[i][k-1],0);adde(out[i][k],out[i+(1<<k-1)][k-1],0);
		adde(in[i][k-1],in[i][k],0);adde(in[i+(1<<k-1)][k-1],in[i][k],0);
	}
	while(m--){
		int opt,u,v,l,r,w;scanf("%d",&opt);
		if(opt==1)scanf("%d%d%d",&u,&v,&w),adde(u,v,w);
		if(opt==2){
			scanf("%d%d%d%d",&u,&l,&r,&w);
			int t=lg[r-l+1];
			adde(u,out[l][t],w);adde(u,out[r-(1<<t)+1][t],w);
		}
		if(opt==3){
			scanf("%d%d%d%d",&u,&l,&r,&w);
			int t=lg[r-l+1];
			adde(in[l][t],u,w);adde(in[r-(1<<t)+1][t],u,w);
		}
	}
	dij();
	for(int i=1;i<=n;i++)if(dis[i]>=Inf)printf("-1 ");else printf("%lld ",dis[i]);
	puts("");
	return 0;
}