#include<bits/stdc++.h>
#define MaxN 2123

long double dp[MaxN][MaxN];
int main()
{
	int n,t;
	long double p;
	//scanf("%d%Lf%d",&n,&p,&t);
	std::cin>>n>>p>>t;
	dp[0][0]=1;
	for(int i=0;i<t;++i)
	for(int j=0;j<=n;++j)
	{
		if(j==n)dp[i+1][j]+=dp[i][j];
		else
		{
			dp[i+1][j]+=dp[i][j]*(1.-p);
			dp[i+1][j+1]+=dp[i][j]*p;
		}
	}
	
	long double ans=0.;
	for(int j=0;j<=n;++j)
	ans+=dp[t][j]*j;
	std::cout<<std::setprecision(15)<<ans<<std::endl;
	return 0;
}