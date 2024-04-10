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
int n,m,i,j,t,l[1005],r[1005],ti,ans[1005];
int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n;
		memset(ans,0,sizeof(ans));
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
		}
		ti=0;
		for (i=1;i<=n;i++)
		{
			 ti=max(ti,l[i]);
			 if (ti>r[i]) continue;
			 ans[i]=ti;
			 ti++;
		}
		for (i=1;i<=n;i++)
		{
			printf("%d ",ans[i]);
		}
		puts("");
	}
	return 0;
}