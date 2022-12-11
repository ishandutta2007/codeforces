#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[300030];
long long ans1,ans2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(i&1)ans1+=a[i]/2,ans2+=(a[i]+1)/2;
		else ans2+=a[i]/2,ans1+=(a[i]+1)/2;
	}
	printf("%lld",min(ans1,ans2));
	return 0;
}