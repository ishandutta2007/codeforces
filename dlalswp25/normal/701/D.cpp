#include <stdio.h>

int main()
{
    int n, k;
    double l, v1, v2;
    int m;
    
    scanf("%d %lf %lf %lf %d", &n, &l, &v1, &v2, &k);
    if(n % k == 0)   m = n / k;
    else    m = n / k + 1;
    
    if(m == 1)
    {
        printf("%.10f", (double)l / v2);
        return 0;
    }
    
    double t = ((double)l * (v1 + v2)) / (v2 * (v1 + v2 + 2 * v1 * (m - 1)));
    printf("%.10f", (t * (v1 - v2) + l) / v1);
    
    return 0;
}