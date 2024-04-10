#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e5+7;
const ll INF=1e9+7;
const ll mod=998244353;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll n;
ll X[N],v[N],p1[N],p2[N],mx[N],mi[N],f[N],h1[N],h2[N],hs[N];
struct pir{ll w1,w2,w;};
pir mer(pir a,pir b){return (pir){a.w1*b.w1%mod,a.w2*b.w2%mod,(a.w1*b.w+b.w2*a.w-a.w1*b.w2%mod+mod)%mod};}
struct Tree{ll l,r; pir s;}tr[N*4];
void build(ll l,ll r,ll p){
	tr[p]=(Tree){l,r,(pir){0,0,0}};
	if(l==r){
		tr[p].s.w1=p1[l];
		tr[p].s.w2=p2[l];
		tr[p].s.w=(p1[l]+p2[l])%mod;
		return;
	}
	ll mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	tr[p].s=mer(tr[p*2].s,tr[p*2+1].s);
}
pir check(ll p,ll L,ll R){
	if(L>R){return (pir){1,1,1};}
	ll l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r)return tr[p].s;
	ll mid=(l+r)>>1;
	if(L<=mid){
		if(R>mid)return mer(check(p*2,L,R),check(p*2+1,L,R));
		return check(p*2,L,R);
	}
	return check(p*2+1,L,R);
}
struct tms{ll id,o1,o2,d,v;}t[N*4];
bool cmp(tms a,tms b){return a.d*b.v<a.v*b.d;}
ll ff(ll x){return (f[x]==x)?x:f[x]=ff(f[x]);}

int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld%lld%lld",&X[i],&v[i],&p1[i]);
	ll iv=Pow(100,mod-2);
	rep(i,n){
		p2[i]=p1[i]*iv%mod;
		p1[i]=(1-p2[i]+mod)%mod;
	}
	build(1,n,1);
	rep(i,n){
		mx[i]=mi[i]=f[i]=i;
		h1[i]=INF;
		h2[i]=0;
		hs[i]=1;
	}
	ll cnt=0;
	rep(i,n-1){
		t[++cnt]=(tms){i,2,1,X[i+1]-X[i],v[i]+v[i+1]};
		if(v[i]>v[i+1])t[++cnt]=(tms){i,2,2,X[i+1]-X[i],v[i]-v[i+1]};
		if(v[i]<v[i+1])t[++cnt]=(tms){i,1,1,X[i+1]-X[i],v[i+1]-v[i]};
	}
	sort(t+1,t+cnt+1,cmp);
	t[0].d=t[0].v=0;
	ll ans=0,pb=1;
	rep(i,cnt){
		ans=(ans+(t[i].d*Pow(t[i].v,mod-2)%mod-t[i-1].d*Pow(t[i-1].v,mod-2)%mod+mod)*pb)%mod;
		if(t[i].o1^t[i].o2){
			ll u=ff(t[i].id+1);
			pb=pb*Pow(hs[u],mod-2)%mod;
			pb=pb*Pow(hs[t[i].id],mod-2)%mod;
			mx[u]=max(mx[u],mx[t[i].id]);
			mi[u]=min(mi[u],mi[t[i].id]);
			h1[u]=min(h1[u],h1[t[i].id]);
			h2[u]=max(h2[u],h2[t[i].id]);
			f[t[i].id]=u;
			if(h1[u]<h2[u]){
				printf("%lld\n",ans);
				return 0;
			}
			pir e1=check(1,mi[u],max(mi[u]-1,h2[u]));
			pir e2=check(1,max(mi[u]-1,h2[u])+1,min(mx[u],h1[u]));
			pir e3=check(1,min(mx[u],h1[u])+1,mx[u]);
			hs[u]=e1.w1*e2.w%mod*e3.w2%mod;
			pb=pb*hs[u]%mod;
		}
		else{
			ll u=ff(t[i].id);
			pb=pb*Pow(hs[u],mod-2)%mod;
			if(t[i].o1==2)h2[u]=max(h2[u],t[i].id);
			else h1[u]=min(h1[u],t[i].id);
			if(h1[u]<h2[u]){
				printf("%lld\n",ans);
				return 0;
			}
			pir e1=check(1,mi[u],max(mi[u]-1,h2[u]));
			pir e2=check(1,max(mi[u]-1,h2[u])+1,min(mx[u],h1[u]));
			pir e3=check(1,min(mx[u],h1[u])+1,mx[u]);
			hs[u]=e1.w1*e2.w%mod*e3.w2%mod;
			pb=pb*hs[u]%mod;
		}
	}
	ans=(ans-t[cnt].d*Pow(t[cnt].v,mod-2)%mod*pb%mod+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}