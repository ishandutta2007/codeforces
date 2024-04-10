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
int n,i,j;
long double m,p,s=0.0,t,xh[100005],csl[100005],l,r,mid;
bool ch(double x)
{
	t=m*x;
	for (i=1;i<=n;i++)
	{
		t+=min(s,csl[i]-x*xh[i]);
	}
	if (t>1e-8) return 1;
	return 0;
}
int main()
{
	cin>>n>>p;
	for (i=1;i<=n;i++)
	{
		scanf("%llf%llf",&xh[i],&csl[i]);
	}
	l=0;r=1e12;
	while (r-l>1e-6)
	{
		m=p;
		mid=(l+r)/2;
		if (ch(mid)) l=mid;
		else r=mid;
	}
	if (mid<(1e12)-(1e11)) cout<<mid;
	else cout<<"-1";
	//cout<<mid;
	return 0;
}