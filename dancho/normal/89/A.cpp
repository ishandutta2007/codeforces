#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long n, m, k;
int a[100020];

int main()
{
    long long i, j, s;
    long long x;

    scanf( "%I64d %I64d %I64d", &n, &m, &k );
    for ( i = 1; i <= n; i++ )
        scanf( "%d", &a[i] );

    if ( ( n%2 == 0 ) )
    {
        printf( "0\n" );
        return 0;
    }
    j = (1<<29);
    for ( i = 1; i <= n; i+=2 )
    {
        j = min( j, (long long)a[i] );
    }

    x = 2*m/(n+1);
    j = min( j, x*k );
    printf( "%I64d\n", j );
    return 0;
}