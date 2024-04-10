#include<stdio.h>
#include<math.h>
double pi=3.1415926535897932384626433832;
int main()
{
    double p,r;
    scanf("%lf%lf",&p,&r);
    printf("%.10lf\n",r*r*p*sin(pi/(p*2))*(sin(pi/p)/sin(pi*3/(p*2))));
}