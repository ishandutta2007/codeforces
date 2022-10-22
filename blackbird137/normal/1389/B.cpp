#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e5+5;
int t,n,k,z,a[N],dp[N][10],ans;

int main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();z=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		ans=0;
		for(int i=1;i<=n;++i)
			if(i-1<=k)
				dp[i][0]=dp[i-1][0]+a[i],ans=max(ans,dp[i][0]);
		for(int i=1;i<=z;++i)
			for(int j=1;j<=n;++j)
				if(j-1+i*2<=k)
				{
					dp[j][i]=max(dp[j-1][i],dp[j+1][i-1])+a[j];
					ans=max(ans,dp[j][i]);
				}
		//for(int i=0;i<=n;++i)
		//	for(int j=0;j<=z;++j)
		//		dp[i][j]=0;
		printf("%d\n",ans);
	}
	return 0;
}