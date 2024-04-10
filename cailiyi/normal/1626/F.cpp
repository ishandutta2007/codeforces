#include<bits/stdc++.h>
#define mod 998244353
const int N=12252240;
using namespace std;
int n,a0,x,y,k,M,f[N],mul=1;
long long ans;
inline void add(int &a,int b) {if((a+=b)>=mod) a-=mod;}
int main()
{
	scanf("%d %d %d %d %d %d",&n,&a0,&x,&y,&k,&M);
	for(int i=k;i;--i,mul=1ll*mul*(i?n:1)%mod)
		for(int j=N-1;j>=0;--j)
			f[j]=(1ll*(n-1)*f[j]+f[j/i*i]+1ll*j*mul)%mod;
	int temp=1ll*k*mul%mod;
	long long ans1=0,ans2=0;
	for(int i=0;i<n;++i,a0=(1ll*x*a0+y)%M)
		ans1+=(a0/N*N),ans2+=f[a0%N];
	printf("%lld",(ans1%mod*temp+ans2%mod)%mod);
	return 0;
}