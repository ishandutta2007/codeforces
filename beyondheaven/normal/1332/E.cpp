#include<bits/stdc++.h>
typedef long long LL;
const LL Mod=998244353;
LL n,m,L,R;
inline LL Pow(LL a,LL b=Mod-2)
{
	a%=Mod;b%=(Mod-1);
	LL res=(a==0?0:1);
	for(;b;b>>=1,a=a*a%Mod)
	if(b&1)res=res*a%Mod;
	return res;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&L,&R);
	LL H=R-L+1;
	if(n*m%2==1)printf("%lld\n",Pow(H,n*m));
	else if(H%2==1)printf("%lld\n",(Pow(H,n*m)+1)*Pow(2)%Mod);
	else printf("%lld\n",(Pow(H,n*m))*Pow(2)%Mod);
	return 0;
}