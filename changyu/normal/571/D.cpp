#include<bits/stdc++.h>
namespace io{
const int D=1<<21;char buf[D],*s,*t;
inline char get(){return s==t&&(t=(s=buf)+fread(buf,1,D,stdin),s==t)?-1:*s++;}
inline int read(){
	int a=0;char c=get();
	for(;c> '9'||c< '0';c=get());
	for(;c<='9'&&c>='0';a=a*10+c-48,c=get());
	return a;
}
inline char readletter(){
	char c=get();
	for(;c<'A'||c>'Z';c=get());
	return c;
}
}
using io::read;
using io::readletter;
typedef long long ll;
const int N=5e5+3,K=20;
int n,m,x[N],y[N],rt[N];char o[N];
#define M (L+R>>1)
struct segment_tree{
	ll s[N*(K+3)];int ls[N*(K+3)],rs[N*(K+3)],t;
	ll Query(int p,int L,int R,int k){
		if(L==R||!k)return s[k];
		return s[k]+(p<=M?Query(p,L,M,ls[k]):Query(p,M+1,R,rs[k]));
	}
	void Add(int l,int r,int a,int L,int R,int g,int&k){
		k=++t,ls[k]=ls[g],rs[k]=rs[g],s[k]=s[g];
		if(l<=L&&R<=r){s[k]+=a;return;}
		if(l<=M)Add(l,r,a,L,M,ls[g],ls[k]);
		if(r> M)Add(l,r,a,M+1,R,rs[g],rs[k]);
	}
}t;
struct yc_mark{int t,x;};
struct segment_tree_{
	yc_mark s[1<<K],tmp;
	segment_tree_(){
		for(int i=1;i<(1<<K);i++)s[i]=(yc_mark){-1,0};
	}
	yc_mark Query(int p,int L,int R,int k){
		if(L==R||~s[k].t)return s[k];
		return p<=M?Query(p,L,M,k<<1):Query(p,M+1,R,k<<1|1);
	}
	void Add(int l,int r,yc_mark a,int L,int R,int k){
		if(l<=L&&R<=r){s[k]=a;return;}
		if(l<=M)Add(l,r,a,L,M,k<<1);
		if(r> M)Add(l,r,a,M+1,R,k<<1|1);
	}
}t1;
struct dsu_tree{
	int dfn[N+N],dfc,siz[N+N],c,p[N+N],g[N+N][2],fa[N+N];
	void Init(){
		c=n;
		for(int u=1;u<=n;u++)p[u]=u;
	}
	void Merge(int u,int v){
		++c,u=Find(u),v=Find(v);
		p[u]=p[v]=p[c]=c;
		fa[u]=fa[v]=c;
		g[c][0]=u,g[c][1]=v;
	}
	int Find(int k){return p[k]==k?k:p[k]=Find(p[k]);}
	void Dfs(int u){
		if(u<=n){
		  dfn[u]=dfc++,siz[u]=1;
		  return;
		}
		dfn[u]=dfc;
		Dfs(g[u][0]),siz[u]+=siz[g[u][0]];
		Dfs(g[u][1]),siz[u]+=siz[g[u][1]];
	}
	void Build(){
		dfc=1;
		for(int u=c;u;u--)if(!siz[u])Dfs(u);
	}
	void Init2(){
		for(int u=1;u<=c;u++)p[u]=u;
	}
	void Merge2(int u,int v){
		u=Find(u),v=Find(v);
		p[u]=p[v]=fa[u];
	}
}dt[2];
int main(){
	int u;yc_mark tmp;
	n=read(),m=read();
	dt[0].Init(),dt[1].Init();
	for(int j=1;j<=m;j++){
	  o[j]=readletter(),x[j]=read();
	  if(o[j]=='U'||o[j]=='M')y[j]=read();
	  if(o[j]=='U')dt[0].Merge(x[j],y[j]);
	  if(o[j]=='M')dt[1].Merge(x[j],y[j]);
	}
	dt[0].Build(),dt[1].Build();
	dt[0].Init2(),dt[1].Init2();
	for(int j=1,la=0;j<=m;j++)switch(o[j]){
	  case'U':dt[0].Merge2(x[j],y[j]);break;
	  case'M':dt[1].Merge2(x[j],y[j]);break;
	  case'A':
		u=dt[0].Find(x[j]);
		t.Add(dt[0].dfn[u],dt[0].dfn[u]+dt[0].siz[u]-1,dt[0].siz[u],1,n,rt[la],rt[j]);
		la=j;
	  break;
	  case'Z':
		u=dt[1].Find(x[j]);
		t1.Add(dt[1].dfn[u],dt[1].dfn[u]+dt[1].siz[u]-1,(yc_mark){la,0},1,n,1);
	  break;
	  case'Q':
		u=x[j];
		tmp=t1.Query(dt[1].dfn[u],1,n,1);
		printf("%lld\n",(~tmp.t?tmp.x-t.Query(dt[0].dfn[u],1,n,rt[tmp.t]):0)+t.Query(dt[0].dfn[u],1,n,rt[la]));
	  break;
	}
	return 0;
}