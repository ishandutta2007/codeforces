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
int n,m,i,j,x=1,y=2,cnt;
string st;
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d %d\n",1000003,1000003);
	for (i=2;i<n;i++)
	{
		m--;
		printf("%d %d %d\n",i,i+1,1);
		cnt++;
	}
	printf("1 2 %d\n",1000003-cnt);
	m--;
	while (m--)
	{
		do
		{
			y++;
			if (y>n)
			{
				x++;
				y=x+2;
			}
		}
		while (x+1==y);
		printf("%d %d 10000000\n",x,y);
	}
	return 0;
}