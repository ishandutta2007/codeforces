#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
#define inf 1000000007
using namespace std;
int n;
int a[400000];
LL ans;
LL pw(int x)
{
	if (x==0)return 1;
	if (x==1)return 2;
	LL t=pw(x/2);
	t=t*t%inf;
	if (x%2==1)t=t*2%inf;
	return t;
}
int main()
{	
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ans=0;
	LL tmp=0;
	for(int i=2;i<=n;i++)
	{
		LL d=a[i]-a[i-1];
		LL t=(pw(i-1)-1)*(pw(n-i+1)-1)%inf;
		d=d*t%inf;
		ans=(ans+d)%inf;
	}
	cout<<ans<<endl;
	return 0;
}