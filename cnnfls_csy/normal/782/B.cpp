#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
double a[600005],b[600005],l,r,mid;
int n,m,i,j,h;
bool ch(double x)
{
	double ll=0,rr=1e9;
	for (int i=1;i<=n;i++) 
	{
		ll=max(ll,a[i]-b[i]*x);
		rr=min(rr,a[i]+b[i]*x);
	}
	if (ll<rr) return 1;
	return 0; 
} 
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) cin>>b[i];
	l=0;r=1e9;
	for (h=1;h<=1000;h++)
	{
		mid=(l+r)/2;
		if (ch(mid)) r=mid;
		else l=mid;
	}
	printf("%.12lf",mid);
	return 0;
}