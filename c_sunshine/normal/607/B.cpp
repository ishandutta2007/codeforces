#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
int c[505];
int f[505][505];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",c+i),f[i][i]=1;
	for(int i=n;i;i--)
		for(int j=i+1;j<=n;j++)
		{
			f[i][j]=n+1;
			for(int k=i;k<j;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
			if(c[i]==c[j])f[i][j]=min(f[i][j],max(1,f[i+1][j-1]));
		}
	printf("%d\n",f[1][n]);
	return 0;
}