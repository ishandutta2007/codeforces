#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#define EPS 1e-5
using namespace std;
double m[11][11];
int main()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			double a=i,h=j;
			double v=a*a*h/12;
			double n=h*h+a*a/2;
			double s=sqrt((n*n+n*a*a+n*a*a)*2-n*n-n*n-a*a*a*a)/4;
			m[i][j]=v*3/s;
			//printf("%lf  \n",m[i][j]);
		}
	}
	double a;
	scanf("%lf",&a);
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(fabs(a-m[i][j])<EPS)
			{
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
}