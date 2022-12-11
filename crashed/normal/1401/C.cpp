#include <cstdio>
#include <algorithm>

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

int seq[MAXN];
int a[MAXN], s[MAXN];
int N;

int gcd( const int a, const int b )
{
	return b ? gcd( b, a % b ) : a;
}

int main()
{
	int T, mn;
	read( T );
	while ( T -- )
	{
		read( N ), mn = INF;
		for( int i = 1 ; i <= N ; i ++ )
			read( a[i] ), mn = MIN( mn, a[i] ), s[i] = a[i];
		int mx = 0, d = 0; bool flg = true;
		std :: sort( s + 1, s + 1 + N );
		for( int i = 1 ; i <= N ; i ++ ) 
		{
			if( a[i] % mn )
			{
				if( a[i] ^ s[i] )
				{ flg = false; break; }
			}
			else d = gcd( a[i] / mn, d );
		}
		if( ! flg || d > 1 ) puts( "NO" );
		else puts( "YES" );
	}
	return 0;
}