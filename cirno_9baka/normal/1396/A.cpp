#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=998244353;
int n,i;
long long a[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	printf("1 1\n");
	printf("%lld\n",n-a[1]%n);
	a[1]+=n-a[1]%n;
	if(n==1)
	{
		printf("1 1\n");
		printf("0\n");
	}
	else
	{
		printf("2 %d\n",n);
		for(i=2;i<=n;++i)
		{
			printf("%lld ",(a[i]%n)*(n-1));
			a[i]+=(a[i]%n)*(n-1);
		}
		printf("\n");
	}
	printf("1 %d\n",n);
	for(i=1;i<=n;++i)
		printf("%lld ",-a[i]);
}