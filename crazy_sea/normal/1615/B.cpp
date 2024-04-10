#include<cstdio>
#include<algorithm>
using namespace std;
int n,l,r,ans,f[300010][20];
int main()
{
	n=3e5;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<20;j++)
			f[i][j]=f[i-1][j]+((i&(1<<j))!=0);
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		for(int j=0;j<20;j++)
			ans=max(ans,f[r][j]-f[l-1][j]);
		printf("%d\n",r-l+1-ans);ans=0;
	}
}