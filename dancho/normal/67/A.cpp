#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
char x[1024];
int a[1024];

int main()
{
    int i, j, k, l;
    scanf( "%d", &n );
    scanf( "%s", x );
    int L = strlen( x );
    for ( i = 1; i <= n; i++ )
    {
        a[i] = 1;
        k = 0;
        l = 0;
        j = i-2;
        while ( ( j >= 0 ) && ( ( x[j] == 'R' ) || ( x[j] == '=' ) ) )
        {
            if ( x[j] == 'R' )
                l--;
            j--;
        }
        a[i] = max( a[i], -l+1 );

        k = 0; l = 0;
        j = i-1;
        while ( ( j < L ) && ( ( x[j] == 'L' ) || ( x[j] == '=' ) ) )
        {
            if ( x[j] == 'L' )
                l--;
            j++;
        }
        a[i] = max( a[i], -l+1 );
        if ( i < n )
            printf( "%d ", a[i] );
        else
            printf( "%d\n", a[i] );
    }
    return 0;
}