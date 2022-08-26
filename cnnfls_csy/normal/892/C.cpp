#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,num[2005],ans=1ll<<62,cnt,now;
long long gcd(long long x,long long y)
{
	if (y) return gcd(y,x%y);
		else return x;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
		if (num[i]==1)
		{
			cnt++;
		}
	}
	if (cnt)
	{
		cout<<n-cnt;
		return 0;
	}
	for (i=1;i<=n;i++)
	{
		now=num[i];
		for (j=i;j<=n&&now!=1;j++)
		{
			now=gcd(now,num[j]);
		}
		if (now==1)
		{
			ans=min(ans,n-1+j-i);
		}
	}
	if (ans<1ll<<62) cout<<ans-1;
		else cout<<-1;
	return 0;
}