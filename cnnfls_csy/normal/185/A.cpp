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
long long m1=1000000007,m2=2000000014,n,m,i,j,x,y;
long long x2(long long x)
{
	long long t;
	if (!x) return 1;
	t=sqr(x2(x>>1)%m2)%m2;
	if (x&1) return t*2%m2;
	else return t%m2;
}
long long x4(long long x)
{
	long long t;
	if (!x) return 1;
	t=sqr(x4(x>>1)%m2)%m2;
	if (x&1) return t*4%m2;
	else return t%m2;
}
int main()
{
	cin>>n;
	cout<<(x2(n)+x4(n))%m2/2%m1;
	return 0;
}