#include<bits/stdc++.h>
typedef long long LL;
const LL Mod=998244353;

inline LL pow_mod(LL a,LL b)
{
	a%=Mod;b%=(Mod-1);
	if(!b)return a?1:0;
	LL res=1;
	for(;b;b>>=1,a=a*a%Mod)
	if(b&1)res=res*a%Mod;
	return res;
}

int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		if(i==n)
		{
			printf("%d ",10);
			continue;
		}
		
		LL ans=2*9*pow_mod(10,n-i-1)%Mod;
		
		if(i+2<=n)
		ans=(ans+(n-i-1)*9*9*pow_mod(10,n-i-2))%Mod;
		
		printf("%lld ",ans*10%Mod);
	}
	puts("");
	
	return 0;
}