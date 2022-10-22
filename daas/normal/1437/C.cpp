#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[201],dp[201][401],ans;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		sort(a+1,a+n+1);
		memset(dp,0x3f,sizeof(dp));
		ans=0x3f3f3f3f;
		for(int i=1;i<=2*n;++i)
			dp[1][i]=abs(a[1]-i);
		for(int i=2;i<=n;++i)
			for(int j=i;j<=n*2;++j)
				for(int k=i-1;k<j;++k)
					dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(a[i]-j));
		for(int i=n;i<=2*n;++i)
			ans=min(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}