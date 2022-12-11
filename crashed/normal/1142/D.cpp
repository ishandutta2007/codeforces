#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1e5 + 5;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

LL f[11], g[11];

char str[MAXN];

int N;

int main() {
	scanf( "%s", str + 1 );
	N = strlen( str + 1 );
	LL ans = 0;
	rep( i, 1, N ) {
		int x = str[i] - '0';
		rep( a, 0, 10 ) {
			if( a <= x ) continue;
			if( ! f[a] ) continue;
			int nwA = ( 10 + x + a * ( a - 1 ) / 2 % 11 ) % 11;
			g[nwA] += f[a];
		}
		rep( a, 0, 10 ) f[a] = g[a], g[a] = 0;
		if( x > 0 ) f[x] ++;
		rep( a, 0, 10 ) ans += f[a];
	}
	write( ans ), putchar( '\n' );
	return 0;
}