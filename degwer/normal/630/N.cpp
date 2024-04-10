#include<stdio.h>
#include<math.h>
using namespace std;
typedef long double ld;
int main()
{
    double p,q,r;
    scanf("%lf%lf%lf",&p,&q,&r);
    ld a=p,b=q,c=r;
    if(a<0)
    {
        a=-a;
        b=-b;
        c=-c;
    }
    printf("%lf\n%lf\n",double((-b+sqrt(b*b-4.0*a*c))/(2*a)),double((-b-sqrt(b*b-4.0*a*c))/(2*a)));
}