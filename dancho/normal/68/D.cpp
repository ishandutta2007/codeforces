#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

int h, q;
map<int,int> nd, tr;

double decay( int v, int mx, int lh )
{
    if ( tr[v] <= mx )
    {
        return mx;
    }
    if ( lh == 0 ) return nd[v];
    double l, r;
    l = decay( 2*v, max( nd[v] + tr[2*v+1], mx ), lh-1 );
    r = decay( 2*v+1, max( nd[v] + tr[2*v], mx ), lh-1 );
    return (l+r)/2.0;
}

int main()
{
    int i, j, k;
    char x[8];
    int v, e;

    scanf( "%d %d", &h, &q );
    for ( i = 1; i <= q; i++ )
    {
        scanf( "%s", x );
        if ( x[0] == 'a' )
        {
            scanf( "%d %d", &v, &e );
            nd[v] += e;
            while ( v > 0 )
            {
                tr[v] += e;
                v /= 2;
            }
        }
        else
        {
            printf( "%.8lf\n", decay( 1, 0, h ) );
        }
    }
    return 0;
}