#include<cstdio>
#include<algorithm>
using namespace std;
int n,mod,a[405],fac[405],invfac[405],dp[405][405];
int mypow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m){return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;}
int M(int x){return x>=mod?x-mod:x;}
int main()
{
	scanf("%d%d",&n,&mod);
	fac[0]=1;
	for(int i=1;i<=400;i++)fac[i]=1ll*fac[i-1]*i%mod;
	invfac[400]=mypow(fac[400],mod-2);
	for(int i=399;i>=0;i--)invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	for(int i=1;i<=400;i++)for(int j=1;j<=i;j++)a[i]=M(a[i]+C(i-1,j-1));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int k=1;k<=j;k++)
			{
				dp[i][j]=(1ll*dp[i][j]+1ll*dp[i-k-1][j-k]*a[k]%mod*C(j,k))%mod;
			}
		}
		dp[i][i]=a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=M(ans+dp[n][i]);
	printf("%d\n",ans);
	return 0;
}