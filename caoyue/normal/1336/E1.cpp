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
const ll N=2e5+7;
const ll INF=1e9+7;
const ll mod=998244353;
const ll M=4e4+7;
ll n,m,ss=0,st=0;
ll a[N],t[50],e[50],f[50],g[40][38][M],b[50],vl[40],bb[M];
ll bc(ll x){
	ll ans=0;
	while(x){
		ans+=(x&1ll);
		x>>=1ll;
	}
	return ans;
} 
void dfs(ll x,ll v){
	if(x==ss+1){
		f[bc(v)]++;
		return;
	}
	dfs(x+1,v);
	dfs(x+1,v^e[x]);
}
int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,n){
		for(ll j=m-1;~j;j--){
			if((a[i]>>j)&1){
				if(!t[j]){
					t[j]=a[i];
					break;
				}
				a[i]^=t[j];
			}
		}
	}
	rep0(i,m)if(t[i])e[++ss]=t[i]; else b[++st]=i;
	ll pw=1;
	rep(i,n-ss)pw=(pw+pw)%mod;
	rep0(i,m)if(t[i])REP(j,i+1,m-1)if((t[j]>>i)&1ll)t[j]^=t[i];
	if(ss<=20){
		dfs(1,0);
		rep0(i,m+1)printf("%lld ",f[i]*pw%mod);
		puts("");
	}
	else {
		ll tt=0;
		rep0(i,m){
			if(t[i]){
				vl[++tt]=0;
				rep(j,st)vl[tt]=(vl[tt]<<1ll)|((t[i]>>b[j])&1ll);
			}
		}
		rep0(i,(1ll<<st)){
			ll nw=i;
			bb[i]=0;
			while(nw){
				bb[i]+=(nw&1ll);
				nw>>=1ll;
			}
		}
		g[0][0][0]=1;
		rep0(j,tt)rep0(k,j+1)rep0(i,(1<<st)){
			g[j+1][k][i]=(g[j+1][k][i]+g[j][k][i])%mod;
			g[j+1][k+1][i^vl[j+1]]=(g[j+1][k+1][i^vl[j+1]]+g[j][k][i])%mod;
		}
		rep0(k,tt+1)rep0(i,(1<<st))f[k+bb[i]]=(f[k+bb[i]]+g[tt][k][i])%mod;
		rep0(i,m+1)printf("%lld ",f[i]*pw%mod);
		puts("");
	}
	return 0;
}