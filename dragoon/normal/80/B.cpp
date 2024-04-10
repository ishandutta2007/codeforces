#include<stdio.h>

int main()
{
    int m,h;
    double ma,ha;

    scanf("%2d:%2d",&h,&m);
    h%=12;
    ha = 360./12*h + (360./12/60*m);
    ma = 360./60*m;
    printf("%lf %lf\n",ha,ma);

    return 0;
}