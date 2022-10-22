#include<cstdio>
#include<algorithm>
const int N=2e5+3,K=20;
struct edge{int v,nxt;}g[N+N];
int n,fa[N+N][K],son[N+N][26],len[N+N],pos[N+N],lst,t,head[N+N],k,dfn[N],ord[N],dfn2[N+N],siz[N+N],dfc,dp[N+N];
char a[N];
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs0(int u){
	int v;
	for(int j=1;j<K;j++)fa[u][j]=fa[fa[u][j-1]][j-1];
	dfn2[u]=dfc+1;
	if(pos[u]>0)
	  ord[dfn[pos[u]]=++dfc]=pos[u],siz[u]=1;
	for(int i=head[u];i;i=g[i].nxt){
	  v=g[i].v;
	  Dfs0(v);
	  siz[u]+=siz[v];
	}
}
#define M (L+R>>1)
struct segment_tree{
	int mx[N*K],ls[N*K],rs[N*K],t,rt[N];
	int Max(int l,int r,int L,int R,int k){
		if(!k||l>r)return 0;
		if(l<=L&&R<=r)return mx[k];
		if(r<=M)return Max(l,r,L,M,ls[k]);
		if(l> M)return Max(l,r,M+1,R,rs[k]);
		return std::max(Max(l,r,L,M,ls[k]),Max(l,r,M+1,R,rs[k]));
	}
	void Update(int p,int a,int L,int R,int k0,int&k1){
		k1=++t,ls[k1]=ls[k0],rs[k1]=rs[k0];
		mx[k1]=std::max(mx[k0],a);
		if(L==R)return;
		p<=M?Update(p,a,L,M,ls[k0],ls[k1]):Update(p,a,M+1,R,rs[k0],rs[k1]);
	}
}tr;
void Dfs1(int u){
	int v,w;
	for(int i=head[u];i;i=g[i].nxt){
	  v=g[i].v,Dfs1(v);
	  dp[u]=std::max(dp[u],dp[v]);
	  pos[u]=pos[v];
	}
	v=u;
	for(int j=K-1;~j;j--)
	  if((w=fa[v][j])&&tr.Max(dfn2[w],dfn2[w]+siz[w]-1,1,n,tr.rt[pos[u]-1])-len[w]<pos[u]-len[u])
		v=w;
	if(fa[v][0]>1)dp[fa[v][0]]=std::max(dp[fa[v][0]],dp[u]+1);
}
int main(){
	int u,v,w,p,c;
	scanf("%d%s",&n,a+1);
	lst=t=1;
	for(int i=1;i<=n;i++){
	  c=a[i]-'a';
	  u=++t,len[u]=i,pos[u]=i;
	  for(v=lst;v&&!son[v][c];v=fa[v][0])son[v][c]=u;
	  if(v){
		p=son[v][c];
		if(len[p]==len[v]+1)fa[u][0]=p;
		else{
		  w=++t,len[w]=len[v]+1;
		  fa[w][0]=fa[p][0],fa[u][0]=fa[p][0]=w;
		  for(int j=0;j<26;j++)son[w][j]=son[p][j];
		  for(;v&&son[v][c]==p;v=fa[v][0])son[v][c]=w;
		}
	  }else fa[u][0]=1;
	  lst=u;
	}
	for(u=2;u<=t;u++)Insert(fa[u][0],u);
	Dfs0(1);
	for(int i=1;i<=n;i++)tr.Update(dfn[i],i,1,n,tr.rt[i-1],tr.rt[i]);
	for(u=1;u<=t;u++)dp[u]=1;
	Dfs1(1);
	printf("%d\n",dp[1]);
	return 0;
}