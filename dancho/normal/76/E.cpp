#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
long long x[100020], y[100020];

int main()
{
    int i, j, k;
    long long ans, ap, sx, sy;

    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%I64d %I64d", &x[i], &y[i] );
    }

    ans = 0;
    sx = 0; sy = 0;
    for ( i = 1; i <= n; i++ )
    {
        ans = ans + x[i]*x[i]*(n-1);
        ans = ans + y[i]*y[i]*(n-1);
        sx = sx + x[i];
        sy = sy + y[i];
    }
    for ( i = 1; i <= n; i++ )
    {
        sx = sx - x[i];
        ans = ans - 2*x[i]*sx;
        sy = sy - y[i];
        ans = ans - 2*y[i]*sy;
    }
    printf( "%I64d\n", ans );
    return 0;
}