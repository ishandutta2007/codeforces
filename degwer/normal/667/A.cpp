#include<stdio.h>
double pi=3.1415926535;
int main()
{
    double d,h,v,e;
    scanf("%lf%lf%lf%lf",&d,&h,&v,&e);
    double m=(d/2)*(d/2)*pi;
    if(e*m-v>-(1e-6))
    {
        printf("NO\n");
    }
    else printf("YES\n%lf\n",h*m/(v-e*m));
}