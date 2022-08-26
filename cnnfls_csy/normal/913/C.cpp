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
long long n,m,i,j,num[35],mi[35],ans;
int main()
{
	cin>>n>>m;
	fill(num+1,num+33+1,1ll<<62);
	for (i=1;i<=n;i++) cin>>num[i];
	for (i=1;i<33;i++) if (num[i+1]>num[i]*2) num[i+1]=num[i]*2;
/*	mi[33]=33;
	for (i=33-1;i;i--)
	{
		if (num[i]<num[mi[i+1]]) mi[i]=i; else mi[i]=mi[i+1];
	}*/
	for (i=1;i<=33;i++)
	{
		if (ans>num[i]) ans=num[i];
		if ((1ll<<(i-1))&m)
		{
			ans+=num[i];
		}
	}
	cout<<ans;
	return 0;
}