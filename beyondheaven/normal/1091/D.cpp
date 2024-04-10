#include<bits/stdc++.h>
#define MaxN 1000123
typedef long long LL;
const LL Mod=998244353;

LL Fac[MaxN],Inv[MaxN],FInv[MaxN];

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
	
	LL ans=1;
	for(int i=1;i<=n;++i)
	ans=(ans+Fac[n]*FInv[i]%Mod*(Fac[i]+Mod-1))%Mod;
	printf("%lld\n",ans);
	return 0;
}