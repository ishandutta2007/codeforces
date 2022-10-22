#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=5e5+7;
const ll mod=1e9+7;
ll n,S=0;
ll X[N],Y[N],s1x[N],s2x[N],s1y[N],s2y[N],c1[N],c2[N];
ll tr(ll x){return (x-1+n)%n+1;}
ll calc(ll x,ll y,ll z){
	ll u=min(min(x,y),z),v=max(max(x,y),z);
	ll w=x+y+z-u-v;
	ll x1=X[u]-X[v],x2=X[w]-X[v],y1=Y[u]-Y[v],y2=Y[w]-Y[v];
	return x2*y1-x1*y2;
}
void ins(ll l,ll r,ll k,ll b,ll x,ll y){
	s1x[r+1]=(s1x[r+1]-k*x%mod+mod)%mod;;
	s1x[l]=(s1x[l]+k*x)%mod;
	s2x[r+1]=(s2x[r+1]-b*x%mod+mod)%mod;
	s2x[l]=(s2x[l]+b*x)%mod;
	s1y[r+1]=(s1y[r+1]-k*y%mod+mod)%mod;;
	s1y[l]=(s1y[l]+k*y)%mod;
	s2y[r+1]=(s2y[r+1]-b*y%mod+mod)%mod;
	s2y[l]=(s2y[l]+b*y)%mod;
	c1[r+1]=(c1[r+1]-k+mod)%mod;
	c1[l]=(c1[l]+k)%mod;
	c2[r+1]=(c2[r+1]-b+mod)%mod;
	c2[l]=(c2[l]+b)%mod;
}
int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld%lld",&X[i],&Y[i]);
	REP(i,3,n)S+=calc(1,i,i-1);
	ll nw=0,id;
	REP(i,3,n){
		nw+=calc(1,i,i-1);
		if(nw>=(S+1)/2){
			id=i;
			break;
		}
	}
	rep(i,n){
		if(i<id){
			ins(i,id-1,2,n-1-2*id,X[i],Y[i]);
			ins(1,i-1,-2,n-5-(n-id)*2,X[i],Y[i]);
			ins(id,n,-2,n-5+2*id,X[i],Y[i]);
		}
		else{
			ins(id,i-1,-2,n-5+2*id,X[i],Y[i]);
			ins(i,n,2,-n-3-2*(id-1),X[i],Y[i]);
			ins(1,id-1,2,n-3-2*(id-1),X[i],Y[i]);
		}
		nw-=calc(i,i+1,id);
		while(nw<(S+1)/2){
			nw+=calc(i+1,id,tr(id+1));
			id=tr(id+1);
		}
	}
	ll ans=0;
	rep(i,n){
		s1x[i]=(s1x[i]+s1x[i-1])%mod;
		s2x[i]=(s2x[i]+s2x[i-1])%mod;
		s1y[i]=(s1y[i]+s1y[i-1])%mod;
		s2y[i]=(s2y[i]+s2y[i-1])%mod;
		c1[i]=(c1[i]+c1[i-1])%mod;
		c2[i]=(c2[i]+c2[i-1])%mod;
		ll sx=(s1x[i]*i+s2x[i])%mod,sy=(s1y[i]*i+s2y[i])%mod,s=(c1[i]*i+c2[i])%mod;
		sx=(sx-s*X[i]%mod+mod)%mod;
		sy=(sy-s*Y[i]%mod+mod)%mod;
		ll x1=(X[tr(i+1)]-X[i]+mod)%mod,y1=(Y[tr(i+1)]-Y[i]+mod)%mod;
		ans=(ans+y1*sx%mod-x1*sy%mod+mod)%mod;
	}
	printf("%lld\n",ans*((mod+1)/2)%mod);
	return 0;
}