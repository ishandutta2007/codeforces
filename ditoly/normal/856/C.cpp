#include<cstdio>
#include<cstring>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 2000
#define MOD 998244353
int a[MN+5],an,b[MN+5],bn,C[MN+5][MN+5],f1[MN+5][MN+5][11],f2[MN+5][MN+5][11],v[100],p[MN+5];
inline int mod(int x){return x<MOD?x:x-MOD;}
inline int f(int n,int m){return m?1LL*p[n]*C[n+m-1][m-1]%MOD:n?0:1;}
int main()
{
	int T,n,i,j,k,x,ans;
	for(p[0]=i=1;i<=MN;++i)p[i]=1LL*p[i-1]*i%MOD;
	for(i=0;i<=MN;++i)for(C[i][0]=j=1;j<=i;++j)C[i][j]=mod(C[i-1][j-1]+C[i-1][j]);
	for(i=0;i<100;++i)v[i]=i%11;
	for(T=read();T--;)
	{
		n=read();an=bn=0;
		for(;n--;(j&1?a[++an]:b[++bn])=x%11)for(k=x=read(),j=0;k;k/=10)++j;
		for(f1[0][0][0]=1,i=1;i<=an;++i)for(j=0;j<=an/2;++j)for(k=0;k<11;++k)
			f1[i][j][k]=mod((j?f1[i-1][j-1][v[k+a[i]]]:0)+f1[i-1][j][v[k+11-a[i]]]);
		for(f2[0][0][0]=1,i=1;i<=bn;++i)for(j=0;j<=bn;++j)for(k=0;k<11;++k)
			f2[i][j][k]=mod((j?f2[i-1][j-1][v[k+b[i]]]:0)+f2[i-1][j][v[k+11-b[i]]]);
		for(j=0;j<11;++j)f1[an][an/2][j]=1LL*f1[an][an/2][j]*p[an/2]%MOD*p[an-an/2]%MOD;
		for(ans=i=0;i<=bn;++i)for(j=0;j<11;++j)
			ans=(ans+1LL*f1[an][an/2][j]*f2[bn][i][v[11-j]]%MOD*f(i,(an+1)/2)%MOD*f(bn-i,an+1-(an+1)/2))%MOD;
		printf("%d\n",ans);
	}
}