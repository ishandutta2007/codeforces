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
const ll N=57;
const ll INF=1e9+7;
const ll mod=998244353;
ll f[N][N*2][N*2];
ll a[N],w[N],iv[N*N*3];
ll n,m,sw=0,cc=0;
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
	scanf("%I64d%I64d",&n,&m);
	rep(i,n)scanf("%I64d",&a[i]);
	rep(i,n)scanf("%I64d",&w[i]);
	rep(i,n){
		sw+=w[i];
		if(a[i])cc+=w[i];
		else cc-=w[i];
	}
	rep(i,sw+m)iv[i]=Pow(i,mod-2);
	rep(o,n){
		memset(f,0,sizeof(f));
		f[0][N][w[o]]=1;
		rep0(i,m){
			REP(j,N-i,N+i){
				if(a[o]){
					REP(k,w[o],w[o]+i){
						f[i+1][j+1][k+1]=(f[i+1][j+1][k+1]+k*iv[sw+j-N]%mod*f[i][j][k])%mod;
						f[i+1][j+1][k]=(f[i+1][j+1][k]+((sw+j-N+i+cc)/2-k)*iv[sw+j-N]%mod*f[i][j][k])%mod;
						f[i+1][j-1][k]=(f[i+1][j-1][k]+((sw+j-N-i-cc)/2)*iv[sw+j-N]%mod*f[i][j][k])%mod;
					}
				}
				else{
					REP(k,max(w[o]-i,0ll),w[o]){
						f[i+1][j+1][k]=(f[i+1][j+1][k]+((sw+j-N+i+cc)/2)*iv[sw+j-N]%mod*f[i][j][k])%mod;
						f[i+1][j-1][k]=(f[i+1][j-1][k]+((sw+j-N-i-cc)/2-k)*iv[sw+j-N]%mod*f[i][j][k])%mod;
						f[i+1][j-1][k-1]=(f[i+1][j-1][k-1]+k*iv[sw+j-N]%mod*f[i][j][k])%mod;
					}
				}
			}
		}
		ll ans=0;
		REP(j,N-m,N+m)REP(k,max(w[o]-m,0ll),w[o]+m)ans=(ans+f[m][j][k]*k)%mod;
		printf("%I64d\n",ans);
	}
	return 0;
}