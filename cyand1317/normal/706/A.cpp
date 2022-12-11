#include <cstdio>
#include <cmath>

int a, b, n;
int x_i, y_i, v_i;

int main()
{
    scanf("%d%d%d", &a, &b, &n);

    double ans = 1e18, cur;
    do {
        scanf("%d%d%d", &x_i, &y_i, &v_i);
        cur = sqrt((x_i - a) * (x_i - a) + (y_i - b) * (y_i - b)) / v_i;
        if (ans > cur) ans = cur;
    } while (--n);

    printf("%.12lf\n", ans);
    return 0;
}