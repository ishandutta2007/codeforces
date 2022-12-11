#include<bits/stdc++.h>
#define MaxN 1123
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
	Fac[0]=FInv[0]=Fac[1]=Inv[1]=FInv[1]=1;
	for(int i=2;i<=1000;++i)
	{
		Fac[i]=Fac[i-1]*i%Mod;
		Inv[i]=(Mod-Mod/i)*Inv[Mod%i]%Mod;
		FInv[i]=FInv[i-1]*Inv[i]%Mod;
	}
	
	LL ans=1;
	int k,s=0;scanf("%d",&k);
	for(int i=1,c;i<=k;++i)
	{
		scanf("%d",&c);
		s+=c;
		ans=ans*Binom(s-1,c-1)%Mod;
	}
	
	printf("%lld\n",ans);
	return 0;
}