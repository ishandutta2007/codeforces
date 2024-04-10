#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include<iomanip>
#define sqr(x) (x)*(x)
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
long double pi=acos(double(-1));
ll n,m,i,j,x[1005],y[1005],r[1005],dep[1005],s;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>r[i];
	}
	for (i=1;i<n;i++)
	{
		for (j=i+1;j<=n;j++)
		{
			if (r[i]<r[j])
			{
				swap(x[i],x[j]);
				swap(y[i],y[j]);
				swap(r[i],r[j]);
			} 
		}
	}
	for (i=1;i<=n;i++)
	{
		dep[i]=0;
		for (j=1;j<i;j++)
		{
			if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=r[j]*r[j])
			{
				dep[i]=max(dep[i],dep[j]);
			}
		}
		dep[i]++;
	}
	for (i=1;i<=n;i++)
	{
		if (dep[i]==1||!(dep[i]%2))
		{
			s+=sqr(r[i]);
		}
		else s-=sqr(r[i]);
	}
	cout<<setprecision(10)<<fixed<<pi*s;
	return 0;
}