#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
long long a[300030];
long long ans,sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d",&a[i]);
		long long s=min(sum,a[i]/2);
		sum-=s;
		ans+=s;
		a[i]-=2*s;
		ans+=a[i]/3;
		sum+=a[i]%3;
	} 
	printf("%I64d",ans);
	return 0;
}