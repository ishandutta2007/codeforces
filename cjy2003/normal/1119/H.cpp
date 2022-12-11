#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353,inv2=499122177,inv4=748683265;
int kpow(int a,int b)
{
	int s=1;
	while(b)
	{
		if(b&1)s=1ll*s*a%mod;
		b>>=1;
		a=1ll*a*a%mod;
	}
	return s;
}
int n,k;
void fwt(int f[],int lim)
{
	for(int len=1;len<lim;len<<=1)
		for(int j=0;j<lim;j+=len<<1)
			for(int k=0;k<len;++k)
			{
				int a=f[j+k],b=f[j+k+len];
				(f[j+k]=a+b)>=mod?f[j+k]-=mod:0;
				(f[j+k+len]=a+mod-b)>=mod?f[j+k+len]-=mod:0;
			}
}
void ifwt(int f[],int lim)
{
	for(int len=1;len<lim;len<<=1)
		for(int j=0;j<lim;j+=len<<1)
			for(int k=0;k<len;++k)
			{
				int a=f[j+k],b=f[j+k+len];
				(f[j+k]=a+b)>=mod?f[j+k]-=mod:0;
				(f[j+k+len]=a+mod-b)>=mod?f[j+k+len]-=mod:0;
			}
	int iv=kpow(1<<k,mod-2);
	for(int i=0;i<lim;++i)
		f[i]=1ll*f[i]*iv%mod;
}
int x,y,z,f1[1<<17],f2[1<<17],f3[1<<17],all,f[1<<17];
int main()
{
	scanf("%d %d %d %d %d",&n,&k,&x,&y,&z);
	int a,b,c;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d %d",&a,&b,&c);
		all^=a;
		++f1[a^b];
		++f2[a^c];
		++f3[b^c];
	}
	//for(int i=0;i<1<<k;++i)
	//	printf("%d %d %d\n",f1[i],f2[i],f3[i]);
	fwt(f1,1<<k);
	fwt(f2,1<<k);
	fwt(f3,1<<k);
	int A=(1ll*x+y+z)%mod,B=(1ll*x+y+mod-z)%mod,C=(1ll*x+mod-y+z)%mod,D=(1ll*x+mod-y+mod-z)%mod;
	//printf("%d %d %d %d\n",A,B,C,D);
	//for(int i=0;i<1<<k;++i)
	//	printf("%d %d %d\n",f1[i],f2[i],f3[i]);
	for(int i=0;i<1<<k;++i)
	{
		f[i]=1;
		f[i]=1ll*f[i]*kpow(A,1ll*(1ll*n+f1[i]+f2[i]+f3[i])*inv4%mod)%mod;
		f[i]=1ll*f[i]*kpow(B,1ll*(1ll*n+f1[i]+mod-f2[i]+mod-f3[i])*inv4%mod)%mod;
		f[i]=1ll*f[i]*kpow(C,1ll*(1ll*n+mod-f1[i]+f2[i]+mod-f3[i])*inv4%mod)%mod;
		f[i]=1ll*f[i]*kpow(D,1ll*(1ll*n+mod-f1[i]+mod-f2[i]+f3[i])*inv4%mod)%mod;
	//	printf("%d ",f[i]);
	}
	ifwt(f,1<<k);
	for(int i=0;i<1<<k;++i)
		printf("%d ",f[i^all]);
	return 0;
}