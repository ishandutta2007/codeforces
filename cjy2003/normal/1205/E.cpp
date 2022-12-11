#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,k,su[200020],sunum,ans,po[200020],mu[200020];
bool bj[200020];
void init()
{
	po[0]=1;
	for(int i=1;i<=200000;++i)po[i]=1ll*po[i-1]*k%mod;
	bj[1]=1;mu[1]=1;
	for(int i=2;i<=200000;++i)
	{
		if(!bj[i])su[++sunum]=i,mu[i]=mod-1;
		for(int j=1;j<=sunum&&su[j]*i<=200000;++j)
		{
			bj[su[j]*i]=1;
			if(i%su[j]==0)break;
			mu[i*su[j]]=1ll*mu[i]*(mod-1)%mod;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&k);
	init();
//	for(int i=1;i<=20;++i)printf("%d ",mu[i]);printf("\n");
	for(int d=1;d<=n;++d)
		if(mu[d])
			for(int sg=d;sg<=2*n-2;sg+=d)
				for(int s=sg;s<=2*n-2;s+=sg)
				{
					int g=s/sg,l=max(sg-(n-1)/g,1)-1,r=min(sg-1,(n-1)/g);
//					printf("%d %d %d %d %d\n",d,sg,s,l,r);
					if(l<r)
					{
//						printf("%d %d %d\n",d,sg,s);
						if(sg<=n/g+1)ans=(ans+1ll*po[g]*(r/d-l/d)%mod*mu[d])%mod;
						else ans=(ans+1ll*po[s-n]*(r/d-l/d)%mod*mu[d])%mod;	
					}
				//	if(min(s/g-1,(n-1)/g)>=2)printf("%d %d %d\n",s,g,min(s/g-1,(n-1)/g));	
				}
//	ans=2ll*ans%mod;
//	for(int i=1;i<=n-1;++i)(ans+=po[i])>=mod?ans-=mod:0;
	ans=1ll*ans*kpow(po[n],mod-2)%mod;
	printf("%d",ans);
	return 0;
}