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
const ll N=57;
const ll M=262144;
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
ll n,m,ss=0,st=0;
ll t[N],a[N],bc[M],u[N],b[N],g[N],p[N][N],f[N],h[N][N],fac[N],inv[N];
ll Bc(ll x){return bc[x/M/M]+bc[x/M%M]+bc[x%M];}
ll C(ll x,ll y){
	if(x<y||y<0)return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void dfs1(ll x,ll v){
	if(x==ss+1){
		u[Bc(v)]++;
		return;
	}
	dfs1(x+1,v);
	dfs1(x+1,v^t[a[x]]);
}
void dfs2(ll x,ll v,ll s){
	if(x==st+1){
		p[s][Bc(v)]++;
		return;
	}
	dfs2(x+1,v,s);
	dfs2(x+1,v^g[x],s+1);
}
int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,n){
		ll x; scanf("%lld",&x);
		for(ll j=m-1;~j;j--){
			if((x>>j)&1ll){
				if(!t[j]){
					t[j]=x;
					break;
				}
				x^=t[j];
			}
		}
	}
	rep0(i,M){
		ll nw=i;
		bc[i]=0;
		while(nw){
			bc[i]+=(nw&1);
			nw>>=1;
		}
	}
	rep0(i,m)if(t[i])a[++ss]=i;else b[++st]=i;
	ll pw=1;
	rep(i,n-ss)pw=(pw+pw)%mod;
	if(ss<=(m+1)/2){
		dfs1(1,0);
		rep0(i,m+1)printf("%lld ",u[i]*pw%mod);
	}
	else{
		fac[0]=1;
		rep(i,st)fac[i]=fac[i-1]*i%mod;
		inv[st]=Pow(fac[st],mod-2);
		for(ll i=st;i;i--)inv[i-1]=inv[i]*i%mod;
		rep0(i,st+1){
			rep0(j,st+1){
				h[i][j]=0;
				rep0(k,i+1){
					if(k&1)h[i][j]=(h[i][j]-C(i,k)*C(st-i,j-k)%mod+mod)%mod;
					else h[i][j]=(h[i][j]+C(i,k)*C(st-i,j-k))%mod;
				}
			}
		}
		rep0(i,m)if(t[i])REP(j,i+1,m-1)if((t[j]>>i)&1)t[j]^=t[i];
		rep(i,st){
			g[i]=0;
			rep(j,ss)g[i]=(g[i]<<1)|((t[a[j]]>>b[i])&1);
		}
		dfs2(1,0,0);
		rep0(j,ss+1){
			rep0(i,ss+1)f[i]=0;
			f[0]=1;
			rep(i,ss-j)for(ll k=ss;k;k--)f[k]=(f[k]+f[k-1])%mod;
			rep(i,j)for(ll k=ss;k;k--)f[k]=(f[k]-f[k-1]+mod)%mod;
			rep0(i,ss+1)rep0(k,st+1)rep0(o,st+1)u[i+o]=(u[i+o]+p[k][j]*h[k][o]%mod*f[i])%mod;
		}
		ll iv=Pow(Pow(2,st),mod-2);
		rep0(i,m+1)printf("%lld ",u[i]*iv%mod*pw%mod);
		puts("");
	}
	return 0;
}