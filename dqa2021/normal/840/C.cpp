#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
const int MAXW=310;
int fac[320],ifac[320];

int n,w[310];
int val[310],siz[310],idtot,sumsiz[310];
int C(int n,int m)  //last C(x,y) may go out of bound
{
	if (m>n) return 0;
	return 1LL*fac[n]*ifac[n-m]%Mod*ifac[m]%Mod;
}
int dp[310][310];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	for (int i=2;i<=MAXW;i++) fac[i]=1LL*fac[i-1]*i%Mod,ifac[i]=1LL*(Mod-Mod/i)*ifac[Mod%i]%Mod;
	for (int i=2;i<=MAXW;i++) ifac[i]=1LL*ifac[i-1]*ifac[i]%Mod;
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",w+i);
	for (int i=1;i<=n;i++)
	{
		bool flg=false;
		for (int j=1;j<=idtot;j++)
		{
			ll tmp1=1LL*val[j]*w[i],tmp2=sqrt(tmp1);
			if (tmp2*tmp2==tmp1)
			{
				siz[j]++; flg=true;
				break;
			}
		}
		if (flg) continue;
		idtot++;
		val[idtot]=w[i],siz[idtot]=1;
	}
	for (int i=1;i<=idtot;i++) sumsiz[i]=sumsiz[i-1]+siz[i];
	
	dp[1][siz[1]-1]=fac[siz[1]];
	for (int i=2;i<=idtot;i++)  //n and idtot
	{
		for (int j=0;j<=sumsiz[i-1]-i+1;j++)  //modified rbound
		{
			for (int u=1;u<=siz[i];u++)
				for (int v=0;v<=u&&v<=j;v++)
				{
					dp[i][j-v+siz[i]-u]=(dp[i][j-v+siz[i]-u]+1LL*dp[i-1][j]*fac[siz[i]]%Mod*C(siz[i]-1,u-1)%Mod*C(j,v)%Mod*C(sumsiz[i-1]+1-j,u-v))%Mod;
				}
		}
	}
	printf("%d\n",(dp[idtot][0]+Mod)%Mod);
	return 0;
}