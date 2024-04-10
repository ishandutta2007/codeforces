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
double m,sum,ti[1000005],s,x;
int n,i,j;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		ti[i]=x+ti[i-1];
	}
	for (i=m;i<=n;i++)
	{
		sum+=ti[i]-ti[int(i-m)];
	}
	printf("%.10lf",sum/(n-m+1));
	return 0;
}