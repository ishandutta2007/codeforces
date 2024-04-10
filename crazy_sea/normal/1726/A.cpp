#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int T,n,a[5010],ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans=a[n]-a[1];
		for(int i=1;i<n;i++)
			ans=max(ans,a[i]-a[i+1]);
		for(int i=2;i<=n;i++)
			ans=max(ans,a[i]-a[1]);
		for(int i=1;i<n;i++)
			ans=max(ans,a[n]-a[i]);
		printf("%d\n",ans);
	}
}