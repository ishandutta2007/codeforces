#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
char x[4][1024];

int main()
{
    int i, j, k;
    scanf( "%d", &n );
    if ( n % 2 == 0 )
    {
        char z = 'a', y = 'b';
        for ( i = 0; i+1 < n; i=i+2 )
        {
            x[0][i] = z;
            x[0][i+1] = z;
            swap( z, y );
        }
        z = 'c', y = 'd';
        x[1][0] = 't'; x[2][0] = 't';
        x[1][n-1] = 's'; x[2][n-1] = 's';
        for ( i = 1; i+1 < n; i=i+2 )
        {
            x[1][i] = z;
            x[1][i+1] = z;
            x[2][i] = y;
            x[2][i+1] = y;
            swap( z, y );
        }
        z = 'a'; y = 'b';
        for ( i = 0; i+1 < n; i=i+2 )
        {
            x[3][i] = z;
            x[3][i+1] = z;
            swap( z, y );
        }
        x[0][n] = '\0';
        x[1][n] = '\0';
        x[2][n] = '\0';
        x[3][n] = '\0';
        for ( i = 0; i < 4; i++ )
        {
            printf( "%s\n", x[i] );
        }
    }
    else
    {
        char z, y;
        z = 'a'; y = 'b';
        for ( i = 0; i+1 < n; i=i+2 )
        {
            x[0][i] = z;
            x[0][i+1] = z;
            x[1][i] = y;
            x[1][i+1] = y;
            swap( z, y );
        }
        x[0][n-1] = 'x'; x[1][n-1] = 'x';
        x[2][0] = 't'; x[3][0] = 't';
        z = 'c'; y = 'd';
        for ( i = 1; i+1 < n; i=i+2 )
        {
            x[2][i] = z;
            x[2][i+1] = z;
            x[3][i] = y;
            x[3][i+1] = y;
            swap( z, y );
        }
        x[0][n] = '\0';
        x[1][n] = '\0';
        x[2][n] = '\0';
        x[3][n] = '\0';
        for ( i = 0; i < 4; i++ )
        {
            printf( "%s\n", x[i] );
        }
    }
    return 0;
}