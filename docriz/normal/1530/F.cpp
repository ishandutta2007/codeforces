#include<bits/stdc++.h>
using namespace std;
int a[22][22],dp[1<<21],mb[21][1<<21],ans=0,n,tmp;
const int mod=31607;
int lowbit(int p){return p&-p;}
int M(int x){return x>=mod?x-mod:x;}
int mypow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int neg(int x)
{
	return x%2==0?1:mod-1;
}
int main()
{
	scanf("%d",&n);
	tmp=mypow(10000,mod-2);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]),a[i][j]=a[i][j]*tmp%mod;
	//printf("%d\n",a[0][0]);
	for(int i=0;i<n;i++)
	{
		mb[i][0]=1;
		for(int j=0;j<n;j++)mb[i][1<<j]=a[i][j];
		for(int j=1;j<(1<<n);j++)
		{
			int tp=lowbit(j);
			mb[i][j]=mb[i][j-tp]*mb[i][tp]%mod;
		}
	}
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<(1<<n);j++)dp[j]=neg(__builtin_popcount(j)+__builtin_popcount(i));
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<(1<<n);k++)
			{
				int ng=k;
				if(i&1)ng|=(1<<j);
				if(i&2)ng|=(1<<(n-1-j));
				dp[k]=(dp[k]*mb[j][ng]-dp[k]*mb[j][(1<<n)-1]%mod+mod)%mod;
			}
		}
		//printf("%d:%d %d\n",i,dp[0],dp[1]);
		for(int j=0;j<(1<<n);j++)ans=M(ans+dp[j]);
	}
	//printf("%d\n",ans);
	printf("%d\n",(mod+1-ans)%mod);
	return 0;
}