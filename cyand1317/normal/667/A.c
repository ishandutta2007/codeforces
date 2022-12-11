#include <stdio.h>
#include <math.h>

int main()
{
    double d, h, v, e;
    scanf("%lf%lf%lf%lf", &d, &h, &v, &e);
    double s = M_PI * d * d / 4;
    double hspd_pour = e;
    double hspd_drink = v / s;
    if (hspd_pour < hspd_drink - 1e-6) {
        puts("YES");
        double time = h / (hspd_drink - hspd_pour);
        printf("%.12lf\n", time);
    } else {
        puts("NO");
    }
    return 0;
}