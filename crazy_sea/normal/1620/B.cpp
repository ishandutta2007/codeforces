#include<cstdio>
#include<algorithm>
using namespace std;
int T,x,y,a[1000010],k;
long long ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		for(int i=1;i<=4;i++)
		{
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
				scanf("%d",&a[j]);
			ans=max(ans,1ll*(a[k]-a[1])*((i<3)?y:x));
		}
		printf("%lld\n",ans);
		ans=0;
	}
}