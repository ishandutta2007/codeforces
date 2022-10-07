#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,i,t,a[N],cnt[N],j;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			cnt[i]=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			++cnt[a[i]];
		}
		a[n+1]=a[n];
		int mx=0;
		for(i=1;i<=n;++i)
			mx=max(mx,cnt[i]);
		if(mx*2-1>n)
		{
			puts("-1");
			continue;
		}
		int as=0,ans=0;
		for(i=1;i<=n;++i)
			cnt[i]=0;
		for(i=1;i<=n;)
		{
			for(j=i;j<=n&&a[j]!=a[j+1];++j);
			++as;
			++cnt[a[i]],++cnt[a[j]];
			i=j+1;
		}
		for(i=1;i<=n;++i)
			cnt[i]-=as;
		ans=as;
		for(i=1;i<=n;++i)
			ans=max(ans,as+cnt[i]-1);
		printf("%d\n",ans-1);
	}
}