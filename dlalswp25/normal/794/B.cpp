#include <stdio.h>
#include <math.h>

int n, h;
double area;

int main()
{
    scanf("%d %d", &n, &h);
    
    area = ((double)h / 2 / n);
    
    double k;
    
    for(int i = 1; i < n; i++)
    {
        k = i * area;
        printf("%.10lf ", sqrt(2 * k * h));
    }
    return 0;
}