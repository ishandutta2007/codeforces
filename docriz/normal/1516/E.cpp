#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,dp[405][405],c[405],ans[405],sum[405],ot[205];
const int mod=1e9+7;
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
int main()
{
	scanf("%d%d",&n,&k);
	c[0]=1;
	for(int i=1;i<=min(2*k,n);i++)c[i]=1ll*c[i-1]*(n+1-i)%mod*mypow(i,mod-2)%mod;
	dp[2][1]=1;
	for(int i=3;i<=2*k;i++)
	{
		for(int j=(i+1)/2;j<i;j++)
		{
			dp[i][j]=1ll*(i-1)*(dp[i-2][j-1]+dp[i-1][j-1])%mod;
		}
	}
	sum[0]=1;
	//printf("%d ")
	for(int i=1;i<=k;i++)
	{
		//printf("%d\n",i);
		for(int j=i+1;j<=min(n,2*i);j++)ans[i]=(1ll*ans[i]+1ll*c[j]*dp[j][i])%mod;
		int tmp=ans[i];
		if(i>1)tmp=(tmp+sum[i-2])%mod;
		ot[i]=tmp;
		sum[i]=ans[i];
		if(i>1)sum[i]=(sum[i]+sum[i-2])%mod;
	}
	for(int i=1;i<k;i++)printf("%d ",ot[i]);
	printf("%d\n",ot[k]);
	return 0;
}