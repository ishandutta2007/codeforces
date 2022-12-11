#include<bits/stdc++.h>
long double _dp[30],*const dp=_dp+15;
int main()
{
	std::string s1,s2;
	std::cin>>s1>>s2;
	int n=s1.length();
	
	int pos=0;
	for(int i=0;i<n;++i)
	pos+=(s1[i]=='+'?1:-1);
	
	dp[0]=1.;
	for(int i=0;i<n;++i)
	{
		long double _tmp[30],*const tmp=_tmp+15;
		memset(_tmp,0,sizeof(_tmp));
		for(int j=-n;j<=n;++j)
		switch(s2[i])
		{
			case '+':
				tmp[j]=dp[j-1];break;
			case '-':
				tmp[j]=dp[j+1];break;
			case '?':
				tmp[j]=.5*dp[j-1]+.5*dp[j+1];break;
		}
		for(int j=-n;j<=n;++j)dp[j]=tmp[j];
	}
	
	//printf("%.15Lf\n",dp[pos]);
	std::cout<<std::setprecision(12)<<dp[pos]<<std::endl;
	return 0;
}