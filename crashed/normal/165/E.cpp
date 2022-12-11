#include <cstdio>

const int MAXN = 1e6 + 5, MAXS = 5e6 + 5;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int f[MAXS], F[MAXS];
int a[MAXN];
int N;

int main()
{
	read( N );
	int mx = 0;
	for( int i = 1 ; i <= N ; i ++ )
		read( a[i] ), mx = MAX( mx, a[i] ), F[a[i]] = a[i];
	int up = 1, bit = 0;
	while( up <= mx ) up <<= 1, bit ++;
	for( int S = 1 ; S < up ; S ++ )
	{
		if( F[S] ) { f[S] = F[S]; continue; }
		for( int i = 0 ; i < bit ; i ++ )
			if( S & ( 1 << i ) )
			{
				if( f[1 << i] ) { f[S] = f[1 << i]; break; }
				if( f[S ^ ( 1 << i )] ) { f[S] = f[S ^ ( 1 << i )]; break; }
			}
	}
	for( int i = 1 ; i <= N ; i ++ )
	{
		int ans = f[( up - 1 ) ^ a[i]];
		if( ans ) write( ans );
		else write( -1 );
		putchar( i == N ? '\n' : ' ' );
	}
	return 0;
}