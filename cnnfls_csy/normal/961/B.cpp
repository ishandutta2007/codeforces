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
long long n,m,i,j,num[100005],ans,x,mx;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>x;
		if (x==1)
		{
			ans+=num[i];
			num[i]=0;
		}
	}
	mx=ans;
	for (i=1;i<=n;i++)
	{
		ans+=num[i];
		if (i-m>0) ans-=num[i-m];
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}