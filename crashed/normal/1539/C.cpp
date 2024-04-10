#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5;

template<typename _T>
void read( _T &x )
{
    x = 0; char s = getchar(); int f = 1;
    while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    x *= f;
}

template<typename _T>
void write( _T x )
{
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) write( x / 10 );
    putchar( x % 10 + '0' );
}

LL cost[MAXN], len = 0;

LL A[MAXN];
int N; LL K, X;

int main()
{
	read( N ), read( K ), read( X );
	rep( i, 1, N ) read( A[i] );
	sort( A + 1, A + 1 + N );
	rep( i, 1, N - 1 )
		cost[++ len] = max( 0ll, ( LL ) ceil( 1.0 * ( A[i + 1] - A[i] ) / X ) - 1 );
	sort( cost + 1, cost + 1 + len );
	LL su = 0;
	rep( i, 1, len )
	{
		if( su + cost[i] > K )
		{
			write( N - i + 1 ), putchar( '\n' );
			return 0;
		}
		su += cost[i];
	}
	puts( "1" );
	return 0;
}