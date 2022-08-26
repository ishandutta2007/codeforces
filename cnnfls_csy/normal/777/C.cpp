#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,m,a[100005],b[100005],h[100005],i,j,k,t;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		a[i]=1;
	}
	h[1]=1;
	for (i=2;i<=n;++i)
	{
		h[i]=100005;
		for (j=1;j<=m;j++)
		{
			scanf("%d",&t);
			if (t<b[j]) a[j]=i;
			h[i]=min(h[i],a[j]);
			b[j]=t;
		}
	}
	scanf("%d",&k);
	for (i=1;i<=k;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if (h[r]<=l) printf("Yes\n");else printf("No\n");
	}
	return 0;
}