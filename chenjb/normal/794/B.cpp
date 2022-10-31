#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;

int main()
{
	int n;
	double h;
	cin>>n>>h;
	for(int i=1;i<n;i++)
	{
		double t=sqrt(double(i)/double(n))*h;
		printf("%.11lf ",t);
	}

	return 0;
}