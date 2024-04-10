#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
long long s[100010],p[100010],sum[100010],cnt[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%I64d",&s[i]);
	sort(s+1,s+1+n);
	for(int i=n;i;--i)
		s[i]-=s[i-1];
	sort(s+2,s+1+n);
	p[1]=0,sum[1]=0,cnt[1]=n;
	for(int i=2;i<=n;++i)
	{
		p[i]=s[i];
		sum[i]=sum[i-1]+(p[i]-p[i-1])*cnt[i-1];
		cnt[i]=cnt[i-1]-1;
	}
	scanf("%d",&m);
	long long l,r,ans;
	while(m--)
	{
		scanf("%I64d %I64d",&l,&r);
		r-=l-1;
		l=upper_bound(p+1,p+1+n,r)-p-1;
		ans=sum[l]+cnt[l]*(r-p[l]);
		printf("%I64d ",ans);
	}
	return 0;
}