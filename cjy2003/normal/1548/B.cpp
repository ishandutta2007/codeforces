#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
long long a[200020];
long long gcd(long long a,long long b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
pair<long long,int>t[1000],tmp[1000];
int cnt;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		for(int i=n;i;--i)a[i]=abs(a[i]-a[i-1]);
		int ans=1;
		cnt=0;
		for(int i=2;i<=n;++i)
		{
			int cur=0;
			tmp[cur=1]=make_pair(a[i],i);
			long long last=a[i];
			for(int j=1;j<=cnt;++j)
			{
				long long g=gcd(last,t[j].first);
				if(g!=last)tmp[++cur]=make_pair(g,t[j].second),last=g;
			}
			for(int j=1;j<=cur;++j)t[j]=tmp[j];
			cnt=cur;
			if(t[cnt].first!=1)ans=max(ans,i);
			else ans=max(ans,i-t[cnt].second+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}