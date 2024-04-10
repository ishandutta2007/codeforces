#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int a[6][3]=
{
	0,1,2,
	1,0,2,
	1,2,0,
	2,1,0,
	2,0,1,
	0,2,1
};
int main()
{
	int n,x;
	cin>>n>>x;
	cout<<a[n%6][x];
	return 0;
}