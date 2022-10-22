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
const ll N=507;
const ll INF=1e9+7;
ll n,m,mod;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll fac[N],inv[N],f[N],g[N],F[N][N],G[N][N];
ll C(ll x,ll y){return fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%lld%lld%lld",&n,&m,&mod);
	fac[0]=1;
	rep(i,n)fac[i]=fac[i-1]*i%mod;
	inv[n]=Pow(fac[n],mod-2);
	for(ll i=n;i;i--)inv[i-1]=inv[i]*i%mod;
	f[0]=1;
	rep(i,n){
		f[i]=g[i]=0;
		rep(j,i){
			f[i]=(f[i]+f[j-1]*f[i-j]%mod*C(i-1,j-1)%mod*(i+1))%mod;
			g[i]=(g[i]+f[j-1]*g[i-j]%mod*C(i-1,j-1)%mod*(i+1))%mod;
			g[i]=(g[i]+g[j-1]*f[i-j]%mod*C(i-1,j-1)%mod*(i+1))%mod;
			g[i]=(g[i]+f[j-1]*f[i-j]%mod*C(i-1,j-1)%mod*((j-1)*j/2+(i-j)*(i-j+1)/2))%mod;
		}
	}
	F[0][0]=1;
	rep(i,n){
		F[i][i]=f[i];
		G[i][i]=g[i];
	}
	rep0(i,n){
		rep0(j,m+1){
			F[i+1][j]=(F[i+1][j]+F[i][j])%mod;
			G[i+1][j]=(G[i+1][j]+G[i][j])%mod;
			rep(k,n){
				if(j+k>m||i+k+1>n)break;
				F[i+k+1][j+k]=(F[i+k+1][j+k]+F[i][j]*f[k]%mod*C(j+k,k))%mod;
				G[i+k+1][j+k]=(G[i+k+1][j+k]+(G[i][j]*f[k]+F[i][j]*g[k])%mod*C(j+k,k))%mod;
			}
		}
	}
	printf("%lld\n",G[n][m]);
	return 0;
}