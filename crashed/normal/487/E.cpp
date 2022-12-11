#include <set>
#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

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
_T Min( const _T a, const _T b ) {
	return a < b ? a : b;
}

struct MyGraph {
	struct Edge {
		int to, nxt;
	} Graph[MAXN << 1];

	int head[MAXN], cnt;

	MyGraph(): head{}, cnt( 1 ) {}

	inline const Edge& operator [] ( const int &idx ) const { return Graph[idx]; }

	inline void AddE( const int from, const int to ) {
		AddEdge( from, to ), AddEdge( to, from );
	}

	inline void AddEdge( const int from, const int to ) {
		Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
		head[from] = cnt;
	}
};

MyGraph org, tre;

std :: set<int> son[MAXN];

int mn[MAXN << 2];

int LPos[MAXN], LTail[MAXN], seq[MAXN], bel[MAXN], tot = 0;
int dep[MAXN], siz[MAXN], heavy[MAXN], fath[MAXN];

int stk[MAXN], top = 0;
int DFN[MAXN], LOW[MAXN], ID = 0, ntot = 0;

int wei[MAXN];

int N, M, Q;

void Tarjan( const int u, const int fa ) {
	DFN[u] = LOW[u] = ++ ID, stk[++ top] = u;
	for( int i = org.head[u], v ; i ; i = org[i].nxt )
		if( ! DFN[v = org[i].to] ) {
			Tarjan( v, u );
			LOW[u] = Min( LOW[u], LOW[v] );
			if( LOW[v] >= DFN[u] ) {
				ntot ++;
				do tre.AddE( ntot, stk[top] );
				while( stk[top --] ^ v );
				tre.AddE( ntot, u );
			}
		} else if( v ^ fa ) LOW[u] = Min( LOW[u], DFN[v] );
}

void DFS1( const int u, const int fa ) {
	siz[u] = 1, heavy[u] = 0;
	dep[u] = dep[fath[u] = fa] + 1;
	for( int i = tre.head[u], v ; i ; i = tre[i].nxt )
		if( ( v = tre[i].to ) ^ fa ) {
			DFS1( v, u ), siz[u] += siz[v];
			if( siz[heavy[u]] < siz[v] ) heavy[u] = v;
		}
}

void DFS2( const int u, const int fa ) {
	seq[LPos[u] = ++ ID] = u;
	if( ! heavy[u] ) bel[u] = ++ tot;
	else DFS2( heavy[u], u ), bel[u] = bel[heavy[u]];
	LTail[bel[u]] = u;
	for( int i = tre.head[u], v ; i ; i = tre[i].nxt )
		if( ( v = tre[i].to ) ^ fa && v ^ heavy[u] )
			DFS2( v, u );
}

inline void Upt( const int &x ) {
	mn[x] = Min( mn[x << 1], mn[x << 1 | 1] );
}

void Build( const int x, const int l, const int r ) {
	if( l > r ) return ;
	if( l == r ) {
		mn[x] = wei[seq[l]];
		return ;
	}
	int mid = ( l + r ) >> 1;
	Build( x << 1, l, mid );
	Build( x << 1 | 1, mid + 1, r );
	Upt( x );
}

void Update( const int x, const int l, const int r, const int p ) {
	if( l == r ) { mn[x] = wei[seq[l]]; return ; }
	int mid = ( l + r ) >> 1;
	if( p <= mid ) Update( x << 1, l, mid, p );
	else Update( x << 1 | 1, mid + 1, r, p );
	Upt( x );
}

int Query( const int x, const int l, const int r, const int segL, const int segR ) {
	if( segL <= l && r <= segR ) return mn[x];
	int mid = ( l + r ) >> 1, ret = INF;
	if( segL <= mid ) ret = Min( ret, Query( x << 1, l, mid, segL, segR ) );
	if( mid  < segR ) ret = Min( ret, Query( x << 1 | 1, mid + 1, r, segL, segR ) );
	return ret;
}

void Init() {
	ntot = N, Tarjan( 1, 0 );
	ID = 0, DFS1( 1, 0 ), DFS2( 1, 0 );
	rep( i, 1, N ) if( fath[i] )
		son[fath[i]].insert( wei[i] );
	rep( i, N + 1, ntot )
		wei[i] = *son[i].begin();
	Build( 1, 1, ntot );
}

void Change( const int u, const int nVal ) {
	if( fath[u] ) son[fath[u]].erase( wei[u] );
	wei[u] = nVal, Update( 1, 1, ntot, LPos[u] );
	if( fath[u] ) {
		son[fath[u]].insert( nVal );
		wei[fath[u]] = *son[fath[u]].begin();
		Update( 1, 1, ntot, LPos[fath[u]] );
	}
}

int Query( int u, int v ) {
	int ret = INF;
	while( bel[u] ^ bel[v] ) {
		if( dep[LTail[bel[u]]] < dep[LTail[bel[v]]] ) std :: swap( u, v );
		ret = Min( ret, Query( 1, 1, ntot, LPos[LTail[bel[u]]], LPos[u] ) ), u = fath[LTail[bel[u]]];
	}
	if( dep[u] > dep[v] ) std :: swap( u, v );
	ret = Min( ret, Query( 1, 1, ntot, LPos[u], LPos[v] ) );
	if( u > N ) ret = Min( ret, wei[fath[u]] );
	return ret; 
}

int main() {
	read( N ), read( M ), read( Q );
	rep( i, 1, N ) read( wei[i] );
	rep( i, 1, M ) {
		int u, v;
		read( u ), read( v );
		org.AddE( u, v );
	}
	Init();
	char op[5]; int a, b;
	while( Q -- ) {
		scanf( "%s", op );
		read( a ), read( b );
		if( op[0] == 'C' ) Change( a, b );
		if( op[0] == 'A' ) write( Query( a, b ) ), putchar( '\n' );
	}
	return 0;
}