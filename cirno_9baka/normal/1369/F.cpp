#include<bits/stdc++.h>
using namespace std;
int n,i,j,a,b;
long long l[100005],r[100005];
int Sum(long long n,long long b)
{
	if((n&1)||n/2<b)
		return (n-b)&1;
	else
	{
		n/=2;
		if(n/2<b)
			return 1;
		return Sum(n/2,b);
	}
}
int Sum2(long long n,long long b)
{
	if(n/2<b)
		return 1;
	else
		return Sum(n/2,b);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%lld %lld",&l[i],&r[i]);
	a=0,b=1;
	for(i=n;i>=1;--i)
	{
		int x=Sum2(r[i],l[i]),y=Sum(r[i],l[i]);
		int ta=0,tb=0;
		if(x)
			ta|=a,tb|=b;
		if(y)
			ta|=a^1,tb|=b^1;
		a=ta,b=tb;
	}
	cout<<a<<' '<<b;
}