#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;
int l, r;

int main()
{
    int i, j, k;
    char x[64];

    scanf( "%d %d", &n, &m );
    l = n+1; r = 0;
    for ( i = 1; i <= m; i++ )
    {
        k = 0;
        for ( j = 1; j <= 4; j++ )
        {
            scanf( "%s", x );
            if ( j == 3 )
            {
                if ( x[0] == 'r' )
                    k = 1;
            }
        }
        scanf( "%d", &j );
        if ( k == 0 )
            l = min( l, j );
        else
            r = max( r, j );
    }
    if ( l <= r+1 )
        printf( "%d\n", -1 );
    else printf( "%d\n", l-r-1 );
    return 0;
}