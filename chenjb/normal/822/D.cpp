#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long 
#define inf 1000000007
using namespace std;
int t0,l,r,i,j,tmp,ans;
LL f[6000000];
bool notprime[6000000];
int prime[6000000],tot;
int main()
{
	scanf("%d%d%d",&t0,&l,&r);
	for(i=2;i<=r;i++)
	{
		if(!notprime[i])
		{
			prime[++tot]=i;
			f[i]=(LL)i*(i-1)/2;
		}
		for(j=1;j<=tot;j++)
		{
			if((LL)prime[j]*i>r)break;
			tmp=prime[j]*i;
			if(!f[tmp])f[tmp]=f[i]+f[prime[j]]*i;
			else f[tmp]=min(f[tmp],f[i]+f[prime[j]]*i);
			notprime[tmp]=1;
		}
	}
	for(i=r;i>=l;i--)ans=((LL)ans*t0+f[i])%inf;
	printf("%d",ans);
}