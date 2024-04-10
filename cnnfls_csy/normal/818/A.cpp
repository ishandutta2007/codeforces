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
long long n,m,x;
int main()
{
	cin>>n>>m;
	x=n/2/(m+1);
	cout<<x<<' '<<x*m<<' '<<n-x-x*m;
	return 0;
}