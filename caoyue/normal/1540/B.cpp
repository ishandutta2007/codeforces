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
const ll N=407;
const ll INF=1e9+7;
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
ll pos[N],f[N][N],id[N],sm[N];
ll n,num=0,i2,gg;
struct edge{ll v,next;}e[N*2];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void fd(ll x,ll f,ll d,ll v){
	if(x==v){
		gg=d;
		id[x]=d;
		return;
	}
	repG(i,x){
		if(e[i].v==f)continue;
		fd(e[i].v,x,d+1,v);
		if(~gg){
			id[x]=d;
			return;
		}
	}
}
void dfs(ll x){
	repG(i,x){
		if(id[e[i].v]>0)continue;
		id[e[i].v]=id[x];
		dfs(e[i].v);
	}
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%lld",&n);
	rep(i,n-1){
		ll x,y; scanf("%lld%lld",&x,&y);
		add(x,y); add(y,x);
	}
	rep(i,n){
		f[i][0]=1;
		f[0][i]=0;
	}
	ll i2=Pow(2,mod-2);
	rep(j,n)rep(k,n)f[j][k]=(f[j-1][k]+f[j][k-1])*i2%mod;
	ll ans=0;
	rep(i,n){
		REP(j,i+1,n){
			memset(id,-1,sizeof(id));
			gg=-1;
			fd(i,0,1,j);
			rep(k,gg)sm[k]=0;
			rep(k,n)if(~id[k])dfs(k);
			rep(k,n)sm[id[k]]++;
			rep(k,gg)ans=(ans+sm[k]*f[k-1][gg-k])%mod;
		}
	}
	printf("%lld\n",ans*Pow(n,mod-2)%mod);
	return 0;
}