#include<bits/stdc++.h>
#define MaxN 4123
typedef long long LL;
const LL Mod=1e9+7;

LL Fac[MaxN],Inv[MaxN],FInv[MaxN];
inline LL Binom(int n,int m)
{
	if(m<0||m>n)return 0;
	return Fac[n]*FInv[m]%Mod*FInv[n-m]%Mod;
}

LL dp[MaxN][2];
//dp[i][0]: no reflexity
//dp[i][1]: have reflexity

int main()
{
	int n;scanf("%d",&n);
	
	Fac[0]=FInv[0]=Fac[1]=Inv[1]=FInv[1]=1;
	for(int i=2;i<=n;++i)
	{
		Fac[i]=Fac[i-1]*i%Mod;
		Inv[i]=(Mod-Mod/i)*Inv[Mod%i]%Mod;
		FInv[i]=FInv[i-1]*Inv[i]%Mod;
	}
	
	dp[0][1]=1;
	for(int i=1;i<=n;++i)
	{
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%Mod;
		for(int j=1;j<=i;++j)
		{
			dp[i][0]=(dp[i][0]+Binom(i-1,j-1)*dp[i-j][0])%Mod;
			dp[i][1]=(dp[i][1]+Binom(i-1,j-1)*dp[i-j][1])%Mod;
		}
	}
	
	printf("%lld\n",dp[n][0]);
	return 0;
}