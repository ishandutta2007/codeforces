#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+3,M=1e9+7,K=18;
#define Md (L+R>>1)
struct segment_tree{
	int s[1<<K],lz[1<<K];
	inline void Down(int L,int R,int k){
		lz[k<<1]=(lz[k<<1]+lz[k])%M;
		lz[k<<1|1]=(lz[k<<1|1]+lz[k])%M;
		s[k<<1]=(s[k<<1]+(ll)lz[k]*(Md-L+1))%M;
		s[k<<1|1]=(s[k<<1|1]+(ll)lz[k]*(R-Md))%M;
		lz[k]=0;
	}
	int Sum(int l,int r,int L,int R,int k){
		if(l>r)return 0;
		if(l<=L&&R<=r)return s[k];
		Down(L,R,k);
		if(l>Md)return Sum(l,r,Md+1,R,k<<1|1);
		if(r<=Md)return Sum(l,r,L,Md,k<<1);
		return(Sum(l,r,L,Md,k<<1)+Sum(l,r,Md+1,R,k<<1|1))%M;
	}
	void Add(int l,int r,int a,int L,int R,int k){
		if(l>r)return;
		if(l<=L&&R<=r){
		  lz[k]=(lz[k]+a)%M;
		  s[k]=(s[k]+(ll)a*(R-L+1))%M;
		  return;
		}
		Down(L,R,k);
		if(l<=Md)Add(l,r,a,L,Md,k<<1);
		if(r>Md)Add(l,r,a,Md+1,R,k<<1|1);
		s[k]=(s[k<<1]+s[k<<1|1])%M;
	}
}t;
struct edge{int v,nxt;}g[N+N];
int n,head[N],k,dep[N],prod,invl[N],inv[N],s,s0,s1,ans,dfn[N],son[N],siz[N],top[N],fa[N];
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
struct update{
	int x,u,f;
	bool operator<(const update&b)const{return x<b.x;}
}upd[N+N];
void Dfs(int u){
	int v;
	siz[u]=1;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa[u])
	  dep[v]=dep[u]+1,fa[v]=u,Dfs(v),siz[u]+=siz[v],son[u]=siz[son[u]]>siz[v]?son[u]:v;
}
void Dfs1(int u){
	int v;
	dfn[u]=++k,top[u]=top[u]?top[u]:u;
	if(son[u])top[son[u]]=top[u],Dfs1(son[u]);
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa[u]&&v!=son[u])
	  Dfs1(v);
}
inline void Pathadd(int u,int a){
	for(;u;u=fa[top[u]])
	  t.Add(dfn[top[u]==1?son[1]:top[u]],dfn[u],a,1,n,1);
}
inline int Pathsum(int u){
	int s=0;
	for(;u;u=fa[top[u]])
	  s=(s+t.Sum(dfn[top[u]==1?son[1]:top[u]],dfn[u],1,n,1))%M;
	return s;
}
int main(){
	int u,v,l,r,f;
	scanf("%d",&n);
	inv[1]=1;for(int i=2;i<N;i++)inv[i]=(ll)inv[M%i]*(M-M/i)%M;
	prod=1;
	for(u=1;u<=n;u++){
	  scanf("%d%d",&l,&r);
	  invl[u]=inv[r-l+1];
	  prod=(ll)prod*(r-l+1)%M;
	  upd[u]=(update){l,u,1};
	  upd[u+n]=(update){r+1,u,M-1};
	}
	std::sort(upd+1,upd+1+n+n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	Dfs(1);
	k=0,Dfs1(1);
	for(int i=1,j=1;i<N;i++){
	  for(;upd[j].x==i;j++){
		u=upd[j].u,f=upd[j].f;
		s0=(s0+(ll)invl[u]*f)%M;
		s1=(s1+(ll)invl[u]*dep[u]%M*f)%M;
		Pathadd(u,(ll)invl[u]*f%M);
		s=(s+(ll)f*prod%M*invl[u]%M*(((ll)dep[u]*s0+s1-2*Pathsum(u)%M+M)%M))%M;
	  }
	  ans=(ans+s)%M;
	}printf("%d\n",ans);
	return 0;
}