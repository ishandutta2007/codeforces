// LUOGU_RID: 95187004
#include <cstdio>
#include <algorithm>
#include <functional>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5;

template<typename _T>
inline void Read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
inline void Write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) Write( x / 10 );
	putchar( x % 10 + '0' );
}

LL val[MAXN];
int tot = 0;

int N;

int main() {
	Read( N ); LL ans = 0;
	rep( i, 1, N ) {
		LL a1, b1, a2, b2;
		Read( a1 ), Read( b1 );
		Read( a2 ), Read( b2 );
		if( a1 + b1 >= a2 + b2 ) {
			ans -= b1 + b2;
			val[++ tot] = a1 + b1; 
			val[++ tot] = a2 + b2;
		} else {
			if( a1 > b2 ) ans += a1 - b2;
			else if( b1 > a2 ) ans += a2 - b1;
		}
	}
	std :: sort( val + 1, val + 1 + tot, std :: greater<LL> () );
	for( int i = 1 ; i <= tot ; i += 2 ) ans += val[i];
	Write( ans ), putchar( '\n' );
	return 0;
}