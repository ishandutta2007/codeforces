#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<LL,int>
using namespace std;
const int N=1e5+5,M=1e6+5;
const LL Inf=1e18;
struct Graph{int u,v;LL w;}g[M];
struct Edge{int to,w,nxt;}e[M];
int n,m,k,qq,tot,E,fst[N],tote,p[N];bool vis[N];LL dis[N];
priority_queue<pii>q;
void adde(int u,int v,int w){e[++tote]=(Edge){v,w,fst[u]};fst[u]=tote;}
void dij(){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)dis[i]=Inf,vis[i]=false;
	for(int i=1;i<=k;i++)q.push(pii(0,i)),dis[i]=0,p[i]=i;
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;vis[u]=false;
		for(int i=fst[u],v,w;i;i=e[i].nxt){
			v=e[i].to;w=e[i].w;
			if(dis[v]>dis[u]+w)dis[v]=dis[u]+w,p[v]=p[u],q.push(pii(-dis[v],v));
		}
	}
}
int bf[N<<1],fa[N<<1][21],dep[N<<1];LL val[N<<1];
vector<int>adj[N<<1];
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;~i;i--)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=20;~i;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs(int u,int f){
	dep[u]=dep[f]+1;fa[u][0]=f;
	for(int i=1;i<=20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:adj[u])dfs(v,u); 
}
int find(int u){return bf[u]==u?u:bf[u]=find(bf[u]);}
bool cmp(Graph a,Graph b){return a.w<b.w;}
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&qq);
	for(int i=1,u,v,w;i<=m;i++)scanf("%d%d%d",&u,&v,&w),adde(u,v,w),adde(v,u,w);
	dij();
	for(int u=1;u<=n;u++)for(int i=fst[u],v,w;i;i=e[i].nxt)
		v=e[i].to,w=e[i].w,g[++E]=(Graph){p[u],p[v],dis[u]+dis[v]+(LL)w};
	sort(g+1,g+E+1,cmp);
	tot=n;for(int i=1;i<=n;i++)bf[i]=i;
	for(int i=1,u,v,ru,rv;i<=E;i++){
		u=g[i].u;v=g[i].v;LL w=g[i].w;
		ru=find(u);rv=find(v);
		if(ru!=rv){
			val[++tot]=w;bf[tot]=bf[ru]=bf[rv]=tot;
			adj[tot].pb(ru);adj[tot].pb(rv);
		}
	}
	for(int i=1;i<=tot;i++)if(bf[i]==i)dfs(i,0);
	while(qq--){
		int u,v;scanf("%d%d",&u,&v);
		printf("%lld\n",val[lca(u,v)]);
	}
	return 0;
}