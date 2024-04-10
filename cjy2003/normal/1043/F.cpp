#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,cnt[300030],mx,x,dp[300030],jc[300030],jcv[300030],inv[300030];
void init()
{
	jc[0]=jc[1]=inv[1]=jcv[0]=jcv[1]=1;
	for(int i=2;i<=300000;++i)
	{
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		jc[i]=1ll*jc[i-1]*i%mod;
		jcv[i]=1ll*jcv[i-1]*inv[i]%mod;
	}
}
int C(int a,int b)
{
	if(a<b)return 0;
	return 1ll*jc[a]*jcv[b]%mod*jcv[a-b]%mod;
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);cnt[x]=1;
		mx=max(mx,x);
	}
	for(int i=1;i<=mx;++i)
		for(int j=2*i;j<=mx;j+=i)
			cnt[i]+=cnt[j];
	for(int i=1;i<=7;++i)
	{
		for(int j=mx;j>=1;--j)
		{
			dp[j]=C(cnt[j],i);
			for(int k=j*2;k<=mx;k+=j)
				(dp[j]+=mod-dp[k])>=mod?dp[j]-=mod:0;
		}
		if(dp[1])
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0; 
	return 0;
}