#include<cstdio>
#include<cstring>
#define MN 200
#define MOD 10007
struct mat{int z[MN*2+5][MN*2+5];}x,y;
inline mat operator*(const mat&a,const mat&b)
{
	mat c;register int i,j,k;
	long long r[MN*2+5][MN*2+5];
	memset(r,0,sizeof(r));
	for(i=1;i<=MN*2;++i)for(j=1;j<=MN*2;++j)
		for(k=1;k<=MN*2;++k)r[i][k]+=a.z[i][j]*b.z[j][k];
	for(i=1;i<=MN*2;++i)for(j=1;j<=MN*2;++j)c.z[i][j]=r[i][j]%MOD;
	return c;
}
char s[MN+5];
int f[MN+5][MN+5][MN+5],ans;
inline void rw(int&a,int b){if((a+=b)>=MOD)a-=MOD;}
int main()
{
	int n,m,i,j,k;
	scanf("%s%d",s+1,&m);n=strlen(s+1);
	for(i=1;i<=MN;++i)
		x.z[i][i]=24,x.z[i][i+1]=1;
	for(i=1;i<=MN/2;++i)
		x.z[MN+i][MN+i]=25,i<MN/2?x.z[MN+i][MN+i+1]=1:0,
		x.z[MN+i][MN+MN/2+i]=1,x.z[MN+MN/2+i][MN+MN/2+i]=26;
	for(i=1;i<=MN+MN;++i)y.z[i][i]=1;
	for(k=n+m>>1;k;k>>=1,x=x*x)if(k&1)y=y*x;
	f[1][n][0]=1;
	for(i=1;i<=n;++i)for(j=n;j>=i;--j)for(k=0;k<=n;++k)if(f[i][j][k])
		if(s[i]==s[j])rw(f[i+1][j-1][k+1],f[i][j][k]);
		else rw(f[i+1][j][k],f[i][j][k]),rw(f[i][j-1][k],f[i][j][k]);
	if((n+m)&1)
	{
		for(i=1;i<=n;++i)for(k=0;k<=n;++k)if(f[i+1][i-1][k])
			ans=(ans+f[i+1][i-1][k]*y.z[MN-n+2*k][MN+MN/2+k]%MOD*26)%MOD;
		for(i=1;i<n;++i)for(k=0;k<=n;++k)if(f[i+1][i][k])
			ans=(ans+f[i+1][i][k]*y.z[MN+1-n+2*k][MN+MN/2+k]%MOD*26)%MOD;
		for(i=1;i<=n;++i)for(k=0;k<=n;++k)if(f[i][i][k])
			ans=(ans+f[i][i][k]*y.z[MN+2-n+2*k][MN+k+1])%MOD;
	}
	else
	{
		for(i=1;i<=n;++i)for(k=0;k<=n;++k)if(f[i+1][i-1][k])
			ans=(ans+f[i+1][i-1][k]*y.z[MN-n+2*k][MN+MN/2+k])%MOD;
		for(i=1;i<n;++i)for(k=0;k<=n;++k)if(f[i+1][i][k])
			ans=(ans+f[i+1][i][k]*y.z[MN+1-n+2*k][MN+MN/2+k])%MOD;
	}
	printf("%d",ans);
}