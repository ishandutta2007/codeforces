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
int n,na[1005],nb[1005],i,j,x,y,p[1005],num[1005],sa;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>na[i];
		num[na[i]]++;
	}
	for (i=1;i<=n;i++)
	{
		cin>>nb[i];
	}
	for (i=1;i<=n;i++)
	{
		if (num[i]==2) x=i;
		if (!num[i]) y=i;
	}
	for (i=1;i<=n;i++)
	{
		if (na[i]==x)
		{
			na[i]=y;
			sa=0;
			for (j=1;j<=n;j++)
			{
				if (na[j]==nb[j]) sa++;
			}
			if (sa==n-1)
			{
				for (j=1;j<=n;j++)
				{
					cout<<na[j]<<' ';
				}
				return 0;
			}
			na[i]=x;
		}
	}
	cout<<"error";
	return 0;
}