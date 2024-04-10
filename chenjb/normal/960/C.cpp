#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define inf 1000000007
using namespace std;
long long X,d;
long long fuck(long long x)
{ 
	long long s=1; 
	while (1)
	{
		long long tmp=1;
		tmp=tmp<<(s+1);
		tmp-=1;
		if (tmp<=x)s++; else break;
	} 
	return s; 
}
long long a[10005];
int main()
{
	long long ans=0;
	cin>>X>>d;
	long long now;
	now=1;
	while (X)
	{
		long long p=fuck(X); X-=(1<<p)-1;
		for(int i=1;i<=p;i++)a[++ans]=now;
		now+=inf;
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)printf("%lld%c",a[i],i==ans?'\n':' ');
	return 0;
}