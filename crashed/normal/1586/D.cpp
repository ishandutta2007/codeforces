#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 105;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int coe[MAXN];
int p[MAXN];

int N;

namespace Interact
{
	int Query()
	{
		printf( "?" );
		rep( i, 1, N ) printf( " %d", coe[i] );
		puts( "" ), fflush( stdout );
		int k; read( k ); return k;
	}
	
	void Answer()
	{
		printf( "!" );
		rep( i, 1, N ) printf( " %d", p[i] );
		puts( "" ), fflush( stdout );
	}
}

int main()
{
	read( N ), p[N] = 1;
	for( ; p[N] < N ; p[N] ++ )
	{
		rep( i, 1, N - 1 ) coe[i] = p[N] + 1;
		coe[N] = 1;
		if( ! Interact :: Query() ) break;
	}
	rep( i, 1, N )
	{
		if( i == p[N] ) continue;
		rep( j, 1, N - 1 ) coe[j] = p[N] + 1 - i;
		coe[N] = 1;
		while( coe[1] < 1 ) 
			rep( j, 1, N ) coe[j] ++;
		p[Interact :: Query()] = i;
	}
	Interact :: Answer();
	return 0;
}