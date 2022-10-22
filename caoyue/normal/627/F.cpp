#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<bitset>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=2e5+7;
const ll INF=1e9+7;
ll a[N],b[N],c[N],fc[N],pos[N],fa[N],dep[N],sz[N],dg[N],id[N],p[N],bp[N],cp[N];
bool g[N];
ll n,r1,r2,num=0;
struct edge{ll v,next;}e[N*2];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(ll x,ll f,ll d){
	dep[x]=d;
	fa[x]=f;
	if(x==r2)sz[x]=1;
	else sz[x]=0;
	repG(i,x){
		if(e[i].v==f)continue;
		dfs(e[i].v,x,d+1);
		sz[x]+=sz[e[i].v];
	}
}
void dfs2(ll x,ll d,ll f){
	id[x]=d;
	p[d]=x;
	repG(i,x){
		if(!g[e[i].v]||e[i].v==f)continue;
		dfs2(e[i].v,d+1,x);
	}
}
ll fd(ll x,ll &xx,ll f){
	if(g[x]){
		xx=id[x];
		return 0;
	}
	repG(i,x){
		if(e[i].v==f)continue;
		ll t=fd(e[i].v,xx,x);
		if(~t)return t+1;
	}
	return -1;
}

int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,n)scanf("%lld",&b[i]);
	rep(i,n){
		if(!a[i])r1=i;
		if(!b[i])r2=i;
	}
	memset(pos,-1,sizeof(pos));
	rep(i,n-1){
		ll x,y; scanf("%lld%lld",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(r1,0,1);
	rep(i,n){
		if(sz[i]&&i!=r1)c[fa[i]]=a[i];
		if(i==r2)c[i]=0;
		if(!sz[i])c[i]=a[i];
	}
	bool fl=0;
	rep(i,n){
		if(c[i]!=b[i]){
			fl=1;
			break;
		}
	}
	if(!fl){
		printf("0 %lld\n",dep[r2]-1);
		return 0;
	}
	rep(i,n)fc[c[i]]=i;
	ll mn=INF,md;
	rep(i,n){
		if(b[fc[a[i]]]!=a[i]){
			g[i]=1;
			if(dep[i]<mn){
				mn=dep[i];
				md=i;
			}
		}
	}
	g[fa[md]]=1;
	rep(i,n){
		dg[i]=0;
		repG(j,i)dg[i]+=g[e[j].v];
	}
	ll t1=0,t2=0,sg=0;
	rep(i,n){
		if(!g[i])continue;
		sg++;
		if(dg[i]<1||dg[i]>2){
			puts("-1");
			return 0;
		}
		if(dg[i]==1){
			if(!t1)t1=i;
			else if(!t2)t2=i;
			else {
				puts("-1");
				return 0;
			}
		}
	}
	dfs2(t1,1,0);
	ll v1,v2,np=0;
	ll ans=fd(r1,v1,0)+fd(r2,v2,0);
	rep(i,sg)if(i!=v2)p[++np]=p[i];
	rep(i,sg-1)bp[i]=b[p[i]],cp[i]=c[p[i]];
	ll rw=-1;
	rep0(i,sg-1)if(bp[1]==cp[i+1])rw=i;
	if(rw<0){
		puts("-1");
		return 0;
	}
	rep(i,sg-1)if(bp[i]!=cp[(i-1+rw)%(sg-1)+1]){
		puts("-1");
		return 0;
	}
	ll tt;
	if(v1==v2)tt=sg*min(rw,(sg-1)-rw);
	else if(v1<v2)tt=min(sg*rw+(v2-v1),sg*(sg-1-rw)-(v2-v1));
	else tt=min(sg*rw-(v1-v2),sg*(sg-1-rw)+(v1-v2));
	printf("%lld %lld %lld\n",min(t1,t2),max(t1,t2),tt+ans);
	return 0;
}