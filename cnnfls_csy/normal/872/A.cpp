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
int n,m,i,j,num[100005],num2[10005],mi=100;
string st;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	for (i=1;i<=m;i++)
	{
		cin>>num2[i];
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (num[i]==num2[j]) mi=min(mi,num[i]);
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			mi=min(mi,num[i]*10+num2[j]);
			mi=min(mi,num2[j]*10+num[i]);
		}
	}
	cout<<mi;
	return 0;
}