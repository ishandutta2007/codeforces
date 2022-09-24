#include <cstdio>

using namespace std;

typedef long long LL;

int main()
{
	LL n,l,r,a,k,i,ans=0;

	scanf("%lld%lld%lld",&n,&l,&r);

	a=n;
	for(k=0;a;) k=k*2+a%2, a/=2;

	for(i=l;i<=r;i++){
		a = (i&(-i));
		ans += ((k&a)!=0);
	}

	printf("%lld\n",ans);

	return 0;
}