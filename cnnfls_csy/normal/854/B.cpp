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
int n,m,i,j;
string st;
int main()
{
	cin>>n>>m;
	if (!m)	{cout<<"0 0";return 0;}
	if (n==m) {cout<<"0 0";return 0;}
	cout<<1<<' ';
	cout<<min(n-m,m*2);
	return 0;
}