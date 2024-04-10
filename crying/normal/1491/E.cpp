#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
const int MAXN=2e5+10,MAXM=4e5+10;
int n,u,v,f[40],valid[MAXM];

struct Edge{
	int u,v,w;
}edge[MAXM];
int first[MAXN],next[MAXM],tot;
int sz[MAXN],depth[MAXN],vis[MAXN];
il void addedge(int u,int v){
	edge[++tot].u=u;edge[tot].v=v;
	next[tot]=first[u];first[u]=tot;
}
void preDfs(int u,int fa){
	depth[u]=depth[fa]+1,sz[u]=1;
	for(int j=first[u];j;j=next[j]){
		if(edge[j].w)continue;
		int v=edge[j].v;
		if(v==fa)continue;
		preDfs(v,u);
		sz[u]+=sz[v];
	}
}
int Search(int u,int fa,int root){
	int ans=0;
	for(int j=first[u];j;j=next[j]){
		if(edge[j].w)continue;
		int v=edge[j].v;if(v==fa)continue;
		if(valid[sz[v]] && valid[sz[root]-sz[v]])return j;
		ans=Search(v,u,root);if(ans)return ans;
	}
	return ans;
}
int dfs(int u,int fa){
	preDfs(u,fa);
	if(!valid[sz[u]])return 0;
	if(sz[u]==1)return 1;
	int e=Search(u,fa,u);
	if(!e)return 0;
	int x=edge[e].u,y=edge[e].v;
	if(sz[x]>sz[y])swap(x,y);
	edge[e].w=edge[op(e)].w=1; //
	return dfs(x,y) && dfs(u,fa); 
}
int main(){
	scanf("%d",&n);
	f[0]=f[1]=1,valid[1]=1;
	rep(i,2,27){f[i]=f[i-1]+f[i-2],valid[f[i]]=1;}
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		addedge(u,v),addedge(v,u);
	}
	printf("%s",(dfs(1,0)?"YES":"NO"));
	return 0;
}