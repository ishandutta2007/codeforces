#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000010];
long long sum,ans=0x3f3f3f3f3f3f3f3f;
void work(long long w)
{
	long long tot=0,now=0;
	for(int i=1;i<=n;++i)
	{
		(now+=a[i])%=w;
		tot+=min(now,w-now);
	}
	ans=min(ans,tot);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum+=a[i];
	if(sum==1)return printf("-1"),0;
	for(int i=2;1ll*i*i<=sum;++i)
		if(sum%i==0)
		{
			work(i);
			while(sum%i==0)sum/=i;
		}
	if(sum>1)work(sum);
	printf("%lld",ans);
	return 0;
}