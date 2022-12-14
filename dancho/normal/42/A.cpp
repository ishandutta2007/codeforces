#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
double a[32], b[32];

double V, x, sa;

int main()
{
    int i, j, k;

    scanf( "%d %lf", &n, &V );
    sa = 0;
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%lf", &a[i] );
        sa = sa + a[i];
    }

    for ( i = 1; i <= n; i++ )
    {
        scanf( "%lf", &b[i] );
    }

    x = (1<<29);
    for ( i = 1; i <= n; i++ )
    {
        x = min( x, b[i]/a[i] );
    }

    x = min( x, V/sa );
    printf( "%lf\n", x*sa );
    return 0;
}