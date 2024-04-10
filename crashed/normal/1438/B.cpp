#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ); s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int a[MAXN];
int N;

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N );
		bool flg = false;
		for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
		for( int i = 1 ; i <= N ; i ++ )
		{
			for( int j = 1 ; j < i ; j ++ )
				if( a[i] == a[j] )
					{ flg = true; break; } 
			if( flg ) break;
		}
		puts( flg ? "YES" : "NO" );
	}
	return 0;
}