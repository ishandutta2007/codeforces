#include<bits/stdc++.h>
#define MaxN 123
typedef long long LL;
const LL Mod=1e9+7;

inline LL pow_mod(LL a,LL b)
{
	a%=Mod;b%=(Mod-1);
	if(!b)return a?1:0;
	LL res=1;
	for(;b;b>>=1,a=a*a%Mod)
	if(b&1)res=res*a%Mod;
	return res;
}

LL Fac[MaxN],Inv[MaxN],FInv[MaxN];
inline LL Binom(int n,int m)
{
	if(m<0||m>n)return 0;
	return Fac[n]*FInv[m]%Mod*FInv[n-m]%Mod;
}

LL sav[MaxN][2];
LL dp[MaxN][MaxN*MaxN];

int main()
{
	int n,k;LL m;
	std::cin>>n>>m>>k;
	
	Fac[0]=FInv[0]=Fac[1]=Inv[1]=FInv[1]=1;
	for(int i=2;i<=n;++i)
	{
		Fac[i]=Fac[i-1]*i%Mod;
		Inv[i]=(Mod-Mod/i)*Inv[Mod%i]%Mod;
		FInv[i]=FInv[i-1]*Inv[i]%Mod;
	}
	
	int tmp1=(m-1)%n+1;
	LL tmp2=(m-1)/n;
	
	#ifdef Dubug
	std::cout<<"tmp1 = "<<tmp1<<std::endl;
	std::cout<<"tmp2 = "<<tmp2<<std::endl;
	#endif
	
	for(int j=0;j<=n;++j)
	{
		sav[j][0]=pow_mod(Binom(n,j),tmp2);
		sav[j][1]=pow_mod(Binom(n,j),tmp2+1);
	}
	
	for(int j=0;j<=std::min(n,k);++j)
	dp[1][j]=sav[j][(1<=tmp1?1:0)];
	
	for(int i=2;i<=n;++i)
	for(int j=0;j<=k;++j)
	for(int p=0;p<=n;++p)
	if(j>=p)
	dp[i][j]=(dp[i][j]+dp[i-1][j-p]*sav[p][(i<=tmp1?1:0)])%Mod;
	
	std::cout<<dp[n][k]<<std::endl;
	return 0;
}