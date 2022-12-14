#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, x1, y1, x2, y2;

int ia( int x )
{
    if ( x < 0 ) return -x;
    return x;
}

int main()
{
    int i, j, k;
    scanf( "%d %d %d %d %d", &n, &x1, &y1, &x2, &y2 );
    if ( ( x1 == x2 ) && ( x1 == 0 || x1 == n ) )
    {
        printf( "%d\n", ia( y1-y2 ) );
        return 0;
    }
    if ( ( y1 == y2 ) && ( y1 == 0 || y1 == n ) )
    {
        printf( "%d\n", ia( x1-x2 ) );
        return 0;
    }
    if ( x1 > x2 )
    {
        swap( x1, x2 );
        swap( y1, y2 );
    }
    if ( ( x1 == 0 ) && ( y2 == 0 ) )
    {
        printf( "%d\n", y1+x2 );
        return 0;
    }
    if ( ( x1 == 0 ) && ( y2 == n ) )
    {
        printf( "%d\n", n-y1 + x2 );
        return 0;
    }
    if ( ( y1 == 0 ) && ( x2 == n ) )
    {
        printf( "%d\n", y2 + n-x1 );
        return 0;
    }
    if ( ( y1 == n ) && ( x2 == n ) )
    {
        printf( "%d\n", n-x1 + n-y2 );
        return 0;
    }
    if ( ( x1 == 0 ) && ( x2 == n ) )
    {
        printf( "%d\n", n + min( y1+y2, n-y1+n-y2 ) );
        return 0;
    }
    if ( ( ( y1 == 0 ) && ( y2 == n ) ) || ( ( y1 == n ) && ( y2 == 0 ) ) )
    {
        printf( "%d\n", n + min( x1+x2, n-x1+n-x2 ) );
        return 0;
    }
}