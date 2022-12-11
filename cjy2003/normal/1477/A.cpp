#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int T,n;
long long k,x[200010];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %lld",&n,&k);
		for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
		long long g=0;
		for(int i=2;i<=n;++i)g=gcd(abs(x[i]-x[1]),g);
		if(x[1]==k)printf("YES\n");
		else if((k-x[1])%g==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}