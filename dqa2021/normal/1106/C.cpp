#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int n,a[300010];
ll ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	for (int i=1;i+i<=n;i++)
	{
		int tmp=a[i]+a[n-i+1];
		ans+=tmp*tmp;
	}
	printf("%I64d\n",ans);
	return 0;
}