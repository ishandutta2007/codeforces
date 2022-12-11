#include<cstdio>
#include<algorithm>
#define MaxN 200123
long long a[MaxN],b[MaxN],x[MaxN];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%lld",b+i);
	a[1]=b[1];x[1]=0;
	for(int i=2;i<=n;++i)
	{
		x[i]=std::max(x[i-1],a[i-1]);
		a[i]=b[i]+x[i];
	}
	for(int i=1;i<=n;++i)
	printf("%lld ",a[i]);
	puts("");
	return 0;
}