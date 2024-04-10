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
const ll N=67;
const ll M=4e4+7;
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
ll n,c1=0,c2=0,iv2;
ll a[N],s[N],t[N],tc[N],g[M],f[N][M],sz[N],fac[N],inv[N],fa[N];
ll ff(ll x){return (fa[x]==x)?x:fa[x]=ff(fa[x]);}
ll C(ll x,ll y){if(x<y||y<0)return 0; return fac[x]*inv[y]%mod*inv[x-y]%mod;}
void mer(ll x,ll y){
	ll u=ff(x),v=ff(y);
	if(u!=v){
		fa[u]=v;
		sz[v]+=sz[u];
	}
}
ll rs[N],rt[N],rc[N],ts[N];
ll solve(ll x){
	ll cnt1=0,cnt2=0;
	rep0(i,c1)if(ff(i)==x)rs[cnt1++]=s[i];
	rep0(i,c2){
		if(ff(i+c1)==x){
			rc[cnt2]=tc[i];
			rt[cnt2++]=t[i];
		}
	}
	if(!cnt1||!cnt2)return 1;
	rep0(i,(1<<cnt1))g[i]=0;
	rep0(i,cnt2){
		ts[i]=0;
		rep0(j,cnt1)if(rt[i]%rs[j]==0)ts[i]|=(1<<j);
		g[ts[i]]+=rc[i];
	}
	rep0(i,cnt1)rep0(j,(1<<cnt1))if((j>>i)&1)g[j]+=g[j-(1<<i)];
	rep(i,cnt2)rep0(j,(1<<cnt1))f[i][j]=0;
	rep0(i,cnt2){
		ll u=rc[i];
		rep0(j,cnt1)if(rs[j]==rt[i])u=u*iv2%mod*(rc[i]+1)%mod;
		f[1][ts[i]]=(f[1][ts[i]]+u)%mod;
	}
	rep(i,cnt2-1){
		rep0(j,(1<<cnt1)){
			if(i<g[j])f[i+1][j]=(f[i+1][j]+f[i][j]*(g[j]-i))%mod;
			rep0(k,cnt2){
				if((ts[k]|j)==j||!(ts[k]&j))continue;
				f[i+1][j|ts[k]]=(f[i+1][j|ts[k]]+f[i][j])%mod;
			}
		}
	}
	return f[cnt2][(1<<cnt1)-1];
} 
int main(){
	iv2=Pow(2,mod-2);
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	rep(i,n){
		bool fl=1;
		rep(j,i-1)if(a[i]%a[j]==0){fl=0; break;}
		if(fl)s[c1++]=a[i];
		else{
			if(!c2||t[c2-1]!=a[i]){
				tc[c2]=1; 
				t[c2++]=a[i];
			}
			else tc[c2-1]++;
		}
	}
	fac[0]=1;
	rep(i,n)fac[i]=fac[i-1]*i%mod;
	inv[n]=Pow(fac[n],mod-2);
	for(ll i=n;i;i--)inv[i-1]=inv[i]*i%mod;
	rep0(i,c1+c2)fa[i]=i;
	rep0(i,c2)sz[i+c1]=1;
	rep0(i,c2)rep0(j,c1)if(t[i]%s[j]==0)mer(i+c1,j);
	ll nw=0,ans=1;
	rep0(i,c1+c2){
		if(ff(i)==i){
			if(!sz[i])continue;
			nw+=sz[i]-1;
			ans=ans*C(nw,sz[i]-1)%mod*solve(i)%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}