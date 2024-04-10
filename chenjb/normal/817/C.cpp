#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;
LL n,s;
int getdigit(LL x)
{
	LL sum=0;
	while (x!=0)
	{
		sum+=(x%10);
		x/=10;
	}
	return sum;
}
int main()
{
	cin>>n>>s;
	LL l=1;
	LL r=n;
	if (n-getdigit(n)<s)
	{
		cout<<0<<endl;
		return 0;
	}
	while (l<r)
	{
		LL mid=(l+r)/2;
		if (mid-getdigit(mid)<s)l=mid+1;
		else r=mid;
	}
	cout<<n-l+1<<endl;
	return 0;
}