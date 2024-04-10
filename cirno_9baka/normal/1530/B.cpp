#include<bits/stdc++.h>
using namespace std;
const int M=998244353,L=5000,N=1000005;
int n,i,t,m,j,a[505][505];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				a[i][j]=0;
		a[n][m]=a[1][1]=a[1][m]=a[n][1]=1;
		for(i=3;i+1<m;i+=2)
			a[1][i]=a[n][i]=1;
		for(i=3;i+1<n;i+=2)
			a[i][1]=a[i][m]=1;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
				printf("%d",a[i][j]);
			printf("\n");
		}
	}
}