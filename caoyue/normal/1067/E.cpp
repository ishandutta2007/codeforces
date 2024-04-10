#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
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
ll n,d2,num=0,ans=0;
ll pos[N],f[N],g[N];
struct edge{ll v,next;}e[N*2];
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(ll x,ll fa){
	ll wp=1;
	repG(i,x){
		if(e[i].v==fa)continue;
		dfs(e[i].v,x);
		wp=(wp*(1-g[e[i].v]*d2%mod+mod)%mod)%mod;
	}
	ans=(ans+1-wp+mod)%mod;
	g[x]=wp;
	f[x]=(1-wp+mod)%mod;
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%I64d",&n);
	d2=Pow(2,mod-2);
	rep(i,n-1){
		ll x,y; scanf("%I64d%I64d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	printf("%I64d\n",ans*Pow(2,n)%mod);
	return 0;
}