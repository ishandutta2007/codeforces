#include<bits/stdc++.h>
const int N=2e5+3,K=20;
int n,a[N],t[N],p,q,d,dep[N],fa[N][K],mx[N],son[N];
long long ans;
std::vector<int>g[N];
void Dfs(int u){
	for(int j=1;j<K;j++)fa[u][j]=fa[fa[u][j-1]][j-1]; 
	for(int v:g[u])if(v!=fa[u][0]){
		fa[v][0]=u,dep[v]=dep[u]+1,Dfs(v);
	}
}
inline int Lca(int u,int v){
	if(dep[u]<dep[v])std::swap(u,v);
	for(int j=K-1;~j;j--)if(dep[fa[u][j]]>=dep[v])u=fa[u][j];
	if(u==v)return v;
	for(int j=K-1;~j;j--)if(fa[u][j]!=fa[v][j])u=fa[u][j],v=fa[v][j];
	return fa[u][0];
}
inline int Dis(int u,int v){return dep[u]+dep[v]-2*dep[Lca(u,v)];}
void Dfs1(int u,int fa){
	for(int v:g[u])if(v!=fa){
		Dfs1(v,u);
		if(mx[v]>mx[u])mx[u]=mx[v],son[u]=v;
	}
	mx[u]=std::max(mx[u],a[u]);
	for(int v:g[u])if(v!=fa&&v!=son[u])ans+=mx[v];
}
signed main(){
	int u,v;
	scanf("%d",&n);
	for(u=1;u<=n;u++)scanf("%d",a+u),t[u]=u;
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	dep[1]=1,Dfs(1);
	std::sort(t+1,t+1+n,[](const int&u,const int&v){return a[u]>a[v];});
	p=q=t[1],d=0;
	for(int id=2;id<=n;id++){
		u=t[id];
		int x=Dis(u,p),y=Dis(u,q);
		if(x+d==y){
			p=u,d=y;
			continue;
		}
		if(y+d==x){
			q=u,d=x;
			continue;
		}
	}
	Dfs1(p,0);
	ans+=mx[p]*2;
	printf("%lld\n",ans);
	return 0;
}