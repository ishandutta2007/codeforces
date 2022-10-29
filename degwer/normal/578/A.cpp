#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
typedef long double ld;
ld eps=1e-13;
using namespace std;
int main()
{
	double za,zb;
	scanf("%lf%lf",&za,&zb);
	ld a=za,b=zb;
	if(a+eps<b)
	{
		printf("-1\n");
		return 0;
	}
	ld k1=floor((a+b)/(b+b)+eps);
	ld k2=floor((a-b)/(b+b)+eps);
	printf("%.30lf\n",double(min((a+b)/(k1+k1),(a-b)/(k2+k2))));
}