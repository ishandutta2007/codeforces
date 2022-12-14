#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int m = (1<<19);
int n, q;

long long ts[(1<<20)];
long long tc[(1<<20)];

long long upd( int nd, int nl, int nr, int l, int r, int v )
{
    if ( ( r < nl ) || ( nr < l ) )
        return ts[nd]+tc[nd];
    if ( ( l <= nl ) && ( nr <= r ) )
    {
        tc[nd] = tc[nd] + v;
        if ( nl < nr )
        {
            tc[2*nd] = tc[2*nd] + tc[nd];
            tc[2*nd+1] = tc[2*nd+1] + tc[nd];
        }
        ts[nd] = ts[nd] + tc[nd];
        tc[nd] = 0;
        return ts[nd];
    }
    if ( nl < nr )
    {
        tc[2*nd] = tc[2*nd] + tc[nd];
        tc[2*nd+1] = tc[2*nd+1] + tc[nd];
    }
    ts[nd] = ts[nd] + tc[nd];
    tc[nd] = 0;
    long long i, j;
    i = upd( 2*nd, nl, (nl+nr)/2, l, r, v );
    j = upd( 2*nd+1, (nl+nr)/2+1, nr, l, r, v );
    ts[nd] = min( i, j );
    return ts[nd];
}

long long query( int nd, int nl, int nr, int l, int r )
{
    if ( ( r < nl ) || ( nr < l ) )
        return (1LL<<60);
    if ( ( l <= nl ) && ( nr <= r ) )
    {
        if ( nl < nr )
        {
            tc[2*nd] = tc[2*nd] + tc[nd];
            tc[2*nd+1] = tc[2*nd+1] + tc[nd];
        }
        ts[nd] = ts[nd] + tc[nd];
        tc[nd] = 0;
        return ts[nd];
    }
    long long i, j;
    if ( nl < nr )
    {
        tc[2*nd] = tc[2*nd] + tc[nd];
        tc[2*nd+1] = tc[2*nd+1] + tc[nd];
    }
    ts[nd] = ts[nd] + tc[nd];
    tc[nd] = 0;
    i = query( 2*nd, nl, (nl + nr)/2, l, r );
    j = query( 2*nd+1, (nl+nr)/2+1, nr, l, r );
    return min( i, j );
}

int main()
{
    int i, j, k, v;
    long long be;
    char x;

    memset( ts, 0, sizeof( ts ) );
    memset( tc, 0, sizeof( tc ) );

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &k );
        upd( 1, 0, m-1, i, i, k );
        upd( 1, 0, m-1, i+n, i+n, k );
    }

    scanf( "%d", &q );
    for ( i = 1; i <= q; i++ )
    {
        scanf( "%d %d", &j, &k );
        scanf( "%c", &x );
        if ( x == ' ' )
        {
            scanf( "%d", &v );
            if ( j <= k )
            {
                upd( 1, 0, m-1, j, k, v );
                upd( 1, 0, m-1, j+n, k+n, v );
            }
            else
            {
                upd( 1, 0, m-1, j, k+n, v );
                upd( 1, 0, m-1, 0, k, v );
                upd( 1, 0, m-1, j+n, 2*n-1, v );
            }
        }
        else
        {
            be = (1LL<<60);
            if ( j <= k )
            {
                printf( "%I64d\n", query( 1, 0, m-1, j, k ) );
            }
            else
            {
                printf( "%I64d\n", query( 1, 0, m-1, j, k+n ) );
            }
        }
    }
    return 0;
}