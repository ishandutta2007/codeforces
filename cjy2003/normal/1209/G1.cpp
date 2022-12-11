#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,a[200020],r[200020],cnt[200020],ans;
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)r[a[i]]=i,++cnt[a[i]];
	ans=n;
	for(int i=1;i<=n;++i)
	{
		int rr=i,mx=0;
		for(int j=i;j<=rr;++j)rr=max(rr,r[a[j]]),mx=max(mx,cnt[a[j]]);
		i=rr;
		ans-=mx;
	}
	printf("%d",ans);
	return 0;
}