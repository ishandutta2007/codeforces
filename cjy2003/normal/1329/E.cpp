#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,m;
long long n,k,dis[400040],mi,mx;
pair<long long,long long>p[400040];
int cnt;
bool checkl(long long w)
{
	long long sum=0;
	for(int i=1;i<=m+1;++i)sum+=dis[i]/w-1;
	return sum>=k;
}
long long findl()
{
	long long l,r,mid;
	l=1,r=mi;
	while(l<r)
	{
		mid=l+r+1>>1;
		if(checkl(mid))l=mid;
		else r=mid-1;
	}
	return l;
}
bool checkr(long long w)
{
	long long sum=0;
	for(int i=1;i<=m+1;++i)sum+=(dis[i]-1)/w;
//	printf("checkr%lld %lld\n",w,sum);
	return sum<=k;
}
long long findr()
{
	long long l,r,mid;
	l=1,r=mx;
	while(l<r)
	{
		mid=l+r>>1;
		if(checkr(mid))r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld %d %lld",&n,&m,&k);
		long long last=0,x;
		for(int i=1;i<=m;++i)
		{
			scanf("%lld",&x);
			dis[i]=x-last;last=x;
		}
		dis[m+1]=n-last;
		mi=0x3f3f3f3f3f3f3f3fll;mx=0;
		for(int i=1;i<=m+1;++i)
		{
			if(dis[i]<mi)mi=dis[i];
			if(dis[i]>mx)mx=dis[i];
		}
		long long lmx=findl(),rmi=findr();
	//	printf("%lld %lld\n",lmx,rmi);
		if(lmx>=rmi)
		{
			printf("0\n");
			continue;
		}
		cnt=0;
		for(int i=1;i<=m+1;++i)
			if((dis[i]-1)/rmi>dis[i]/lmx-1)
			{
				static long long lc,rc;
				lc=(dis[i]-1)/rmi;rc=dis[i]/lmx-1;
				p[++cnt]=make_pair(dis[i]/(lc+1),(dis[i]-1)/(rc+1)+1);
			}
		sort(p+1,p+1+cnt);
		long long cur=rmi,ans=0x3f3f3f3f3f3f3f3fll;
		p[cnt+1].first=lmx;
		for(int i=0;i<=cnt;++i)
		{
			cur=max(cur,p[i].second);
			if(p[i].first!=p[i+1].first)ans=min(ans,cur-p[i+1].first);
		}
		printf("%lld\n",ans);
	}
	return 0;
}