#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

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

typedef std :: pair<int, int> Diff;

std :: set<int> s;

int ans[MAXN];

Diff seq[MAXN];
int tot = 0;

int A[MAXN];

int N;

int main() {
	int T; Read( T );
	while( T -- ) {
		Read( N );
		rep( i, 1, N ) Read( A[i] );
		tot = 0;
		rep( i, 1, N - 1 )
			if( A[i] > A[i + 1] )
				seq[++ tot] = { A[i] - A[i + 1], i };
		std :: sort( seq + 1, seq + 1 + tot );
		s.clear();
		rep( i, 1, N ) s.insert( i ), ans[i] = N;
		per( i, tot, 1 ) {
			int x = seq[i].first, y = seq[i].second;
			std :: set<int> :: iterator it = s.lower_bound( x );
			ans[*it] = y + 1, s.erase( it );
		}
		rep( i, 1, N ) Write( ans[i] ), putchar( " \n"[i == N] );
	}
	return 0;
}