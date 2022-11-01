#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+5;
struct Edge{int to,nxt;}e[N<<1];
int n,m,q,fst[N],tote,md,pos,ans[N],fa[N],dep[N];bool vis[N];
void adde(int u,int v){e[++tote]=(Edge){v,fst[u]};fst[u]=tote;}
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
void uni(int u,int v){if(find(u)!=find(v))fa[fa[u]]=fa[v];}
void dfs(int u,int d,int f){
	vis[u]=true;dep[u]=d;if(dep[u]>md)md=dep[u],pos=u;
	for(int i=fst[u],v;i;i=e[i].nxt)if((v=e[i].to)!=f)
		uni(u,v),dfs(v,d+1,u);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)if(!vis[i])md=-1,dfs(i,0,0),md=-1,dfs(pos,0,0),ans[find(i)]=md;
	while(q--){
		int opt,u,v;scanf("%d",&opt);
		if(opt==1)scanf("%d",&u),printf("%d\n",ans[find(u)]);
		else{
			scanf("%d%d",&u,&v);
			int ru=find(u),rv=find(v),t=max({ans[ru],ans[rv],((ans[ru]+1)>>1)+((ans[rv]+1)>>1)+1});
			if(ru!=rv)ans[ru]=t,fa[rv]=ru;
		}
	}
	return 0;
}