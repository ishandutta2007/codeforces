#include<bits/stdc++.h>
#define mod 1000000007
#define N 1000000
int Pow(int n,int x,int r=1) { for(;x;n=1ll*n*n%mod,x>>=1) if(x&1) r=1ll*r*n%mod; return r; }
int n,m,k,T,S,fac[1000005],finv[1000005];
int main() {
	for(int i=fac[0]=1;i<=N;i++) fac[i]=1ll*fac[i-1]*i%mod;
	finv[N]=Pow(fac[N],mod-2);
	for(int i=N;i;i--) finv[i-1]=1ll*finv[i]*i%mod;
	for(scanf("%d",&T);T--;printf("%d\n",Pow(mod+1>>1,n-1,1ll*k*S%mod*fac[n]%mod))) {
		scanf("%d%d%d",&n,&m,&k);
		for(int i=S=0;i<m;i++) S=(S+1ll*finv[i]*finv[n-i]%mod*(m-i))%mod;
	}
}