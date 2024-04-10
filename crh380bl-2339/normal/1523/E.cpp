#include<bits/stdc++.h>
#define mod 1000000007
#define N 300005
#define ll long long
using namespace std;
ll fac[N],_fac[N],p[N],q[N];
ll C(ll x,ll y){
	if(x<y)return 0;
	return fac[x]*_fac[y]%mod*_fac[x-y]%mod;
}
ll ksm(ll x,int y){
	ll t=1;
	while(y){
		if(y&1)t=t*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return t;
}
int main(){
	int n,k,i,j;int T;scanf("%d",&T);
	fac[0]=_fac[0]=1;
	for(i=1;i<N;++i){
		fac[i]=fac[i-1]*i%mod;
		_fac[i]=ksm(fac[i],mod-2);
	}
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;++i)p[i]=q[i]=0;
		for(i=1;i<=n&&(n+k>i*(k-1));++i){
			p[i]=C(n+k-1-i*(k-1),i)*fac[i]%mod;
		}
		for(i=2;i<=n;++i){
			q[i]=((p[i-1]*(n-i+1)-p[i])%mod+mod)%mod;
			q[i]=(q[i]*_fac[n]%mod*fac[n-i]%mod);
		}
		ll C=0,D=0;
		for(i=2;i<=n;++i){
			C=(C+q[i]*i)%mod;
			D=(D+q[i])%mod;
		}
		printf("%lld\n",C*ksm(D,mod-2)%mod);
	}
	return 0;
}