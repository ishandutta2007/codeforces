#include<cstdio>
#define ll long long
#define MN 100
#define MOD 1000000007
int c[MN+5][MN+5],f[MN+5][MN*MN+5],p[MN+5];
int pw(int x,ll y)
{
	int r=1;y%=MOD-1;
	for(;y;y>>=1,x=1LL*x*x%MOD)if(y&1)r=1LL*r*x%MOD;
	return r;
}
int main()
{
	int n,k,i,j,l;ll m;
	scanf("%d%I64d%d",&n,&m,&k);
	for(i=0;i<=n;++i)for(c[i][0]=j=1;j<=i;++j)
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	f[0][0]=1;
	for(i=0;i<=n;++i)p[i]=pw(c[n][i],m/n+1);
	for(i=1;i<=m%n;++i)for(j=0;j<=k&&j<=(i-1)*n;++j)
		for(l=0;l<=n&&j+l<=k;++l)f[i][j+l]=(f[i][j+l]+1LL*f[i-1][j]*p[l])%MOD;
	for(i=0;i<=n;++i)p[i]=pw(c[n][i],m/n);
	for(i=m%n;i++<n;)for(j=0;j<=k&&j<=(i-1)*n;++j)
		for(l=0;l<=n&&j+l<=k;++l)f[i][j+l]=(f[i][j+l]+1LL*f[i-1][j]*p[l])%MOD;
	printf("%d",f[n][k]);
}