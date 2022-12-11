#include <bitset>
#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXS = 1250005, MAXN = 30;

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

template<typename _T>
_T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

template<typename _T>
_T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

std :: bitset<MAXS> dp[MAXN << 1][MAXN];

bool fir[MAXN << 1];

int A[MAXN << 1];

int N;

void DFS( const int &i, const int &j, const int &k ) {
	if( i > ( N << 1 ) ) return ;
	if( dp[i + 1][j].test( k ) )
		DFS( i + 1, j, k );
	else {
		fir[i] = true;
		DFS( i + 1, j - 1, k - A[i] );
	}
}

int main() {
	read( N ); int su = 0;
	rep( i, 1, N ) read( A[i] ), su += A[i];
	rep( i, 1, N ) read( A[i + N] ), su += A[i + N];
	std :: sort( A + 1, A + 1 + ( N << 1 ) );
	dp[( N << 1 ) + 1][0].set( 0 ); 
	int ans = INF, ansI, ansJ, ansK;
	per( i, N << 1, 1 ) {
		if( i > 1 ) {
			int pref = 0;
			rep( k, 1, i - 1 ) pref += A[k];
			rep( j, 0, ( N - i + 1 ) * 50000 )
				if( dp[i + 1][N - i + 1].test( j ) )
					if( Max( A[i] + j + pref, su + A[1] - ( j + pref ) ) < ans ) {
						ans = Max( A[i] + j + pref, su + A[1] - ( j + pref ) );
						rep( k, 1, N << 1 ) fir[k] = false;
						rep( k, 1, i - 1 ) fir[k] = true;
						ansI = i + 1, ansJ = N - i + 1, ansK = j;
					}	
			rep( j, 0, ( N - 1 ) * 50000 )
				if( dp[i + 1][N - 1].test( j ) )
					if( Max( A[1] + j + A[i], su - j ) < ans ) {
						ans = Max( A[1] + j + A[i], su - j );
						rep( k, 1, N << 1 ) fir[k] = false;
						fir[i] = true;
						ansI = i + 1, ansJ = N - 1, ansK = j;
					}
		}
		rep( j, 0, 25 ) {
			dp[i][j] = dp[i + 1][j];
			if( j ) dp[i][j] |= dp[i + 1][j - 1] << A[i];
		}
	}
	DFS( ansI, ansJ, ansK );
	rep( i, 1, N << 1 ) if( fir[i] ) write( A[i] ), putchar( ' ' );
	puts( "" );
	per( i, N << 1, 1 ) if( ! fir[i] ) write( A[i] ), putchar( ' ' );
	puts( "" );
	return 0;
}