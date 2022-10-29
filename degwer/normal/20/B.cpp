#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	if(a==0)
	{
		if(b==0)
		{
			if(c==0)
			{
				printf("-1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			printf("1\n");
			printf("%.10lf\n",double(-c)/double(b));
		}
		return 0;
	}
	if(b*b-4*a*c<0)
	{
		printf("0\n");
		return 0;
	}
	if(b*b==4*a*c)
	{
		printf("1\n");
		printf("%.10lf\n",double(-b)/double(2*a));
	}
	else
	{
		printf("2\n");
		if(a>0)
		{
			printf("%.10lf\n",double(-b-sqrt(double(b*b-4*a*c)))/double(2*a));
			printf("%.10lf\n",double(-b+sqrt(double(b*b-4*a*c)))/double(2*a));
		}
		else
		{
			printf("%.10lf\n",double(-b+sqrt(double(b*b-4*a*c)))/double(2*a));
			printf("%.10lf\n",double(-b-sqrt(double(b*b-4*a*c)))/double(2*a));
		}
	}
}