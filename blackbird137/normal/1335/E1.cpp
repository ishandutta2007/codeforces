#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=2005;
int t,n,x,sum[30][N],a,b,ans; 

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=26;++j)
				sum[j][i]=sum[j][i-1];
			x=read();
			sum[x][i]++;
		}
		ans=0;
		for(int i=1;i<=26;++i)
			ans=max(ans,sum[i][n]);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
			{
				a=0;b=0;
				for(int k=1;k<=26;++k)
				{
					a=max(a,min(sum[k][i],sum[k][n]-sum[k][j-1])*2);
					b=max(b,sum[k][j-1]-sum[k][i]);
				}
				ans=max(ans,a+b);
			}
		printf("%d\n",ans);
	}
	return 0;
}