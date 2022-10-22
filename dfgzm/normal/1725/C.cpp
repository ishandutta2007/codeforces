#include<stdio.h>
const int maxn=400005,mod=998244353;
int n,m,ans,tot;
int d[maxn],fac[maxn],nfac[maxn],inv[maxn];
long long all;
long long sum[maxn];
inline int C(int a,int b){
	return a<b? 0:1ll*fac[a]*nfac[b]%mod*nfac[a-b]%mod; 
}
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int main(){
	fac[0]=fac[1]=nfac[0]=nfac[1]=inv[1]=1;
	for(int i=2;i<maxn;i++)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod,nfac[i]=1ll*nfac[i-1]*inv[i]%mod; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]),all+=d[i],sum[i]=sum[i-1]+d[i];
	if(all&1){
		ans=1;
		for(int i=1;i<=n;i++)
			ans=1ll*ans*m%mod;
		printf("%d\n",ans);
		return 0;
	}
	for(int i=0,j=1;i<n;i++){
		while(j<n&&sum[j]-sum[i]<all/2)
			j++;
		if(j<n&&sum[j]-sum[i]==all/2)
			tot++;
	}
	for(int i=0;i<=tot&&i<=m;i++)
		ans=(ans+1ll*C(tot,i)*C(m,i)%mod*ksm(1ll*(m-i)*(m-i-1)%mod,tot-i)%mod*ksm(m-i,n-2*tot)%mod*fac[i])%mod;
	printf("%d\n",ans);
	return 0;
}