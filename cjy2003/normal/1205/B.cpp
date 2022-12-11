#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
long long a[100010];
int dis[300],from[300],cnt[70],ans=0x3f3f3f3f;
queue<int>q;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d",&a[i]);
		for(int j=0;j<=60;++j)
			if(a[i]>>j&1)++cnt[j];
	}
	for(int i=0;i<=60;++i)
		if(cnt[i]>=3)
		{
			printf("3\n");
			return 0;
		}
	sort(a+1,a+1+n,cmp);
	while(!a[n]&&n)--n;
	for(int i=1;i<=n;++i)
	{
		memset(dis,0,sizeof(dis));
		dis[i]=1;q.push(i);
		int x,y;
		while(!q.empty())
		{
			x=q.front();q.pop();
			for(int j=1;j<=n;++j)
				if(j!=x&&(a[x]&a[j]))
				{
					if(!dis[j])dis[j]=dis[x]+1,from[j]=x,q.push(j);
					else if(from[x]!=j)ans=min(ans,dis[x]+dis[j]-1);
				}
		}
	}
	if(ans==0x3f3f3f3f)printf("-1\n");
	else printf("%d",ans);
	return 0;
}