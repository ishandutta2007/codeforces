#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
using namespace std;
#define ll long long
struct poi
{
	int x,y;
}a[110000];
int n;
double get(double x0)
{
	double r=0;
	for(int i=1;i<=n;i++)
	{
		double p=(x0-a[i].x)*(x0-a[i].x)+1.0*a[i].y*a[i].y;
		p=p/2.0/a[i].y;
		if (p<0)p=-p;
		r=max(r,p);
	}
	return r;
}
int main()
{
	cin>>n;
	int pos=0,neg=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if (a[i].y>0)pos=1; else neg=1;
	}
	if (pos && neg)
	{
		puts("-1");
		return 0;
	}
	if (neg)
	{
		for(int i=1;i<=n;i++)a[i].y=-a[i].y;
	}
	double L=-1e8,R=1e8;
	for(int i=1;i<=120;i++)
	{
		double x1=L+(R-L)/3;
		double x2=R-(R-L)/3;
		if (get(x1)<get(x2))R=x2; else L=x1;
	}
	printf("%.8f\n",get(L));
	return 0;
}