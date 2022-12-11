#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[200020];
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]<0?a[i]=-a[i]:0;
	sort(a+1,a+1+n);
	int last=-1,sum=0;
	for(int i=1;i<=n;++i)
	{
		ans+=upper_bound(a+1,a+1+n,2*a[i])-upper_bound(a+1,a+1+n,a[i]);
		if(a[i]!=last)sum=0,last=a[i];
		ans+=sum;
		++sum;
	}
	printf("%lld",ans);
	return 0;
}