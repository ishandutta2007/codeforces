#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1505;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
inline _T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

typedef std :: pair<int, int> Number;
typedef bool ( * Comparer ) ( const Number&, const Number& );

bool ever[MAXN * MAXN] = {};

int tmp[15], cnt = 0;

std :: vector<Number> lef, rig;
std :: vector<Number> lf[MAXN], up[MAXN][MAXN];

int grid[MAXN][MAXN];
int pref[MAXN];

int N, Q;

inline bool Greater( const Number &a, const Number &b ) {
	return a > b;
}

inline bool Less( const Number &a, const Number &b ) {
	return a < b;
}

inline std :: vector<Number> Merge( const std :: vector<Number> &a, const std :: vector<Number> &b, const Comparer Cmp = Greater ) {
	int n = a.size(), m = b.size();
	std :: vector<Number> ret; Number nxt;
	for( int i = 0, j = 0 ; ( int ) ret.size() < Q + 1 && ( i < n || j < m ) ; ) {
		if( i < n && ( j >= m || Cmp( a[i], b[j] ) ) )
			nxt = a[i ++];
		else nxt = b[j ++];
		if( ! ever[nxt.second] )
			ret.push_back( nxt ), ever[nxt.second] = true;
	}
	for( const Number &x : ret )
		ever[x.second] = false;
	return ret;
}

int main() {
	read( N ), read( Q );
	rep( i, 1, N ) rep( j, 1, N ) read( grid[i][j] );
	rep( i, 2, N ) rep( j, 1, N )
		up[i][j] = Merge( up[i - 1][j], ( std :: vector<Number> ) { { i - 1, grid[i - 1][j] } } );
	rep( s, 1 - N, N - 1 ) {
		lef.clear(), rig.clear();
		rep( i, 1, N ) 
			if( 1 <= i + s && i + s <= N ) {
				int j = i + s, n, m, val, id;
				lf[i] = Merge( lf[i], ( std :: vector<Number> ) { { j, grid[i][j] } } );
				lef = Merge( lef, lf[i] ), rig = Merge( rig, up[i][j] );
				n = lef.size(), m = rig.size(), cnt = 0;
				for( int p = 0, q = 0 ; cnt < Q + 1 && ( p < n || q < m ) ; ) {
					if( p < n && ( q >= m || j - lef[p].first < i - rig[q].first ) )
						val = j - lef[p].first, id = lef[p].second, p ++;
					else val = i - rig[q].first, id = rig[q].second, q ++;
					if( ! ever[id] ) tmp[++ cnt] = id, ever[id] = true;
				}
				int lim = cnt > Q ? val : 1e9;
				lim = Min( lim, Min( i, j ) ), pref[lim] ++;
				rep( i, 1, cnt ) ever[tmp[i]] = false;
				// if( lim >= 5 )
					// printf( "%d %d\n", i, j );
			}
	}
	per( i, N, 1 ) i[pref] += pref[i + 1];
	rep( i, 1, N ) write( i[pref] ), putchar( '\n' );
	return 0;
}