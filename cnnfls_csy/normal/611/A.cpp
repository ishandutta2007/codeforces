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
	cin>>n>>st>>st;
	if (st[0]=='w')
	{
		if (n==5||n==6)
		{
			cout<<53;
		}
		else cout<<52;
	}
	else
	{
		if (n==31)
		{
			cout<<7;
		}
		else if (n==30)
		{
			cout<<11;
		}
		else cout<<12;
	}
	return 0;
}