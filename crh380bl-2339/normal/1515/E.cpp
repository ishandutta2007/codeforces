#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[404][404],t[404],fac[404],inv[404],M;
ll ksm(ll x,int y){
	ll t=1;
	while(y){
		if(y&1)t=t*x%M;
		x=x*x%M;
		y>>=1;
	}
	return t;
}
ll C(int n,int m){
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
int main(){
	int n,i,j,k;
	ll ans=0;;
	scanf("%d%lld",&n,&M);
	t[1]=1;
	fac[0]=1;
	for(i=1;i<=n;++i)fac[i]=fac[i-1]*i%M;
	for(i=0;i<=n;++i)inv[i]=ksm(fac[i],M-2);
	for(i=2;i<=n;++i)t[i]=t[i-1]*2%M;
	for(i=1;i<=n;++i){
		f[i][i]=t[i];
		for(j=2;j<i;++j){
			for(k=1;k<j;++k){
				f[i][k+i-j]=(f[i][k+i-j]+f[j-1][k]*t[i-j]%M*C(k+i-j,k))%M;
			}
		} 
	}
	for(i=1;i<=n;++i)ans+=f[n][i];
	printf("%lld\n",ans%M);
	return 0;
}