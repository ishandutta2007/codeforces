#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[200010],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ans=a[n/2+1]-a[1];
	for(int i=2;i<=n/2;i++)
		ans=min(ans,a[i+n/2]-a[i]);
	printf("%d",ans);
}