#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long n,i,ans=1e18;
	scanf("%lld",&n);
	for(i=1;i<=n;i=n/(n/i)+1)ans=min(ans,i+n/i+bool(n%i));
	printf("%lld",ans<<1);
}