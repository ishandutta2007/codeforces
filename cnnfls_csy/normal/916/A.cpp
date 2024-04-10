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
int n,m,i,j,x,y,cnt;
string st;
int main()
{
	cin>>n>>x>>y;
	while (x/10!=7&&y/10!=7&&x%10!=7&&y%10!=7)
	{
		y-=n;
		cnt++;
		if (y<0)
		{
			y+=60;
			x--;
		}
		if (x<0) x+=24;
	}
	cout<<cnt;
	return 0;
}