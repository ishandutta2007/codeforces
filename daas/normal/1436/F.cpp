#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=998244353;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,lim=100000,dp[100001],can[100001];
int ksm(int x,int y)
{
	if(y<0)
		return ksm(ksm(x,-y),mod-2);
	int z=1;
	while(y)
	{
		if(y%2)
			z=1ll*z*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return z;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int v=read();
		can[v]=read();
	}
	for(int i=lim;i>=1;--i)
	{
		int cnt1=0,cnt2=0,all=0,flag1=0,flag2=0,flag3=0,flag4=0;
		for(int j=1;i*j<=lim;++j)
		{
			cnt1+=can[i*j];
			cnt2+=can[i*j];
			if(cnt1>=2)
				flag1=1;
			if(cnt1>=3)
				flag2=1;
			cnt1%=mod;
			cnt2%=(mod-1);
			all=(all+1ll*i*j*can[i*j]%mod)%mod;
		}
		for(int j=1;i*j<=lim;++j)
		{
			int v=i*j;
			if(!can[v])
				continue;
			if(flag1)
				dp[i]=(dp[i]+1ll*v*v%mod*can[v]%mod*(cnt1-1+mod)%mod*ksm(2,cnt2-2)%mod)%mod;
			if(flag1)
				dp[i]=(dp[i]+1ll*v*(all-v+mod)%mod*can[v]%mod*ksm(2,cnt2-2)%mod)%mod;
			if(flag2)
				dp[i]=(dp[i]+1ll*v*(all-v+mod)%mod*can[v]%mod*(cnt1-2+mod)%mod*ksm(2,cnt2-3)%mod)%mod;
		}
		for(int j=2;i*j<=lim;++j)
			dp[i]=(dp[i]-dp[i*j]+mod)%mod;
	}
	printf("%d\n",dp[1]);
	return 0;
}