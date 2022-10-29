#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
double eps=1e-12;
int main()
{
	double a,b,c,d;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	double beg=0.0,end=1000000000000000000.0;
	for(int p=0;p<200;p++)
	{
		double med=(beg+end)/2.0;
		bool f=false;
		for(int i=0;i<4;i++)
		{
			for(int j=-1;j<=1;j+=2)
			{
				for(int k=-1;k<=1;k+=2)
				{
					for(int l=-1;l<=1;l+=2)
					{
						double x=a-med*j;
						double y=b-med*k;
						double z=c-med*l;
						if(fabs(x)<eps)
						{
							if(fabs(y)<eps||fabs(z)<eps)f=true;
							else continue;
						}
						else
						{
							double w=y*z/x;
							if(fabs(d-w)<=med)f=true;
						}
					}
				}
			}
			double t=a;
			a=b;
			b=d;
			d=c;
			c=t;
		}
		if(f)end=med;
		else beg=med;
	}
	printf("%.12lf\n",beg);
}