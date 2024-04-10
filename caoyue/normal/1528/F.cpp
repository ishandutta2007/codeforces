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
#include<bitset>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=3e5+7;
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
ll G[2][22][N],F[N],NW[N];
void pre(){
	for(ll i=1,u=0;u<18;i<<=1,u++){
		ll gn1=Pow(3,(mod-1)/i/2),gn2=Pow(3,mod-1-(mod-1)/i/2),g1=1,g2=1;
		rep0(k,i){
			G[0][u][k]=g1;
			G[1][u][k]=g2;
			g1=g1*gn1%mod;
			g2=g2*gn2%mod;
		}
	}
}
void fft(ll *a,ll o,bool s){
	for(ll i=1;i<o;i<<=1)rep0(j,i)NW[j+i]=NW[j]+o/i/2;
	rep0(i,o)F[i]=a[NW[i]];
	for(ll i=1,u=0;i<o;i<<=1,u++){
		for(ll j=0;j<o;j+=i*2){
			rep0(k,i){
				ll x=F[j+k],y=F[i+j+k]*G[s][u][k]%mod;
				F[j+k]=(x+y<mod)?x+y:x+y-mod;
				F[i+j+k]=(x-y<0)?x-y+mod:x-y;
			}
		}
	}
	if(s){
		ll iv=Pow(o,mod-2);
		rep0(i,o)F[i]=F[i]*iv%mod;
	}
	rep0(i,o)a[i]=F[i];
}
ll a[N],b[N],fac[N],inv[N],w[N];
ll n,k;

int main(){
	pre();
	scanf("%lld%lld",&n,&k);
	fac[0]=1;
	rep(i,k)fac[i]=fac[i-1]*i%mod;
	inv[k]=Pow(fac[k],mod-2);
	for(ll i=k;i;i--)inv[i-1]=inv[i]*i%mod;	
	rep(i,k)a[i]=Pow(i,k)*inv[i]%mod;
	rep0(i,k+1)b[i]=Pow(mod-1,i)*inv[i]%mod;
	ll cc=1;
	while(cc<=k+k)cc<<=1;
	fft(a,cc,0);
	fft(b,cc,0);
	rep0(i,cc)a[i]=a[i]*b[i]%mod;
	fft(a,cc,1);
	w[0]=1;
	ll rn=n%mod;
	rep0(i,k)w[i+1]=w[i]*(rn-i+mod)%mod;
	ll ans=0;
	rep0(i,k+1)ans=(ans+w[i]*Pow(rn+1,n-i+mod-1)%mod*a[i])%mod;
	printf("%lld\n",ans);
	return 0;
}