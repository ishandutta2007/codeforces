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
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll M=357;
const ll N=1e5+M+M;
const ll INF=1e18;
ll n,T;
ll a[N],d[N],s[N],c[N],ik[N],dd[N],ss[N],sz[N],nw[N];
bool is[N],gg[N];
struct pir{ll x,v,id;}p[M][M];
bool sb(pir a,pir b,pir c){
	ll x1=(b.x-a.x),y1=(b.v-a.v),x2=(c.x-a.x),y2=(c.v-a.v);
	return y2*x1>x2*y1;
}
void build(ll x){
	gg[x]=1;
	ss[min(x*T,n)+1]=0;
	for(ll i=min(x*T,n);i>(x-1)*T;i--){
		ss[i]=ss[i+1];
		if(!is[i])gg[x]=0;
		else ss[i]+=a[i];
	}
	if(gg[x])return;
	c[x]=0;
	dd[(x-1)*T]=d[x];
	ll tp=0;
	p[x][0].x=-INF;
	REP(i,(x-1)*T+1,x*T){
		dd[i]=dd[i-1];
		if(!is[i]){
			if(a[i]<=p[x][tp].x)continue;
			pir hh=(pir){a[i],(dd[i]+1)*a[i]+ss[i],i};
			while(tp>1){
				if(!sb(p[x][tp-1],p[x][tp],hh))break;
				tp--;
			}
			p[x][++tp]=hh;
		}
		else dd[i]++;
	}
	c[x]=tp;
	sz[x]=0;
	nw[x]=1;
	while(nw[x]!=tp&&p[x][nw[x]].v<p[x][nw[x]+1].v)nw[x]++;
}
ll solve(){
	ll mx=-INF,md=0;
	rep(i,(n-1)/T+1){
		if(gg[i])continue;
		ll hh=p[i][nw[i]].v+p[i][nw[i]].x*sz[i]+s[i];
		if(hh>mx){
			mx=hh;
			md=i;
		}
	}
	ll t=p[md][nw[md]].id;
	is[t]=1;
	rep(i,md-1)s[i]+=a[t];
	REP(i,md+1,(n-1)/T+1){
		sz[i]++;
		d[i]++;
		while(nw[i]<c[i]){
			if(p[i][nw[i]+1].v+p[i][nw[i]+1].x*sz[i]<p[i][nw[i]].v+p[i][nw[i]].x*sz[i])break;
			nw[i]++;
		}
	}
	build(md);
	return mx;
}
int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&a[i]);
	T=sqrt(n);
	for(ll i=1;i<=n;i+=T){
		rep0(j,T)ik[i+j]=(i-1)/T+1;
		build((i-1)/T+1);
	}
	ll ans=0,Ans=0;
	rep(i,n){
		ll t=solve();
		ans+=t;
		Ans=max(Ans,ans);
	}
	printf("%lld\n",Ans);
	return 0;
}