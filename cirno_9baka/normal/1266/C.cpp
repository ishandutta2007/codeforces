#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=600005,M=998244353;
int n,m,i,j;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	if(n==1&&m==1)
	{
		puts("0");
		return 0;
	}
	if(m==1)
	{
		for(i=2;i<=n+1;++i)
			printf("%d\n",i);
		printf("\n");
		return 0;
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
			printf("%d ",i*(j+n));
		printf("\n");
	}
}