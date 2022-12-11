#include<cstdio>
#define MN 500
int a[MN+5],f[MN+5][MN+5];
int main()
{
	int n,m,b,mod,i,j,k,ans=0;
	scanf("%d%d%d%d",&n,&m,&b,&mod);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(f[0][0]=i=1;i<=n;++i)for(j=1;j<=m;++j)for(k=a[i];k<=b;++k)
		f[j][k]=(f[j][k]+f[j-1][k-a[i]])%mod;
	for(k=0;k<=b;++k)ans=(ans+f[m][k])%mod;
	printf("%d",ans);
}