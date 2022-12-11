#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,S=4e5+5;
vector<int>v[S];
#define pb push_back
int fir[S],a[S],l[S],to[S],ec,dfn[S],dep[S],son[S],sz[S],f[S],tim,top[S],n,ans,sta[S],sum[S],d;
int phi[S],p[S],pc,np[S],mu[S],F[S];
int qp(int b,int t=mod-2,int a=1){for(;t;t>>=1,b=1ll*b*b%mod)if(t&1)a=1ll*a*b%mod;return a;}
int mo(int x){return x>=mod?x-mod:x;}
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void link(int a,int b){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;}
void dfs(int p,int fa){
	sz[p]=1; dep[p]=dep[fa]+1; dfn[p]=++tim; f[p]=fa;
	for(int i=fir[p];i;i=l[i])if(to[i]!=fa){
		dfs(to[i],p);sz[p]+=sz[to[i]];
		if(sz[to[i]]>sz[son[p]])son[p]=to[i];
	}
}
void DFS(int p,int tp){
	top[p]=tp;
	if(son[p])DFS(son[p],tp);
	for(int i=fir[p];i;i=l[i])if(!top[to[i]])DFS(to[i],to[i]);
}
int lca(int x,int y){
	while(top[x]!=top[y])if(dep[top[x]]<dep[top[y]])y=f[top[y]];else x=f[top[x]];
	return dep[x]<dep[y]?x:y;
}
void cal(int p,int r){
	sum[p]=p%d==0?phi[p]:0; if(p%d==0)ans=(ans+1ll*r*phi[p]%mod*phi[p]%mod*dep[p])%mod;
	for(int i=0,y;y=i<v[p].size()?v[p][i]:0;++i)cal(y,r),ans=(ans+2ll*r*dep[p]%mod*sum[p]%mod*sum[y])%mod,sum[p]=mo(sum[p]+sum[y]);
	v[p].clear();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),link(a[x],a[y]),link(a[y],a[x]);
	dfs(1,0);DFS(1,1);
	mu[1]=phi[1]=1;
	for(int i=2;i<=n;++i){
		if(!np[i])p[++pc]=i,mu[i]=-1,phi[i]=i-1;
		for(int j=1,x;(x=i*p[j])<=n;++j)
			if(i%p[j])np[x]=1,phi[x]=phi[i]*(p[j]-1),mu[x]=-mu[i];
			else{np[x]=1,phi[x]=phi[i]*p[j];break;}
	}
	for(int i=1;i<=n;++i)for(int j=i;j<=n;j+=i)F[j]=(F[j]+1ll*i*qp(phi[i])*mu[j/i]%mod+mod)%mod;
	for(d=1;d<=n;++d){
		int f=F[d],c=0,rt=d,top=0,phd=0,ph=0;
		for(int g=d;g<=n;g+=d)a[++c]=g,rt=lca(rt,g),phd=(phd+1ll*phi[g]*dep[g])%mod,ph=mo(ph+phi[g]);
		sort(a+1,a+1+c,cmp); ans=(ans+2ll*phd*ph%mod*f)%mod;
		for(int i=1,L;i<=c;++i){
			if(!top)goto E;
			if((L=lca(sta[top],a[i]))==sta[top])goto E;
			while(top>1&&dfn[L]<=dfn[sta[top-1]])v[sta[top-1]].pb(sta[top]),top--;
			if(L!=sta[top])v[L].pb(sta[top]),sta[top]=L;
			E:sta[++top]=a[i];
		}while(top>1)v[sta[top-1]].pb(sta[top]),top--;
		cal(rt,mo(mod+mod-f-f));
	}printf("%lld",(0ll+ans%mod+mod)%mod*qp((n-1ll)*n%mod)%mod);
}