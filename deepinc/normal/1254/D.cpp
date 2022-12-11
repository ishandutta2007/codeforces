#include<bits/stdc++.h>
using namespace std;
#define F for(int _=fir[p],y;y=to[_];_=l[_])
const int S=2e6+6,mod=998244353;
int n,fir[S],l[S],to[S],dfn[S],ans,sz[S],tim,w[S],T[S],f[S],top[S],son[S],ec,m,tag[S];
int mo(int x){return x>=mod?x-mod:x;}
int qp(int b,int t,int a=1){for(;t;t>>=1,b=1ll*b*b%mod)if(t&1)a=1ll*a*b%mod;return a;}
void link(int a,int b){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;}
void add(int p,int v){for(;p<=n;p+=p&-p)T[p]=mo(T[p]+v);}
int ask(int p,int a=0){for(;p;p^=p&-p)a=mo(a+T[p]);return a;}
void dfs(int p,int fa){
	sz[p]=1;f[p]=fa;
	F if(y!=fa)dfs(y,p),sz[p]+=sz[y],son[p]=sz[son[p]]>sz[y]?son[p]:y;
}
void DFS(int p,int tp){
	dfn[p]=++tim;top[p]=tp;
	if(son[p])DFS(son[p],tp);
	F if(!dfn[y])DFS(y,y);
}
int Ask(int p,int a=0){
	for(int y;y=top[p],p;p=f[top[p]])
		a=mo(a+mo(mod+ask(dfn[p])-ask(dfn[y]-1))),
		a=(a+tag[f[y]]*1ll*(n-sz[y]-sz[f[y]]+mod))%mod;
	return a;
}
void upd(int x,int y){
	if(son[x])add(dfn[son[x]],(mod+n-sz[son[x]]-sz[x])*1ll*y%mod);
	tag[x]=mo(tag[x]+y); ans=(ans+1ll*y*sz[x])%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<n;++i)scanf("%d%d",&a,&b),link(a,b),link(b,a);
	dfs(1,0);DFS(1,1);
	for(int i=1,o,x,y;i<=m;++i){
		scanf("%d%d",&o,&x);
		if(o==2)printf("%lld\n",(ans+Ask(x)+1ll*tag[x]*(n-sz[x]))%mod*qp(n,mod-2)%mod);
		else scanf("%d",&y),upd(x,y);
	}
}