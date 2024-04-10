#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e5 + 5;

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

int pre1[MAXN], suf0[MAXN];
int A[MAXN];

int N;

int main() {
	int T; Read( T );
	while( T -- ) {
		Read( N );
		rep( i, 1, N ) Read( A[i] );
		pre1[0] = suf0[N + 1] = 0;
		rep( i, 1, N ) pre1[i] = pre1[i - 1] + ( A[i] == 1 );
		per( i, N, 1 ) suf0[i] = suf0[i + 1] + ( A[i] == 0 );
		int ans = 1e9;
		rep( i, 0, N ) 
			if( pre1[i] + ( N - i - suf0[i + 1] ) >= suf0[i + 1] ) 
				ans = std :: min( ans, std :: max( pre1[i], suf0[i + 1] ) );
		Write( ans ), putchar( '\n' );
	}
	return 0;
}