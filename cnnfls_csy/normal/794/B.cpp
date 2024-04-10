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
int n,i;
double h,x,ar;
int main()
{
	cin>>n>>h;
	for (i=1;i<n;i++)
	{
		printf("%.10f ",(double)(sqrt((double)(i)/n))*h);
	}
	return 0;
}