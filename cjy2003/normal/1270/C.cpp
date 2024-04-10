#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[100010];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long s=0,w=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),s+=a[i],w^=a[i];
		printf("2\n");
		printf("%lld %lld\n",w,s+w);
	}
	return 0;
}