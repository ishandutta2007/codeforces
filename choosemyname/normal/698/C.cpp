#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
double dp[1050010];
double p[25],ans[25];
int main()
{
	int n,m;
	cin>>n>>m;
	dp[0]=1;
	for(int i=0;i<n;i++)
		cin>>p[i];
//	cout<<(1<<n)<<endl;
	for(int j=0;j<(1<<n);j++)
	{
		if(dp[j]<1e-10)
			continue;
	//	cout<<j<<' '<<dp[j]<<endl;
		int now=0;
		double nowp=0;
		for(int k=0;k<n;k++)
			if(j&(1<<k))
				now++;
			else
				nowp+=p[k];
		if(now==m)
			for(int k=0;k<n;k++)
				if(j&(1<<k))
					ans[k]+=dp[j];
		if(now>=m)
			continue;
		if(nowp<1e-10)
		{
			for(int k=0;k<n;k++)
				if(j&(1<<k))
					ans[k]+=dp[j];
			continue;
		}
		for(int k=0;k<n;k++)
			if((j&(1<<k))==0)
				dp[j|(1<<k)]+=dp[j]*p[k]/nowp;
	}
	for(int k=0;k<n;k++)
		printf("%.10f ",ans[k]);
}