#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cstdlib>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int T;
long long p,q,b;
long long gcd(long long x,long long y)
{
	if (y==0)return x;
	return gcd(y,x%y);
}
bool judge(long long p,long long q,long long b)
{
	long long g=gcd(p,q);
	q/=g;
	while (1)
	{
		long long t=gcd(q,b);
		if (t==1)break;
		while (q%t==0)q/=t;
	}
	if (q==1)return 1; return 0;
}
int main()
{
	cin>>T;
	while (T--)
	{
		scanf("%lld%lld%lld",&p,&q,&b);
		if (judge(p,q,b))puts("Finite"); else puts("Infinite");
	}
	return 0;
}