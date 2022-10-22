#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
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
const ll N=1e3+7;
const ll mod=1e9+7;
ll d[N],fac[N],inv[N],f[N];
char s[N];
ll k,n;
ll C(ll x,ll y){
	if(x<y||y<0)return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
ll check(ll w){
	ll ans=0,qw=w;
	rep(i,n){
		if(s[i]=='0')continue;
		ans=(ans+C(n-i,w))%mod;
		w--;
	}
	if(!w)ans=(ans+1)%mod;
	return ans;
}
ll bc(ll x){
	ll ans=0;
	while(x)ans+=(x&1),x>>=1;
	return ans;
}
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%I64d",&k);
	if(!k){printf("1\n"); return 0;}
	if(k==1){printf("%d\n",n-1); return 0;}
	fac[0]=1;
	rep(i,n)fac[i]=fac[i-1]*i%mod;
	inv[n]=Pow(fac[n],mod-2);
	for(ll i=n;i;i--)inv[i-1]=inv[i]*i%mod;
	f[1]=0;
	REP(i,2,1000)f[i]=f[bc(i)]+1;
	ll cal=0;
	REP(i,2,1000)if(f[i]==k-1)cal=(cal+check(i))%mod;
	printf("%I64d\n",cal);
	return 0;
}