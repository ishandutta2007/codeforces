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
int r1,r2,c1,c2,d1,d2,i,j,k,l;
int main()
{
	cin>>r1>>r2>>c1>>c2>>d1>>d2;
	for (i=1;i<=9;i++)
	{
		for (j=1;j<=9;j++)
		{
			for (k=1;k<=9;k++)
			{
				for (l=1;l<=9;l++)
				{
					if (i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l&&i+j==r1&&k+l==r2&&i+k==c1&&j+l==c2&&i+l==d1&&j+k==d2)
					{
						cout<<i<<' '<<j<<endl<<k<<' '<<l;
						return 0;
					}
				}
			}
		}
	}
	cout<<-1;
	return 0;
}