#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
int ls, lb[16];
char s[100020];
char b[16][16];

int hv[100020][13];

int blen, bpos;

int main()
{
    int i, j, k;
    int ne;
    int p, q, en;

    scanf( "%s", s ); ls = strlen( s );
    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%s", b[i] );
        lb[i] = strlen( b[i] );
    }

    memset( hv, 0, sizeof( hv ) );

    for ( i = 1; i <= n; i++ )
    {
        for ( j = 0; j < ls; j++ )
        {
            for ( k = 0; k < lb[i]; k++ )
            {
                if ( s[j+k] != b[i][k] )
                    break;
            }
            if ( k >= lb[i] )
            {
                hv[j][i] = 1;
                hv[j][0]++;
            }
        }
    }

    blen = -1;

    for ( j = 0; j < ls; )
    {
        en = ls;
        ne = j;
        for ( i = j; i < en; i++ )
        {
            if ( hv[i][0] == 0 ) continue;
            for ( k = 1; k <= n; k++ )
            {
                if ( hv[i][k] == 1 )
                {
                    if ( i+lb[k]-1 <= en )
                    {
                        ne = i;
                        en = i+lb[k]-1;
                    }
                }
            }
        }
        if ( en-j > blen )
        {
            blen = en-j;
            bpos = j;
        }
        if ( en == ls ) break;
//        cout << j << " " << en << endl;
        j = ne+1;
    }
    printf( "%d %d\n", blen, bpos );
    return 0;
}