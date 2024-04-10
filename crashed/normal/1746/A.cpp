#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 55;

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

int dp[MAXN][MAXN];

int seq[MAXN], tot = 0;
int A[MAXN];

int N, K;

int main() {
	int T; Read( T );
	while( T -- ) {
		tot = 0;
		Read( N ), Read( K );
		rep( i, 1, N ) {
			Read( A[i] );
			if( A[i] == 1 ) tot ++;
		}
		puts( tot ? "YES" : "NO" );
	}
	return 0;
}