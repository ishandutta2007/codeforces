#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
int a, b;
int t[200020];
int br[8];

int f[200020];

int ba[8], bb[8];

int main()
{
    int i, j, k;
    int ra, rb;
    scanf( "%d", &n );
    scanf( "%d %d", &a, &b );

    memset( br, 0, sizeof( br ) );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%d", &t[i] );
        br[t[i]]++;
    }

    if ( a < b )
    {
        ra = a; rb = b;
        ba[5] = min( br[5], ra );
        ra = ra - ba[5];
        ba[4] = min( br[4], ra );
        ra = ra - ba[4];
        ba[3] = min( br[3], ra );
        ra = ra - ba[3];
        ba[2] = min( br[2], ra );
        ra = ra - ba[2];
        ba[1] = min( br[1], ra );
        ra = ra - ba[1];

        for ( i = 1; i <= 5; i++ )
            bb[i] = br[i] - ba[i];
    }
    else if ( a > b )
    {
        ra = a; rb = b;
        bb[5] = min( br[5], rb );
        rb = rb - bb[5];
        bb[4] = min( br[4], rb );
        rb = rb - bb[4];
        bb[3] = min( br[3], rb );
        rb = rb - bb[3];
        bb[2] = min( br[2], rb );
        rb = rb - bb[2];
        bb[1] = min( br[1], rb );
        rb = rb - bb[1];

        for ( i = 1; i <= 5; i++ )
            ba[i] = br[i] - bb[i];
    }
    else
    {
        printf( "1" );
        for ( i = 2; i <= a; i++ )
            printf( " %d", 1 );
        for ( i = 1; i <= b; i++ )
            printf( " 2" );
        printf( "\n" );
        return 0;
    }

    for ( i = 1; i <= n; i++ )
    {
        if ( ba[t[i]] > 0 )
        {
            f[i] = 1;
            ba[t[i]]--;
        }
        else f[i] = 2;
    }

    printf( "%d", f[1] );
    for ( i = 2; i <= n; i++ )
    {
        printf( " %d", f[i] );
    }
    printf( "\n" );
    return 0;
}