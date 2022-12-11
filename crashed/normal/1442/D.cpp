#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 3005;

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
inline _T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

LL f[MAXN << 2][MAXN];

std :: vector<LL> pref[MAXN];

int N, K;

void Divide( const int &x, const int &l, const int &r ) {
	if( l > r ) return ;
	if( l == r ) {
		int n = pref[l].size();
		rep( i, 0, K ) f[x][i] = - INF;
		for( int i = 0 ; i < n && i <= K ; i ++ )
			f[x][i] = pref[l][i];
		return ;
	}
	int mid = ( l + r ) >> 1;
	Divide( x << 1, l, mid );
	Divide( x << 1 | 1, mid + 1, r );
	rep( i, l, mid ) {
		int t = pref[i].size();
		per( j, K, t - 1 )
			f[x << 1 | 1][j] = Max( f[x << 1 | 1][j], f[x << 1 | 1][j - t + 1] + pref[i][t - 1] );
	}
	rep( i, mid + 1, r ) {
		int t = pref[i].size();
		per( j, K, t - 1 )
			f[x << 1][j] = Max( f[x << 1][j], f[x << 1][j - t + 1] + pref[i][t - 1] );
	}
	rep( j, 0, K ) 
		f[x][j] = Max( f[x << 1][j], f[x << 1 | 1][j] );
}

int main() {
	read( N ), read( K );
	rep( i, 1, N ) {
		int t; read( t );
		pref[i].push_back( 0 );
		while( t -- ) {
			int x; read( x );
			pref[i].push_back( x + pref[i].back() );
		}
	}
	Divide( 1, 1, N );
	write( f[1][K] ), putchar( '\n' );
	return 0;
}