#include <cstdio>

const int MAXN = 105;

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

int a[MAXN], b[MAXN];
int N;
bool statement[MAXN];

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) scanf( "%1d", &statement[i] );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] ), read( b[i] );
	int res = 0, tmp;
	for( int i = 1 ; i <= N ; i ++ ) res += statement[i];
	int upper = 3e7 / N;
	for( int i = 1 ; i <= upper ; i ++ )
	{
		tmp = 0;
		for( int j = 1 ; j <= N ; j ++ )
		{
			if( i >= b[j] && ! ( ( i - b[j] ) % a[j] ) ) statement[j] = ! statement[j];
			tmp += statement[j];
		}
		res = MAX( res, tmp );
	}
	write( res ), putchar( '\n' );
	return 0;
}