#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
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
ll n,m=0;
ll a[N],fac[N],inv[N],iv[N],K[N],B[N],f[N],va[N],vb[N],vc[N],ivb[N];

int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,n)m+=a[i];
	fac[0]=1;
	rep(i,max(m,n))fac[i]=fac[i-1]*i%mod;
	inv[(max(n,m))]=Pow(fac[max(n,m)],mod-2);
	for(ll i=max(n,m);i;i--)inv[i-1]=inv[i]*i%mod;
	rep(i,max(n,m))iv[i]=inv[i]*fac[i-1]%mod;
	rep0(i,m){
		va[i]=(m-i)*iv[n-1]%mod*iv[m]%mod;
		vb[i]=i*iv[m]%mod;
		ivb[i]=m*iv[i]%mod;
		vc[i]=(n-2)*(m-i)%mod*iv[n-1]%mod*iv[m]%mod;
	}
	K[m]=B[m-1]=B[m]=0;
	K[m-1]=1;
	for(ll i=m-2;~i;i--){
		K[i]=((1-vc[i+1]+mod)*K[i+1]-va[i+1]*K[i+2]%mod+mod)%mod*ivb[i+1]%mod;
		B[i]=((1-vc[i+1]+mod)*B[i+1]-va[i+1]*B[i+2]%mod+mod-1+mod)%mod*ivb[i+1]%mod;
	}
	ll ic=Pow((1-vc[0]+mod)%mod,mod-2);
	ll sk=(K[1]*va[0]%mod*ic-K[0]+mod)%mod,sb=(B[0]-(B[1]*va[0]%mod+1)*ic%mod+mod)%mod;
	ll oo=sb*Pow(sk,mod-2)%mod;
	rep0(i,m+1)f[i]=(oo*K[i]+B[i])%mod;
	ll ss=0;
	rep(i,n)ss=(ss+f[a[i]])%mod;
	ss=(ss-(n-1)*f[0]%mod+mod)%mod;
	printf("%lld\n",ss*iv[n]%mod);
	return 0;
}