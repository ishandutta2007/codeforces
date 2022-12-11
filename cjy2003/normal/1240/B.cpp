#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int q,n,a[300030],lp[300030],rp[300030],cnt[300030],ans,d[300030];
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),d[i]=a[i];
		sort(d+1,d+1+n);
		int m=unique(d+1,d+1+n)-d-1;
		for(int i=1;i<=n;++i)a[i]=lower_bound(d+1,d+1+m,a[i])-d;
		for(int i=1;i<=n;++i)
		{
			if(!cnt[a[i]])lp[a[i]]=i;
			++cnt[a[i]];rp[a[i]]=i;
		}
		int r=0,nr;
		ans=m-1;
		for(int i=1;i<=m;++i)
		{
			if(r<i)r=i,nr=rp[i];
			while(r<m&&lp[r+1]>nr)nr=rp[++r];
			ans=min(ans,m-(r-i+1));
		}
		printf("%d\n",ans);
		memset(cnt+1,0,m<<2);
	}
	return 0;
}