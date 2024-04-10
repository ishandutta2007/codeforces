#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 2010
using namespace std;
int f[N][N],n,m,XXX,x,y,s,T;
const int mod=1e9+7,inv2=(mod+1)/2;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&XXX);
		for(int i=1;i<=n;i++)
			for(int j=0;j<=min(m,i);j++)
				f[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=min(m,i);j++)
			{
				if(j==i){f[i][j]=i;continue;}
				x=f[i-1][j-1],y=f[i-1][j];
				f[i][j]=1ll*(x+y)*inv2%mod;
			}
		}
		printf("%lld\n",1ll*f[n][m]*XXX%mod);
	}
}