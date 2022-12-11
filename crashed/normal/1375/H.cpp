#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = ( 1 << 12 ) + 5, MAXQ = ( 1 << 16 ) + 5, MAXS = 2.2e6 + 5;

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
inline _T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

int sub[MAXS][2];

std :: vector<int> pos[MAXN << 2];
std :: map<int, int> rng[MAXN << 2];
int dep[MAXN << 2];

int ans[MAXQ];
int p[MAXN], q[MAXN];

int N, Q, cnt;

inline int Merge( const int &u, const int &v ) {
	cnt ++;
	sub[cnt][0] = u, sub[cnt][1] = v;
	return cnt;
}

void Build( const int &x, const int &l, const int &r ) {
	if( l > r ) return ;
	rep( i, l, r ) pos[x].push_back( q[i] );
	std :: sort( pos[x].begin(), pos[x].end() );
	if( l == r ) return ;
	int mid = ( l + r ) >> 1;
	Build( x << 1, l, mid );
	Build( x << 1 | 1, mid + 1, r );
}

int Query( const int &x, const int &qL, const int &qR ) {
	int tL = std :: lower_bound( pos[x].begin(), pos[x].end(), qL ) - pos[x].begin(),
		tR = std :: upper_bound( pos[x].begin(), pos[x].end(), qR ) - pos[x].begin() - 1;
	if( tL > tR ) return 0;
	if( tL == tR ) return pos[x][tL];
	int id = tL << 13 | tR;
	int ret = rng[x][id];
	if( ret ) return ret;
	int rL = Query( x << 1, qL, qR ),
		rR = Query( x << 1 | 1, qL, qR );
	if( ! rL || ! rR ) ret = rL | rR;
	else ret = Merge( rL, rR );
	return rng[x][id] = ret;
}

int main() {
	read( N ), read( Q ), cnt = N;
	rep( i, 1, N ) read( p[i] ), q[p[i]] = i;
	Build( 1, 1, N );
	rep( cas, 1, Q ) {
		int l, r; read( l ), read( r );
		ans[cas] = Query( 1, l, r );
	}
	write( cnt ), putchar( '\n' );
	rep( i, N + 1, cnt ) 
		write( sub[i][0] ), putchar( ' ' ),
		write( sub[i][1] ), putchar( '\n' );
	rep( i, 1, Q ) write( ans[i] ), putchar( " \n"[i == Q] );
	return 0;
}