#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,num[1000005],num2[1000005],sum[1000005],sum2[1000005],ans;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		sum[i]=sum[i-1]+num[i];
	}
	for (i=1;i<=m;i++)
	{
		scanf("%d",&num2[i]);
		sum2[i]=sum2[i-1]+num2[i];
	}
	for (i=1;i<=n;i++)
	{
		while (j+1<=m&&sum2[j+1]<=sum[i]) j++;
		if (sum[i]==sum2[j]) ans++;
	}
	cout<<ans;
	return 0;
}