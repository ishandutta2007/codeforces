
 #include<stdio.h>
#include<math.h>
int main()
{
    double px,py,vx,vy,a,b,c,d;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&px,&py,&vx,&vy,&a,&b,&c,&d);
    double r=sqrt(vx*vx+vy*vy);
    vx/=r;
    vy/=r;
    printf("%.20lf %.20lf\n",px+vx*b,py+vy*b);
    printf("%.20lf %.20lf\n",px-vy*a/2.0,py+vx*a/2.0);
    printf("%.20lf %.20lf\n",px-vy*c/2.0,py+vx*c/2.0);
    printf("%.20lf %.20lf\n",px-vx*d-vy*c/2.0,py-vy*d+vx*c/2.0);
    printf("%.20lf %.20lf\n",px-vx*d+vy*c/2.0,py-vy*d-vx*c/2.0);
    printf("%.20lf %.20lf\n",px+vy*c/2.0,py-vx*c/2.0);
    printf("%.20lf %.20lf\n",px+vy*a/2.0,py-vx*a/2.0);
}