#include<stdio.h>
#include<math.h>
typedef long double ld;
ld pi=3.1415926535897932384626433832;
int main()
{
    ld s=0;
    for(int i=3;i<=5;i++)
    {
        double t;
        scanf("%lf",&t);
        ld z=t;
        s+=z*z*z*(sqrt(1.0-1.0/(4.0*sin(pi/i)*sin(pi/i)))*cos(pi/i)*i/(sin(pi/i)*4.0*3.0));
        //printf("%lf\n",sqrt(1.0-1.0/(4.0*sin(pi/i)*sin(pi/i)))*cos(pi/i)*i/(sin(pi/i)*4.0*3.0));
    }
    printf("%.12lf\n",double(s));
}