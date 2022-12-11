#include <cstdio>

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e4 + 5;

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

LL f[MAXN];
int p[MAXN], s[MAXN];
int N, c;

int main()
{
	read( N ), read( c );
	for( int i = 1 ; i <= N ; i ++ ) read( p[i] );
	for( int i = 1 ; i <= N ; i ++ ) read( s[i] );
	for( int i = 1 ; i <= N ; i ++ ) f[i] = INF;
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = i ; ~ j ; j -- )
			f[j] = MIN( f[j] + 1ll * j * c + p[i], j ? ( f[j - 1] + s[i] ) : INF );
	LL ans = INF;
	for( int i = 0 ; i <= N ; i ++ ) ans = MIN( ans, f[i] );
	write( ans ), putchar( '\n' );
	return 0;
}