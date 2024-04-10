#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2010;
typedef long long ll;
ll mod=1000003;
ll n,k,x[maxn],y[maxn],ans,s1,s2,iv[maxn];
ll powmod(ll a,ll x)
{
    ll ret=1ll,nww=a;
    while(x)
    {
        if(x&1)ret=ret*nww%mod;
        nww=nww*nww%mod;x>>=1;
    }
    return ret;
}
ll inv(ll x){return powmod(x,mod-2);}
int main()
{
	n=12;
    for(int i=1;i<=n;i++)
	{
		printf("? %d\n",i);
		fflush(stdout);
		x[i]=i;
		scanf("%I64d",&y[i]);
	}
	for(int i=1;i<=n;i++)
	{
		s2=1ll;
		for(int j=1;j<=n;j++)
			if(i!=j)
				s2=s2*((x[i]-x[j]%mod)%mod)%mod;
		iv[i]=inv(s2);
	}
	for(k=0;k<1000003;k++)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			s1=y[i]%mod;
			for(int j=1;j<=n;j++)if(i!=j)s1=s1*(k-x[j])%mod;
			ans+=s1*iv[i]%mod;ans=(ans+mod)%mod;
		}
		if(ans==0)
		{
			printf("! %I64d",k);
			fflush(stdout);
			return 0;
		}
	}
	printf("! -1");
	fflush(stdout);
    return 0;
}