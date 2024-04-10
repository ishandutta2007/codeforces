#include <cmath>
#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5, MAXLOG = 20;

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

struct Edge {
	int to, nxt;
} Graph[MAXN << 1];

std :: vector<int> route[MAXN], qry[MAXN];

int DFN[MAXN], siz[MAXN], BIT[MAXN], ID = 0;

int rU[MAXN], rV[MAXN];
int qU[MAXN], qV[MAXN], ans[MAXN], old[MAXN];

int jmp[MAXN][MAXLOG];
int tag[MAXN][MAXLOG];
int fath[MAXN][MAXLOG];
int head[MAXN], dep[MAXN], cnt = 1;

int N, M, Q, lg2;

inline void Down( int &x ) { x &= x - 1; }
inline void Up( int &x ) { x += x & ( - x ); }
inline void Update( int x, int v ) { for( ; x <= N ; Up( x ) ) BIT[x] += v; }
inline  int Query( int x ) { int ret = 0; for( ; x ; Down( x ) ) ret += BIT[x]; return ret; }
inline  int Query( int l, int r ) { return Query( r ) - Query( l - 1 ); }

inline void AddEdge( const int &from, const int &to ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void Init( const int &u, const int &fa ) {
	DFN[u] = ++ ID, siz[u] = 1;
	dep[u] = dep[fath[u][0] = fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			Init( v, u ), siz[u] += siz[v];
}

void Init() {
	Init( 1, 0 ), lg2 = log2( N );
	rep( j, 1, lg2 ) rep( i, 1, N )
		fath[i][j] = fath[fath[i][j - 1]][j - 1];
}

inline void Balance( int &x, const int &stp ) {
	for( int i = 0 ; ( 1 << i ) <= stp ; i ++ )
		if( stp >> i & 1 ) x = fath[x][i];
}

inline int LCA( int u, int v ) {
	if( dep[u] > dep[v] ) Balance( u, dep[u] - dep[v] );
	if( dep[v] > dep[u] ) Balance( v, dep[v] - dep[u] );
	if( u == v ) return u;
	per( i, lg2, 0 ) if( fath[u][i] ^ fath[v][i] ) u = fath[u][i], v = fath[v][i];
	return fath[u][0];
}

inline void Upt( int &x, const int &v ) {
	x = dep[x] < dep[v] ? x : v;
}

inline void SingleCover( int u, int stp, const int &tar ) {
	if( stp == 0 ) {
		Upt( jmp[u][0], tar );
		return ;
	}
	int d = 31 - __builtin_clz( stp );
	Upt( tag[u][d], tar );
	Balance( u, stp ^ ( 1 << d ) );
	Upt( tag[u][d], tar );
}

inline void Cover( int u, int v ) {
	int lca = LCA( u, v );
	SingleCover( u, dep[u] - dep[lca], lca );
	SingleCover( v, dep[v] - dep[lca], lca );
}

void DFS( const int &u, const int &fa ) {
	for( const int &q : qry[u] ) {
		int v = qU[q] == u ? qV[q] : qU[q];
		old[q] = Query( DFN[v], DFN[v] + siz[v] - 1 );
	}
	for( const int &r : route[u] ) Update( DFN[r], 1 );
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			DFS( v, u );
	for( const int &q : qry[u] ) {
		int v = qU[q] == u ? qV[q] : qU[q];
		if( old[q] == Query( DFN[v], DFN[v] + siz[v] - 1 ) )
			ans[q] += 2;
		else ans[q] ++;
	}
}

int main() {
	read( N );
	rep( i, 2, N ) {
		int p; read( p );
		AddEdge( i, p ), AddEdge( p, i );
	}
	Init(), dep[0] = N + 1;
	read( M );
	rep( i, 1, M ) read( rU[i] ), read( rV[i] ), Cover( rU[i], rV[i] );
	read( Q );
	rep( i, 1, Q ) read( qU[i] ), read( qV[i] );
	per( j, lg2, 1 ) rep( i, 1, N ) {
		Upt( tag[i][j - 1], tag[i][j] );
		if( fath[i][j - 1] ) Upt( tag[fath[i][j - 1]][j - 1], tag[i][j] );
	}
	rep( i, 1, N ) {
		Upt( jmp[i][0], tag[i][0] );
		if( fath[i][0] ) Upt( jmp[fath[i][0]][0], tag[i][0] );
	}
	rep( j, 1, lg2 ) rep( i, 1, N )
		jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
	rep( i, 1, Q ) {
		int &u = qU[i], &v = qV[i], lca = LCA( u, v );
		if( u ^ lca ) {
			for( int k = lg2 ; ~ k ; k -- )
				if( jmp[u][k] && dep[jmp[u][k]] > dep[lca] )
					u = jmp[u][k], ans[i] += 1 << k;
		}
		if( v ^ lca ) {
			for( int k = lg2 ; ~ k ; k -- )
				if( jmp[u][k] && dep[jmp[v][k]] > dep[lca] )
					v = jmp[v][k], ans[i] += 1 << k;
		}
		if( u == v ) continue;
		if( u ^ lca && ( ! jmp[u][0] || dep[jmp[u][0]] > dep[lca] ) ) { ans[i] = -1; continue; }
		if( v ^ lca && ( ! jmp[v][0] || dep[jmp[v][0]] > dep[lca] ) ) { ans[i] = -1; continue; }
		if( u == lca || v == lca ) ans[i] ++;
		else qry[u].push_back( i );
	}
	rep( i, 1, M ) {
		route[rU[i]].push_back( rV[i] );
		route[rV[i]].push_back( rU[i] );
	}
	DFS( 1, 0 );
	rep( i, 1, Q ) write( ans[i] ), putchar( '\n' );
	return 0;
}