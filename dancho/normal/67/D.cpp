#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
int a[1000020], no[1000020], p[1000020];

int main()
{
    int i, j, k;
    int la, l, r, m;

    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%d", &k );
        no[k] = i;
    }
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%d", &a[i] );
        a[i] = no[a[i]];
    }

    p[0] = (1<<29);
    la = 0;
    for ( i = 1; i <= n; i++ )
    {
        if ( a[i] < p[la] )
        {
            la++;
            p[la] = a[i];
        }
        else
        {
            l = 0; r = la;
            while ( l + 1 < r )
            {
                m = (l+r)/2;
                if ( p[m] > a[i] )
                {
                    l = m;
                }
                else if ( p[m] < a[i] )
                {
                    r = m;
                }
            }
            p[r] = max( p[r], a[i] );
        }
    }
    printf( "%d\n", la );
    return 0;
}