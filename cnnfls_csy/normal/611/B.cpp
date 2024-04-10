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
long long n,m,i,j,k,x,s;
int main()
{
	cin>>n>>m;
	for (i=2;i<=63;i++)
	{
		for (j=2;j<=i;j++)
		{
			x=0;
			for (k=1;k<=i;k++)
			{
				x*=2;
				if (k!=j) x++;
			}
			if (x>=n&&x<=m) s++;
		}
	}
	cout<<s;
	return 0;
}