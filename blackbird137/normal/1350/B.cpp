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
int t,n,a[N],b[N],len,dp[N],ans;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		ans=1;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)
		{
			dp[i]=1;
			len=0;
			for(int j=1;j<=sqrt(i);++j)
				if(i%j==0)
				{
					b[++len]=j;
					if(j!=i/j)
						b[++len]=i/j;
				}
				
			for(int j=1;j<=len;++j)
				if(a[b[j]]<a[i])
				{
					dp[i]=max(dp[i],dp[b[j]]+1);
					ans=max(ans,dp[i]);
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}