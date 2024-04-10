#include <cstdio>
#include <cmath>

int main()
{
    double a,b,c,
            d,e,f;
    scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
    double dis = sqrt((a-d)*(a-d) + (b-e)*(b-e));
    double ans;
    if(c < f)
    {
        double t=c;c=f;f=t;
    }
    if(dis >= (c+f)) ans = dis - c - f;
    else if(dis <= (c-f)) ans = c - f - dis;
    else ans = 0;
    printf("%.8f",ans/2);
    return 0;
}