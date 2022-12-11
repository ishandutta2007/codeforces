#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int q,n;
long long a,b,m,f[100],sum;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld %lld %lld",&a,&b,&m);
		if(a==b)
		{
			printf("1 %lld\n",a);
			continue;
		}
		n=2;
		while((1ll<<n-2)*(a+m)<b)++n;
		if((1ll<<n-2)*(a+1)>b)
		{
			printf("-1\n");
			continue;
		}
		long long c=b-(1ll<<n-2)*a;
		f[1]=a;sum=a;
		for(int i=2;i<n;++i)
		{
			long long w=min(m,c/(1ll<<n-i-1)-1);
			c-=(1ll<<n-i-1)*w;
			f[i]=sum+w;
			sum+=f[i];
		}
		f[n]=b;
		printf("%d ",n);
		for(int i=1;i<=n;++i)
			printf("%lld ",f[i]);
		printf("\n");
	}
	return 0;
}