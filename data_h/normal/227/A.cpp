#include <cstdio>
#include <cstdlib>
int main()
{
    long long x1, y1, x2, y2, x3, y3;
    scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &x1, &y1, &x2, &y2, &x3, &y3);
    long long tmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (tmp == 0)
    {
        printf("TOWARDS\n");
    }
    else
    if (tmp < 0)
        printf("RIGHT\n");
    else
        printf("LEFT\n");
 
    return 0;
}