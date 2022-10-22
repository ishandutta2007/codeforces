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
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
const ll N=6e5+7;
const ll mod=1e9+7;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
char ss[N];
ll s[N],t[N],fac[N],inv[N],p2[N],sp[N],p[N],phi[N],sh[N];
bool is[N];
ll n,n1,n2,a1=0,a2=0,b1=0,b2=0,w1=0,w2=0,cnt=0;
ll C(ll x,ll y){return fac[x]*inv[y]%mod*inv[x-y]%mod;}

int main(){
	scanf("%s",ss+1);
	n1=strlen(ss+1);
	rep(i,n1){
		if(ss[i]=='A')s[i]=0,a1++;
		if(ss[i]=='B')s[i]=1,b1++;
		if(ss[i]=='?')s[i]=-1,w1++;
	}
	scanf("%s",ss+1);
	n2=strlen(ss+1);
	rep(i,n2){
		if(ss[i]=='A')t[i]=0,a2++;
		if(ss[i]=='B')t[i]=1,b2++;
		if(ss[i]=='?')t[i]=-1,w2++;
	}
	scanf("%lld",&n);
	phi[1]=1;
	REP(i,2,n){
		if(!is[i])p[++cnt]=i,phi[i]=i-1;
		rep(j,cnt){
			if(i*p[j]>n)break;
			is[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	rep(i,n)sh[i]=(sh[i-1]+phi[i])%mod;
	fac[0]=1;
	rep(i,w1+w2)fac[i]=fac[i-1]*i%mod;
	inv[w1+w2]=Pow(fac[w1+w2],mod-2);
	for(ll i=w1+w2;i;i--)inv[i-1]=inv[i]*i%mod;
	p2[0]=1;
	rep(i,n)p2[i]=p2[i-1]*2%mod;
	rep(i,n)sp[i]=(sp[i-1]+p2[i])%mod;
	ll sm=1;
	if(n1!=n2)sm=0;
	else{
		rep(i,n1){
			if(~s[i]){
				if(~t[i]){
					if(s[i]!=t[i]){
						sm=0;
						break;
					}
				}
			}
			else if(t[i]<0)sm=sm*2%mod;
		}
	}
	ll ans=sm*Pow((sp[n]-sp[0]+mod)%mod,2)%mod;
	rep0(i,w1+w2+1){
		ll f=C(w1+w2,i);
		ll c1=a1-a2+i-w2,c2=b1-b2+w1-i;
		if(!c1||!c2){
			if(c1||c2)continue;
			f=(f-sm)%mod;
			ll gg=0;
			rep(j,n)gg=(gg+(sh[n/j]*2-1)*p2[j])%mod;
			ans=(ans+f*gg)%mod;
			continue;
		}
		if(c1*c2>0)continue;
		ll hh=n/(max(abs(c1),abs(c2))/gcd(abs(c1),abs(c2)));
		ans=(ans+f*(sp[hh]-sp[0]+mod))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}