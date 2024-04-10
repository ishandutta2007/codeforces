#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,b;
int cnt[10010],tot;
long long num[10010],ans=1ll<<62,y[10010];
long long calc(long long x,long long c)
{
	long long sum=0;
	while(c)
	{
		c/=x;
		sum+=c;
	}
	return sum;
}
int main()
{
	scanf("%I64d %I64d",&n,&b);
	for(int i=2;1ll*i*i<=b;++i)
		if(!(b%i))
		{
			y[++tot]=i;
			while(!(b%i))
			{
				b/=i;
				++cnt[tot];
			}
		}
	if(b>1)
	{
		y[++tot]=b;
		cnt[tot]=1;
	}
	for(int i=1;i<=tot;++i)
		num[i]=calc(y[i],n),ans=min(ans,num[i]/cnt[i]);
	printf("%I64d",ans);
	return 0;
}