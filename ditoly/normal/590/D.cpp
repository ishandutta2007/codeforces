#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 150
#define MX 5625
int f[MN+5][MX+5]; 
int main()
{
	int n,m,s,x,i,j,k;
	scanf("%d%d%d",&n,&m,&s);
	memset(f,40,sizeof(f));
	for(i=0;i<=s&&i<=MX;++i)f[0][i]=0;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&x);
		for(j=min(i,m);j;--j)for(k=i-j;k<=s&&k<=MX;++k)
			f[j][k]=min(f[j][k],f[j-1][k-i+j]+x);
	}
	printf("%d",f[m][min(s,MX)]);
}