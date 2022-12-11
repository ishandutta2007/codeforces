#include<bits/stdc++.h>
#define MaxN 1123
typedef long long LL;
const LL Mod=1e9+7;

LL A[MaxN][15],B[MaxN][15];

int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	A[i][1]=B[i][1]=1;
	
	for(int j=2;j<=m;++j)
	for(int i=1;i<=n;++i)
	{
		for(int k=1;k<=i;++k)
		A[i][j]=(A[i][j]+A[k][j-1])%Mod;
		for(int k=i;k<=n;++k)
		B[i][j]=(B[i][j]+B[k][j-1])%Mod;
	}
	
	LL ans=0;
	for(int x=1;x<=n;++x)
	for(int y=x;y<=n;++y)
	ans=(ans+A[x][m]*B[y][m])%Mod;
	
	printf("%lld\n",ans);
	return 0;
}