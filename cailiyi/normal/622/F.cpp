#include<iostream>
#include<cstdio>
#include<algorithm>
#define mod 1000000007
#define N 1000010
using namespace std;
int n,k,ifac[N],mul,f[N],ans;
int quick_pow(int x,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1) ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,b>>=1;
	}
	return ret;
}
int inv(int x) {return quick_pow(x,mod-2);}
int main()
{
	scanf("%d %d",&n,&k);
	ifac[0]=mul=1;
	for(int i=1;i<=k+2;++i)
	{
		ifac[i]=1ll*ifac[i-1]*inv(i)%mod;
		f[i]=(f[i-1]+quick_pow(i,k))%mod;
		mul=1ll*mul*(n-i+mod)%mod;
	}
	if(n<=k+2) return printf("%d",f[n]),0;
	for(int i=1;i<=k+2;++i)
		ans=(ans+1ll*f[i]*mul%mod*inv(n-i)%mod*ifac[i-1]%mod*ifac[k+2-i]%mod*((k-i)&1?mod-1:1)%mod)%mod;
	printf("%d",ans);
	return 0;
}