#include <cmath>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

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

template<typename _T>
_T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

struct Edge {
	int to, nxt;
} Graph[MAXN << 1];

int f[MAXN], g[MAXN];

int seq[MAXN], tot = 0;
int head[MAXN], fath[MAXN], cnt = 1;

int ans[MAXN];

int N, THRE;

inline void AddEdge( const int from, const int to ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void Init( const int u, const int fa ) {
	fath[u] = fa, seq[++ tot] = u;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa ) Init( v, u );
}

inline int Query( const int l ) {
	int ret = 0;
	rep( i, 1, N ) f[i] = g[i] = 0;
	per( s, N, 1 ) {
		int u = seq[s], v = fath[u];
		if( f[u] + g[u] + 1 >= l ) ret ++;
		else if( v ) {
			if( f[v] <= f[u] + 1 ) g[v] = f[v], f[v] = f[u] + 1;
			else if( g[v] < f[u] + 1 ) g[v] = f[u] + 1;
		}
	}
	return ret;
}

void Divide( const int l, const int r, const int vL, const int vR ) {
	if( l > r || vL > vR ) return ;
	if( vL == vR ) {
		rep( i, l, r ) ans[i] = vL;
		return ;
	}
	int mid = ( l + r ) >> 1;
	ans[mid] = Query( mid );
	Divide( l, mid - 1, ans[mid], vR );
	Divide( mid + 1, r, vL, ans[mid] );
}

int main() {
	read( N );
	rep( i, 1, N - 1 ) {
		int u, v;
		read( u ), read( v );
		AddEdge( u, v ), AddEdge( v, u );
	}
	Init( 1, 0 ), THRE = sqrt( N );
	rep( i, 1, THRE ) ans[i] = Query( i );
	Divide( THRE + 1, N, 0, THRE );
	rep( i, 1, N ) write( ans[i] ), putchar( '\n' );
	return 0;
}