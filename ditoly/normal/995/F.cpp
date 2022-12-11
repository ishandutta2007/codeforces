#include<cstdio>
#define MN 3000
#define MOD 1000000007
int fa[MN+5],f[MN+5][MN+5],c[MN+5][MN+5],r[MN+5];
int main()
{
	int n,d,i,j,s,ans=0;
	scanf("%d%d",&n,&d);
	for(i=2;i<=n;++i)scanf("%d",&fa[i]);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)f[i][j]=1;
	for(i=n;i;--i)for(s=0,j=1;j<=n;++j)
		f[i][j]=(f[i][j]+f[i][j-1])%MOD,f[fa[i]][j]=1LL*f[fa[i]][j]*f[i][j]%MOD;
	for(i=0;i<=n;++i)for(c[i][0]=j=1;j<=i;++j)c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	for(i=1;i<=n;++i)for(j=1;j<i;++j)f[1][i]=(f[1][i]+MOD-1LL*c[i][j]*f[1][j]%MOD)%MOD;
	for(r[1]=1,i=2;i<=n;++i)r[i]=1LL*(MOD-MOD/i)*r[MOD%i]%MOD;
	for(i=s=1;i<=n&&i<=d;++i)s=1LL*s*(d-i+1)%MOD*r[i]%MOD,ans=(ans+1LL*f[1][i]*s)%MOD;
	printf("%d",ans);
}