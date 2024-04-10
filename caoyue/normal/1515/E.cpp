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
ll n,mod;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll fac[N],inv[N];
ll tr[N][N],F[N][2*N],rt[N][N],G[N],B[N];
void Inv(){
	int m=2*n+1;
	rep0(i,n+1){
		ll id=-1;
		REP(j,i,n){
			if(F[j][i]%mod){
				id=j;
				break;
			}
		}
		rep0(j,m+1)swap(F[id][j],F[i][j]);
		rep0(j,m+1)F[i][j]=(F[i][j]%mod+mod)%mod;
		ll iv=Pow(F[i][i],mod-2);
		rep0(j,m+1)F[i][j]=F[i][j]*iv%mod;
		rep0(k,n+1){
			if(k==i)continue;
			ll v=(F[k][i]%mod+mod)%mod;
			if(v)rep0(j,m+1)F[k][j]-=F[i][j]*v;
		}
		if(i&8){
			rep0(j,n+1){
				rep0(k,m+1){
					F[j][k]=(F[j][k]%mod+mod)%mod;
				}
			}
		}
	}
	rep0(j,n+1){
		rep0(k,m+1){
			F[j][k]=(F[j][k]%mod+mod)%mod;
		}
	}
}
void trans(ll *a,ll *b,bool s){
	rep0(i,n+1){
		B[i]=a[i];
		if(!s)B[i]=B[i]*inv[i]%mod;
		G[i]=0;
	}
	if(s){
		rep0(i,n+1){
			rep0(j,n+1)G[j]+=rt[i][j]*B[i];
			if(i&8)rep0(j,n+1)G[j]%=mod;
		}
	}
	else{
		rep0(i,n+1){
			rep0(j,n+1)G[j]+=tr[i][j]*B[i];
			if(i&8)rep0(j,n+1)G[j]%=mod;
		}
	}	
	rep0(j,n+1)G[j]%=mod;
	if(s)rep0(i,n+1)G[i]=G[i]*fac[i]%mod;
	rep0(i,n+1)b[i]=G[i];
}
ll f0[N][N],g0[N][N],f1[N][N],g1[N][N],h[N*2];
ll C(ll x,ll y){return fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%lld%lld",&n,&mod);
	fac[0]=1;
	rep(i,n)fac[i]=fac[i-1]*i%mod;
	inv[n]=Pow(fac[n],mod-2);
	for(ll i=n;i;i--)inv[i-1]=inv[i]*i%mod;
	rep0(i,n+1){
		ll nw=1;
		rep0(j,n+1){
			F[i][j]=tr[i][j]=nw;
			F[i][j+n+1]=(i==j);
			nw=nw*i%mod;
		}
	}
	Inv();
	rep0(i,n+1)rep0(j,n+1)rt[i][j]=F[i][j+n+1];
	rep0(i,n+1){
		rep0(j,i){
			swap(tr[i][j],tr[j][i]);
			swap(rt[i][j],rt[j][i]);
		}
	}
	rep0(i,n+1)f0[0][i]=f0[1][i]=(!i);
	trans(f0[0],g0[0],0);
	trans(f0[1],g0[1],0);
	REP(i,2,n){
		rep0(j,n+1)g0[i][j]=0;
		rep0(k,i){
			rep0(j,n+1)g0[i][j]+=g0[k][j]*g0[i-1-k][j];
			if(k&8)rep0(j,n+1)g0[i][j]%=mod;
		}
		rep0(j,n+1)g0[i][j]%=mod;
		trans(g0[i],f0[i]+1,1);
		f0[i][0]=0;
		trans(f0[i],g0[i],0);
	}
	rep0(o,2)rep0(i,n+1)f1[o][i]=(o==i);
	trans(f1[0],g1[0],0);
	trans(f1[1],g1[1],0);
	REP(i,2,n){
		rep0(j,n+1)g1[i][j]=0;
		rep0(k,i){
			rep0(j,n+1)g1[i][j]+=g1[k][j]*g0[i-1-k][j];
			if(k&8)rep0(j,n+1)g1[i][j]%=mod;
		}
		rep0(j,n+1)g1[i][j]%=mod;
		trans(g1[i],f1[i]+1,1);
		f1[i][0]=0;
		trans(f1[i],g1[i],0);
	}
	rep0(j,n+1)h[j]=0;
	rep(i,n){
		rep0(j,n+1)h[j]=(h[j]+g1[i-1][j]*g1[n-i][j])%mod;
	}
	trans(h,h,1);
	ll ans=0;
	rep0(i,n+1)ans=(ans+h[i])%mod;
	printf("%lld\n",ans);
	return 0;
}