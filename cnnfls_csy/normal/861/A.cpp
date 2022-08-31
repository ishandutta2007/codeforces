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
long long n,m,i,j,c2,c5,x,y;
string st;
int main()
{
	cin>>n>>m;
	y=n;
	while (n%2==0)
	{
		c2++;
		n/=2;
	}
	while (n%5==0)
	{
		c5++;
		n/=5;
	}
	x=min(c2,c5);
	m-=x;
	c2-=x;
	c5-=x;
	while (m>0&&(c2||c5))
	{
		if (c5)
		{
			y*=2;
			c5--;
			m--;
		}
		if (c2)
		{
			y*=5;
			c2--;
			m--;
		}
	}
	while (m>0)
	{
		y*=10;
		m--;
	}
	cout<<y;
	return 0;
}