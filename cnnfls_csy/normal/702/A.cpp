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
int n,num[1000005],i,j,ma;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	for (i=1;i<=n;i=j)
	{
		for (j=i+1;num[j]>num[j-1]&&j<=n;j++);
		ma=max(ma,j-i);
	}
	cout<<ma;
	return 0;
}