#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e5+5;
int n,a[N];

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	if(n==1)
	{
		printf("1 1\n");
		printf("%lld\n",-a[1]);
		printf("1 1\n");
		printf("%lld\n",0);
		printf("1 1\n");
		printf("%lld\n",0);
		return 0;
	}
	printf("%lld %lld\n",1,n);
	for(int i=1;i<=n;++i)
	{
		printf("%lld ",n*(-a[i]));
		a[i]+=n*(-a[i]);
	}
	printf("\n%lld %lld\n",1,n-1);
	for(int i=1;i<=n-1;++i)
		printf("%lld ",-a[i]);
	printf("\n%lld %lld\n",n,n);
	printf("%lld\n",-a[n]);
	return 0;
}