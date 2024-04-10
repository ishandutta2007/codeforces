#include<cstdio>
#include<algorithm>
using namespace std;
int s[1000010][10],l,r,k,g[1000010];
int fuck(int x)
{
	int ans=1;
	for(;x;x/=10)
	{
		if(x%10)
		{
			ans*=x%10;
		}
	}
	return ans;
}
int main()
{
	for(int i=1;i<=9;i++)
	{
		g[i]=i;
	}
	for(int i=10;i<=1000000;i++)
	{
		g[i]=g[fuck(i)];
	}
	for(int i=1;i<=1000000;i++)
	{
		for(int j=1;j<=9;j++)
		{
			s[i][j]=s[i-1][j];
		}
		s[i][g[i]]++;
	}
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",s[r][k]-s[l-1][k]);
	}
	return 0;
}