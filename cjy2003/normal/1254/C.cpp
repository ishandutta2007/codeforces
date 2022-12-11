#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
pair<long long,int>s[1010];
int st[1010],h,t,id[1010];
int main()
{
	scanf("%d",&n);
	int p=2,x;
	for(int i=3;i<=n;++i)
	{
		printf("2 1 %d %d\n",p,i);
		fflush(stdout);
		scanf("%d",&x);
		if(x<0)p=i;
	}
	int q;
	long long mx=0;
	for(int i=2;i<=n;++i)
	{
		if(p==i)s[i].first=0,s[i].second=i;
		else
		{
			printf("1 1 %d %d\n",p,i);
			fflush(stdout);
			scanf("%lld",&s[i].first);s[i].second=i;
			if(s[i].first>mx)mx=s[i].first,q=i;			
		}
	}
	for(int i=2;i<=n;++i)
		if(q!=i)
		{
			printf("2 1 %d %d\n",q,i);
			fflush(stdout);
			scanf("%d",&x);
			if(x<0)id[i]=1;
			else id[i]=2;
		}
	sort(s+2,s+1+n);
	st[1]=1;h=1,t=n+1;
	for(int i=2;i<=n;++i)
	{
		if(id[s[i].second]==1)st[++h]=s[i].second;
		else if(id[s[i].second]==2)st[--t]=s[i].second;
	}
	st[++h]=q;
	printf("0 ");
	for(int i=1;i<=n;++i)printf("%d ",st[i]);
	fflush(stdout);
	return 0;
}