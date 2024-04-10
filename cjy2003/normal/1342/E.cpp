#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,k,jc[200020],jcv[200020];
int C(int a,int b)
{
	return 1ll*jc[a]*jcv[b]%mod*jcv[a-b]%mod;
}
int main()
{
	scanf("%d %d",&n,&k);
	if(k>=n)return printf("0"),0;
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=1ll*jc[i-1]*i%mod;
	jcv[n]=kpow(jc[n],mod-2);
	for(int i=n;i;--i)jcv[i-1]=1ll*jcv[i]*i%mod;
	if(k==0)return printf("%d",jc[n]),0;
	int ans=0;
	for(int i=k;i<=n-1;++i)
	{
	//	printf("%d\n",1ll*kpow(n-i,n)*C(n,i)%mod);
		if((i-k)&1)ans=(ans+1ll*(mod-kpow(n-i,n))*C(n,i)%mod*C(i,k))%mod;
		else ans=(ans+1ll*kpow(n-i,n)*C(n,i)%mod*C(i,k))%mod;
	}
	ans=2ll*ans%mod;
	printf("%d",ans);
	return 0;
}