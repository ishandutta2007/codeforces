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
int n,m,i,j,ans,l,r,p;
int main()
{
	cin>>n>>p>>l>>r;
	if (l==1&&r==n)
	{
		cout<<0;
		return 0;
	}
	if (l==1)
	{
		cout<<abs(r-p)+1;
		return 0;
	}
	if (r==n)
	{
		cout<<abs(l-p)+1;
		return 0;
	}
	cout<<abs(l-r)+min(abs(l-p),abs(r-p))+2;
	return 0;
}