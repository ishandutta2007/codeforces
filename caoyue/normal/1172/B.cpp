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
const ll N=2e5+7;
const ll INF=1e9+7;
const ll mod=998244353;
ll n,num=0;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll pos[N],f[N],sz[N],fac[N],d[N];
struct edge{ll v,next;}e[N*2];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(ll x,ll ft){
	sz[x]=1;
	ll nm=0;
	f[x]=1;
	repG(i,x){
		if(e[i].v==ft)continue;
		dfs(e[i].v,x);
		sz[x]+=sz[e[i].v];
		nm++;
		f[x]=f[x]*f[e[i].v]%mod;
	}
	f[x]=f[x]*fac[nm+1]%mod;
}
int main(){
	scanf("%I64d",&n);
	if(n==2){
		puts("2");
		return 0;
	}
	fac[0]=1;
	rep(i,n)fac[i]=fac[i-1]*i%mod;
	memset(pos,-1,sizeof(pos));
	rep(i,n-1){
		ll x,y; scanf("%I64d%I64d",&x,&y);
		add(x,y); add(y,x);
		d[x]++; d[y]++;
	}
	rep(i,n){
		if(d[i]>1){
			dfs(i,0);
			ll ans=0;
			repG(j,i)ans=(ans+sz[e[j].v]*fac[d[i]])%mod;
			ans=(ans+fac[d[i]])%mod;
			repG(j,i)ans=ans*f[e[j].v]%mod;
			printf("%I64d\n",ans);
			return 0;
		}
	}
	return 0;
}