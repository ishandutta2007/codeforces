#include<cstdio>
#define ll long long
#define F(a,b) (f[a][b]-g[a][b]+mod)
#define N 90
#define M 6500
using namespace std;
int n,m,mod,len;
inline int Mod(int a){return a<mod?a:a-mod;}
ll c[N][N],p2[M],f[N][N],g[N][N],h[N][N],s[N][N],ans;
ll chk(int a){return (a&1)?mod-1:1;}
int main()
{
	scanf("%d%d%d",&n,&m,&mod);
	len=n>m?n:m;
	for(int i=0;i<=len;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=Mod(c[i-1][j]+c[i-1][j-1]);
	}
	len=n*m;
	p2[0]=1;
	for(int i=1;i<=len;i++) p2[i]=Mod(p2[i-1]<<1);
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
		{
			s[i][j]=1;
			for(int k=1;k<=j;k++) s[i][j]=s[i][j]*(p2[i]-k)%mod;
		}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=j;k++)
			{
				f[i][j]=(f[i][j]+chk(j-k)*c[j][k]%mod*p2[k*i])%mod;
				h[i][j]=(h[i][j]+chk(j-k)*c[j][k]%mod*s[k][i])%mod;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int x=1+((n&1)&&(i==n));x<=i;x++)
				for(int y=1;y<=j;y++)
					g[i][j]=(g[i][j]+p2[(j-y)*x]*h[x][y]%mod
						*c[i][x]%mod*c[j][y]%mod*F(i-x,j-y))%mod;
	for(int i=0;i<=m;i++) ans=(ans+c[m][i]*F(n,i))%mod;
	printf("%lld",ans);
}