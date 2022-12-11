#include<bits/stdc++.h>
#define MaxN 200123
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

LL s[2];

int main()
{
	int n;scanf("%d",&n);
	s[0]=1;
	for(int i=1;i<=n;++i)
	s[i&1]=(s[i&1]+s[(i&1)^1])%Mod;
	printf("%lld\n",s[(n&1)^1]*pow_mod(pow_mod(2,Mod-2),n)%Mod);
	return 0;
}