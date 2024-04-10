#include<bits/stdc++.h>
#define P(i) ((i-1)/D+1)
#define L(j) ((j)*D-D+1)
#define R(j) std::min((j)*D,n)
const int N=1e5+3,D=180,C=560;
int n,m,fa[N],ord[N],dfn[N],dfc,siz[N],son[N],top[N],f[N],a[N],t[N],lz[C];
bool Cmp(const int&i,const int&j){return f[ord[i]]==f[ord[j]]?a[i]<a[j]:f[ord[i]]>f[ord[j]];}
std::vector<int>g[N];
void Dfs0(int u){
	int v;
	siz[u]=1;
	for(int i=0;i<g[u].size();i++){
	  v=g[u][i];
	  Dfs0(v);
	  siz[u]+=siz[v],son[u]=siz[v]>siz[son[u]]?v:son[u];
	}
}
void Dfs1(int u){
	int v;
	ord[dfn[u]=++dfc]=u,top[u]=top[u]?top[u]:u;
	if(son[u])top[son[u]]=top[u],Dfs1(son[u]);
	for(int i=0;i<g[u].size();i++)if((v=g[u][i])!=son[u])Dfs1(v);
}
inline void Add(int l,int r,int x){
	if(P(l)==P(r)){
	  for(int i=l;i<=r;i++)a[i]+=x;
	  std::sort(t+L(P(l)),t+R(P(l))+1,Cmp);
	  return;
	}
	for(int i=l;i<=R(P(l));i++)a[i]+=x;
	std::sort(t+L(P(l)),t+R(P(l))+1,Cmp);
	for(int i=L(P(r));i<=r;i++)a[i]+=x;
	std::sort(t+L(P(r)),t+R(P(r))+1,Cmp);
	for(int j=P(l)+1;j<P(r);j++)lz[j]+=x;
}
inline int Query(){
	int res=0,l,r,m;
	for(int j=1;L(j)<=n;j++){
	  l=L(j),r=R(j)+1;
	  for(;l<r;)m=l+r>>1,!f[ord[t[m]]]&&a[t[m]]+lz[j]>0?r=m:l=m+1;
	  res+=R(j)-l+1;
	}return res;
}
int main(){
	int x,u;
	scanf("%d%d",&n,&m);
	for(u=2;u<=n;u++)scanf("%d",fa+u),g[fa[u]].push_back(u);
	Dfs0(1),Dfs1(1);
	for(u=1;u<=n;u++)scanf("%d",a+dfn[u]),a[dfn[u]]=-a[dfn[u]];
	for(int i=1;i<=n;i++)t[i]=i;
	for(int j=1;L(j)<=n;j++)std::sort(t+L(j),t+R(j)+1,Cmp);
	for(;m--;){
	  scanf("%d",&u),u=std::abs(u);
	  x=(f[u]^1)-f[u],f[u]^=1;
	  std::sort(t+L(P(dfn[u])),t+R(P(dfn[u]))+1,Cmp);
	  for(;u;u=fa[top[u]])Add(dfn[top[u]],dfn[u],x);
	  printf("%d ",Query());
	}return 0*puts("");
}