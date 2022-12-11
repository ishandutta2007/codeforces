#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,b[200020];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	long long mx=0;
	for(int i=1;i<=n;++i)
	{
		long long cur=mx+b[i];
		mx=max(mx,cur);
		printf("%lld ",cur);
	}
	return 0;
}