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
int n,m,i,j,k,x[100005],y[100005],xx[1000005],yy[1000005],l[100005],r[100005],u[100005],d[100005],cl,cr,cu,cd;
int main()
{
	cin>>k>>n>>m;
	for (i=1;i<=k;i++)
	{
		scanf("%d%d%d%d",&x[i],&y[i],&xx[i],&yy[i]);
		if (x[i]>xx[i]) swap(xx[i],x[i]);
		if (y[i]>yy[i]) swap(yy[i],y[i]);
		l[y[i]]++;
		r[yy[i]]++;
		u[x[i]]++;
		d[xx[i]]++;
	}
	for (i=1;i<=100000;i++) u[i]+=u[i-1];
	for (i=100000;i>0;i--) d[i]+=d[i+1];
	for (i=1;i<=100000;i++) l[i]+=l[i-1];
	for (i=100000;i>0;i--) r[i]+=r[i+1];
	cin>>cu>>cd>>cl>>cr;
	for (i=1;i<=k;i++)
	{
		if (l[yy[i]-1]-(y[i]!=yy[i])==cl&&r[y[i]+1]-(y[i]!=yy[i])==cr&&u[xx[i]-1]-(x[i]!=xx[i])==cu&&d[x[i]+1]-(x[i]!=xx[i])==cd)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}