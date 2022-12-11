#include<bits/stdc++.h>
#define MaxN 1123
typedef long long LL;
const LL Mod=1e9+7;
int n,x,pos;
LL Fac[MaxN],Inv[MaxN],FInv[MaxN];
inline LL Binom(int n,int m)
{
	if(m>n||m<0)return 0;
	return Fac[n]*FInv[m]%Mod*FInv[n-m]%Mod;
}
int main()
{
	scanf("%d%d%d",&n,&x,&pos);
	Fac[0]=FInv[0]=Fac[1]=Inv[1]=FInv[1]=1;
	for(int i=2;i<=n;++i)
	{
		Fac[i]=Fac[i-1]*i%Mod;
		Inv[i]=(Mod-Mod/i)*Inv[Mod%i]%Mod;
		FInv[i]=FInv[i-1]*Inv[i]%Mod;
	}
	
	int cnt0=0,cnt1=0;
	int L=0,R=n;
	while(L<R)
	{
		int M=(L+R)/2;
		if(pos<M)
		{
			++cnt1;
			#ifdef Dubug
			printf("a[%d]>x\n",M);
			#endif
			R=M;
		}
		else
		{
			#ifdef Dubug
			printf("a[%d]<=x\n",M);
			#endif
			cnt0+=(pos==M?0:1);
			L=M+1;
		}
	}
	
	#ifdef Dubug
	printf("cnt0=%d cnt1=%d\n",cnt0,cnt1);
	#endif
	
	printf("%lld\n",Fac[n-cnt0-cnt1-1]*Binom(x-1,cnt0)%Mod*Fac[cnt0]%Mod*Binom(n-x,cnt1)%Mod*Fac[cnt1]%Mod);
	return 0;
}