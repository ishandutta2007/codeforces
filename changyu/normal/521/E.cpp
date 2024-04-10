#include<cstdio>
#include<vector>
#include<set>
const int N=2e5+3;
struct edge{int v,nxt;}g[N+N];
int n,m,head[N],k,dfn[N],dfc,cnt,x[N],y[N],fa[N],s[2],t[2],w,z,fnd,dep[N];
std::vector<int>add[N],ans[3];
std::set<int>tot[N];
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs0(int u){
	int v;
	dfn[u]=++dfc;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa[u]){
	  if(!dfn[v])fa[v]=u,dep[v]=dep[u]+1,Dfs0(v);
	  else if(dfn[v]<dfn[u]){
		++cnt;
		x[cnt]=u,y[cnt]=v;
		add[u].push_back(cnt);
		add[v].push_back(-cnt);
	  }
	}
}
void Dfs1(int u){
	int v;
	for(int i=head[u];i;i=g[i].nxt)if(fa[v=g[i].v]==u){
	  Dfs1(v);
	  if(!fnd)for(std::set<int>::iterator it=tot[v].begin();it!=tot[v].end();it++)
		tot[u].insert(*it);
	}
	if(!fnd)for(int i=0;i<add[u].size();i++)
	  if(add[u][i]<0)tot[u].erase(-add[u][i]);
	  else tot[u].insert(add[u][i]);
	if(!fnd&&fa[u]&&tot[u].size()>1){
	  int k=0;
	  for(std::set<int>::iterator it=tot[u].begin();it!=tot[u].end();it++){
		s[k]=x[*it],t[k]=y[*it];
		++k;
		if(k==2)break;
	  }
	  fnd=1;
	}
}
inline int Lca(int u,int v){
	for(;dep[u]>dep[v];u=fa[u]);
	for(;dep[u]<dep[v];v=fa[v]);
	for(;u!=v;u=fa[u],v=fa[v]);
	return u;
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(;m--;)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	for(u=1;u<=n;u++)if(!dfn[u])Dfs0(u);
	for(u=1;u<=n;u++)if(!fa[u])Dfs1(u);
	if(!fnd)return 0*puts("NO");
	puts("YES");
	w=Lca(s[0],s[1]);
	z=dep[t[0]]>dep[t[1]]?t[0]:t[1];
	for(u=w;u!=fa[z];u=fa[u])ans[0].push_back(u);
	for(u=z;u!=fa[t[0]];u=fa[u])
	  ans[1].push_back(u);
	for(u=s[0];u!=fa[w];u=fa[u])
	  ans[1].push_back(u);
	for(u=z;u!=fa[t[1]];u=fa[u])
	  ans[2].push_back(u);
	for(u=s[1];u!=fa[w];u=fa[u])
	  ans[2].push_back(u);
	printf("%d",ans[0].size());
	for(int i=ans[0].size()-1;~i;i--)
	  printf(" %d",ans[0][i]);
	printf("\n%d",ans[1].size());
	for(int i=0;i<ans[1].size();i++)
	  printf(" %d",ans[1][i]);
	printf("\n%d",ans[2].size());
	for(int i=0;i<ans[2].size();i++)
	  printf(" %d",ans[2][i]);
	return 0;
}