#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
int main()
{
	int t,n;LL a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a=(LL)n*(n+1)/2;
		for(int i=1;i<=n;i<<=1)a-=i+i;
		printf("%I64d\n",a);
	}
	return 0;
}