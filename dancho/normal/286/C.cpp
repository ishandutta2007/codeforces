#include <cstdio>
#include <cstring>

int n;
int p[1<<20];
int st[1<<20], stop;

int main()
{
    int i, j, k;
    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
        scanf( "%d", &p[i] );

    scanf( "%d", &k );
    for ( i = 1; i <= k; i++ )
    {
        scanf( "%d", &j );
        p[j] = -p[j];
    }

    stop = 0;
    for ( i = n; i > 0; i-- )
    {
        if ( p[i] < 0 )
        {
            st[++stop] = -p[i];
        }
        else if ( p[i] == st[stop] )
        {
            stop--;
        }
        else
        {
            p[i] = -p[i];
            st[++stop] = -p[i];
        }
    }
    if ( stop == 0 )
    {
        printf( "YES\n" );
        for ( i = 1; i < n; i++ )
            printf( "%d ", p[i] );
        printf( "%d\n", p[n] );
    }
    else
        printf( "NO\n" );
    return 0;
}