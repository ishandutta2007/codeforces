#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
long long x, y, p;

void mmul( int sz, long long a[4][4], long long b[4][4], long long c[4][4] )
{
    int i, j, k;
    for ( i = 1; i <= sz; i++ )
    {
        for ( j = 1; j <= sz; j++ )
        {
            c[i][j] = 0;
            for ( k = 1; k <= sz; k++ )
            {
                c[i][j] = ( c[i][j] + (a[i][k])*(b[k][j])%p )%p;
            }
        }
    }
}

void mcpy( int sz, long long a[4][4], long long b[4][4] )
{
    int i, j;
    for ( i = 1; i <= sz; i++ )
    {
        for ( j = 1; j <= sz; j++ )
            b[i][j] = a[i][j];
    }
}

void fst( int sz, long long m[4][4], long long st )
{
    if ( st < 0 ) return;
    long long a[4][4], b[4][4], r[4][4];
    int i, j, k;
    for ( i = 1; i <= sz; i++ )
    {
        for ( j = 1; j <= sz; j++ )
            r[i][j] = 0;
        r[i][i] = 1;
    }
    while ( st > 0 )
    {
        if ( st % 2 == 1 )
        {
            mcpy( sz, r, a );
            mmul( sz, a, m, r );
        }
        mcpy( sz, m, a );
        mcpy( sz, m, b );
        mmul( sz, a, b, m );
        st = st / 2;
    }
    mcpy( sz, r, m );
}

int main()
{
    int i, j, k;
    int a[2], a1, an;
    long long sol, sum;
    long long soly;
    long long m[4][4];

    scanf( "%d %I64d %I64d %I64d", &n, &x, &y, &p );
    if ( n == 1 )
    {
        scanf( "%d", &k );
        printf( "%d\n", k%p );
        return 0;
    }
    sum = 0;
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%d", &a[i%2] );
        a[i%2] = a[i%2] % p;
        sum = ( sum + a[i%2] ) % p;
        if ( i == 1 ) a1 = a[i%2];
    }

    if ( x == 0 )
        swap( x, y );
    if ( x == 0 )
    {
        printf( "%d\n", sum );
        return 0;
    }
    m[1][1] = 3;
    m[1][2] = ( p - ((a1 + a[n%2])%p) ) % p;
    m[2][1] = 0;
    m[2][2] = 1;
    fst( 2, m, x );
    sol = 0;
    sol = ( ((m[1][1]*sum)%p) + m[1][2] ) % p;
    if ( y == 0 )
    {
        printf( "%I64d\n", sol );
        return 0;
    }

    m[1][1] = 1;
    m[1][2] = 1;
    m[2][1] = 1;
    m[2][2] = 0;
    fst( 2, m, x );
    an = ( ( ( a[(n-1)%2]*m[1][2] ) % p ) + ( ( a[n%2]*m[1][1] ) %p ) ) % p;

    m[1][1] = 3;
    m[1][2] = ( p - (a1 + an) ) % p;
    m[2][1] = 0;
    m[2][2] = 1;
    fst( 2, m, y );
    soly = 0;
    soly = ( ((m[1][1]*sol)%p) + m[1][2] ) % p;

    printf( "%I64d\n", soly );
    return 0;
}