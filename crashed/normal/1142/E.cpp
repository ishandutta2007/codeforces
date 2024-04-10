#include <set>
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
_T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

struct MyGraph {
	struct Edge {
		int to, nxt;
	} Graph[MAXN];

	int head[MAXN], cnt;

	MyGraph(): head{}, cnt( 0 ) {}

	inline const Edge& operator [] ( const int &idx ) const { return Graph[idx]; }

	inline void AddEdge( const int &from, const int &to ) {
		Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
		head[from] = cnt;
	}
};

MyGraph org, shrk;

std :: set<int> avai;
std :: set<int> SCC[MAXN];
int into[MAXN];

int bel[MAXN], tot;

int stk[MAXN], top;
int DFN[MAXN], LOW[MAXN], ID;
bool in[MAXN];

int N, M;

void Tarjan( const int &u ) {
	DFN[u] = LOW[u] = ++ ID;
	in[stk[++ top] = u] = true;
	for( int i = org.head[u], v ; i ; i = org[i].nxt )
		if( ! DFN[v = org[i].to] ) 
			Tarjan( v ), LOW[u] = Min( LOW[u], LOW[v] );
		else if( in[v] ) LOW[u] = Min( LOW[u], DFN[v] );
	if( LOW[u] == DFN[u] ) {
		int v; tot ++;
		do in[v = stk[top --]] = false,
		   SCC[bel[v] = tot].insert( v );
		while( v ^ u );
	}
}

bool QueryDir( const int &u, const int &v ) {
	printf( "? %d %d\n", u, v );
	fflush( stdout );
	int d; scanf( "%d", &d );
	return d;
}

int main() {
	read( N ), read( M );
	rep( i, 1, M ) {
		int u, v; read( u ), read( v );
		org.AddEdge( u, v );
	}
	rep( i, 1, N ) if( ! DFN[i] ) Tarjan( i );
	for( int u = 1 ; u <= N ; u ++ )
		for( int i = org.head[u] ; i ; i = org[i].nxt )
			if( bel[u] ^ bel[org[i].to] )
				shrk.AddEdge( bel[u], bel[org[i].to] ), into[bel[org[i].to]] ++;
	rep( i, 1, tot )
		if( ! into[i] )
			avai.insert( i );
	while( avai.size() > 1u ) {
		int p = *avai.begin(),
			q = *avai.rbegin();
		int u = *SCC[p].begin(),
			v = *SCC[q].begin();
		if( QueryDir( u, v ) ) { // supposed to remove v
			SCC[q].erase( v );
			if( SCC[q].empty() ) {
				avai.erase( q );
				for( int i = shrk.head[q] ; i ; i = shrk[i].nxt )
					if( ! ( -- into[shrk[i].to] ) ) avai.insert( shrk[i].to );
			}
		} else { // supposed to remove u
			SCC[p].erase( u );
			if( SCC[p].empty() ) {
				avai.erase( p );
				for( int i = shrk.head[p] ; i ; i = shrk[i].nxt )
					if( ! ( -- into[shrk[i].to] ) ) avai.insert( shrk[i].to );
			}
		}
	}
	printf( "! %d\n", *SCC[*avai.begin()].begin() );
	return 0;
}