#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;

const int MAXN = 205;

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

LL f[MAXN][MAXN][MAXN];
int r[MAXN], g[MAXN], b[MAXN];
int R, G, B;

void upt( LL &x, const LL v ) { x = MAX( x, v ); }

int main()
{
	read( R ), read( G ), read( B );
	for( int i = 1 ; i <= R ; i ++ ) read( r[i] );
	for( int i = 1 ; i <= G ; i ++ ) read( g[i] );
	for( int i = 1 ; i <= B ; i ++ ) read( b[i] );
	std :: sort( r + 1, r + R + 1 );
	std :: sort( g + 1, g + G + 1 );
	std :: sort( b + 1, b + B + 1 );
	memset( f, 0xc0, sizeof f );
	f[R][G][B] = 0;
	for( int i = R ; ~ i ; i -- )
		for( int j = G ; ~ j ; j -- )
			for( int k = B ; ~ k ; k -- )
			{
				if( i < R && j < G ) upt( f[i][j][k], f[i + 1][j + 1][k] + r[i + 1] * g[j + 1] );
				if( j < G && k < B ) upt( f[i][j][k], f[i][j + 1][k + 1] + g[j + 1] * b[k + 1] );
				if( i < R && k < B ) upt( f[i][j][k], f[i + 1][j][k + 1] + r[i + 1] * b[k + 1] );
			}
	LL ans = -1;
	for( int i = R ; ~ i ; i -- )
		for( int j = G ; ~ j ; j -- )
			for( int k = B ; ~ k ; k -- )
				upt( ans, f[i][j][k] );
	write( ans ), putchar( '\n' );
	return 0;
}