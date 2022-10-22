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
const ll N=5e5+7;
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
ll X[N],Y[N],pos[N],dp[N][4],sz[N];
ll n,num=0;
struct edge{ll v,next;}e[N*2];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs0(ll x,ll f){
	repG(i,x){
		if(e[i].v!=f){
			dfs0(e[i].v,x);
			sz[x]+=sz[e[i].v];
		}
	}
	sz[x]++;
}
void dfs1(ll x,ll f){
	if(sz[x]==1){
		dp[x][0]=1;
		dp[x][1]=1;
		dp[x][2]=0;
		dp[x][3]=1;
		return;
	}
	repG(i,x)if(e[i].v!=f)dfs1(e[i].v,x);
	dp[x][0]=1;
	dp[x][1]=0;
	bool fl=0;
	ll s1=1,s2=1;
	repG(i,x){
		ll j=e[i].v;
		if(e[i].v==f){
			fl=1;
			continue;
		}
		if(fl)dp[x][0]=(dp[x][0]*(dp[j][2]+dp[j][3]))%mod;
		else dp[x][0]=(dp[x][0]*(dp[j][2]+dp[j][0]))%mod;
		s2=s2*(dp[j][2]+dp[j][3])%mod;
	}
	fl=0;
	repG(i,x){
		ll j=e[i].v;
		if(e[i].v==f){
			fl=1;
			continue;
		}
		s2=s2*Pow(dp[j][2]+dp[j][3],mod-2)%mod;
		if(fl)dp[x][1]=(dp[x][1]+s1*s2%mod*dp[j][1])%mod;
		else dp[x][2]=(dp[x][2]+s1*s2%mod*dp[j][1])%mod;
		s1=s1*(dp[j][2]+dp[j][0])%mod;
	}
	dp[x][1]=(dp[x][1]+s1)%mod;
	dp[x][3]=dp[x][1];
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%lld",&n);
	rep(i,n-1)scanf("%lld%lld",&X[i],&Y[i]);
	add(0,1); add(1,0);
	for(ll i=n-1;i;i--)add(X[i],Y[i]),add(Y[i],X[i]);
	dfs0(0,0);
	dfs1(0,0);
	printf("%lld\n",(dp[1][0]+dp[1][2])%mod);
	return 0;
}