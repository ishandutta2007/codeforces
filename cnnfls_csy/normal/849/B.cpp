#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j;
double y[1005];
set<double> s;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>y[i];
	}
	for (i=1;i<=n;i++)
	{
		 s.insert((y[2]-y[1])*(i-1)-y[i]);
	}
	if (s.size()==2)
	{
		cout<<"Yes";
		return 0;
	}
	s.clear();
	for (i=1;i<=n;i++)
	{
		 s.insert((y[3]-y[2])*(i-1)-y[i]);
	}
	if (s.size()==2)
	{
		cout<<"Yes";
		return 0;
	}
	s.clear();
	for (i=1;i<=n;i++)
	{
		 s.insert((y[3]-y[1])/2.0*(i-1)-y[i]);
	}
	if (s.size()==2)
	{
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
	return 0;
}