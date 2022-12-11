#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = - x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int bucT[MAXN], bucD[MAXN];
int top[MAXN], dif[MAXN];
int N, cnt;

void Clear()
{
	rep( i, 1, N ) bucT[i] = bucD[i] = 0;
}

int main()
{
	int T; read( T );
	while( T -- )
	{
		read( N ), Clear();
		rep( i, 1, N )
		{
			read( top[i] ), read( dif[i] );
			bucT[top[i]] ++, bucD[dif[i]] ++;
		}
		LL ans = 1ll * N * ( N - 1 ) * ( N - 2 ) / 6;
		rep( i, 1, N ) ans -= 1ll * ( bucT[top[i]] - 1 ) * ( bucD[dif[i]] - 1 );
		write( ans ), putchar( '\n' );
 	}
	return 0;
}
/*
1
3
1 2
2 1
1 3
*/