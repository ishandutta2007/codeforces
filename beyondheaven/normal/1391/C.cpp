#include<bits/stdc++.h>
#define MaxN 1000123
typedef long long LL;
const LL Mod=1e9+7;

LL Fac[MaxN],Inv[MaxN],FInv[MaxN];
inline LL Binom(int n,int m) 
{
	if(m<0||m>n)return 0;
	return Fac[n]*FInv[m]%Mod*FInv[n-m]%Mod;
}

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
	
	LL ans=0;
	for(int i=1;i<=n;++i)
	ans=(ans+Binom(n-1,i-1))%Mod;
	
	printf("%lld\n",(Fac[n]+Mod-ans)%Mod);
	return 0;
}