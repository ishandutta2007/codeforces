#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=100005,E=262144;
int n,m,i,j,t,k,a[505][505];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	if(n<=2)
	{
		puts("-1");
		return 0;
	}
	for(i=n;i>3;--i)
		if(i&1)
		{
			for(j=1;j<i;++j)
				a[j][n-i+1]=++k;
			for(j=n-i+1;j<=n;++j)
				a[i][j]=++k;
		}
		else
		{
			for(j=n;j>=n-i+1;--j)
				a[i][j]=++k;
			for(j=i-1;j>=1;--j)
				a[j][n-i+1]=++k;
		}
	a[3][n-2]=4+k;
	a[3][n-1]=5+k;
	a[3][n]=k+8;
	a[2][n-2]=k+9;
	a[2][n-1]=k+3;
	a[2][n]=7+k;
	a[1][n-2]=1+k;
	a[1][n-1]=k+6;
	a[1][n]=2+k;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}