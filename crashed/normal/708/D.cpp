#include <queue>
#include <cstdio>
#include <utility>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 5;

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

template<typename _T>
inline _T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

typedef std :: pair<int, int> Node;

struct Edge {
	int to, nxt, c, w;
} Graph[MAXN << 1];

int dist[MAXN], pot[MAXN];
int head[MAXN], cur[MAXN], cnt = 1, ntot;
bool vis[MAXN];

int deg[MAXN];

int N, M;

inline void AddEdge( const int &from, const int &to, const int &C, const int &W ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	Graph[cnt].w = W, Graph[cnt].c = C, head[from] = cnt;
}

inline void AddE( const int &from, const int &to, const int &C, const int &W ) {
	AddEdge( from, to, C, W ), AddEdge( to, from, 0, -W );
}

void Init( const int &S ) {
	static std :: queue<int> q;

	rep( i, 1, ntot ) pot[i] = INF, vis[i] = false;
	q.push( S ), pot[S] = 0, vis[S] = true;
	while( ! q.empty() ) {
		int u = q.front(); 
		q.pop(), vis[u] = false;
		for( int i = head[u], v ; i ; i = Graph[i].nxt )
			if( Graph[i].c && pot[v = Graph[i].to] > pot[u] + Graph[i].w ) {
				pot[v] = pot[u] + Graph[i].w;
				if( ! vis[v] ) q.push( v ), vis[v] = true;
			}
	}
}

bool Dijkstra( const int &S, const int &T ) {
	static std :: priority_queue<Node, std :: vector<Node>, std :: greater<Node> > q;

	while( ! q.empty() ) q.pop();
	rep( i, 1, ntot ) dist[i] = INF, vis[i] = false;
	q.push( { dist[S] = 0, S } );
	while( ! q.empty() ) {
		int u = q.top().second; q.pop();
		if( vis[u] ) { continue; } vis[u] = true;
		for( int i = head[u], v ; i ; i = Graph[i].nxt ) {
			int w = pot[u] + Graph[i].w - pot[v = Graph[i].to];
			if( Graph[i].c && dist[v] > dist[u] + w )
				q.push( { dist[v] = dist[u] + w, v } );
		}
	}
	rep( i, 1, ntot ) pot[i] = ( dist[i] += pot[i] - pot[S] );
	return dist[T] < INF;
}

int DFS( const int &u, const int &lin, const int &T ) {
	if( u == T ) return lin;
	int used = 0, ret, v, c, w; vis[u] = true;
	for( int &i = cur[u] ; i ; i = Graph[i].nxt ) {
		v = Graph[i].to, c = Graph[i].c, w = Graph[i].w;
		if( c && dist[v] == dist[u] + w && ! vis[v] &&
			( ret = DFS( v, Min( lin - used, c ), T ) ) ) {
			used += ret, Graph[i].c -= ret, Graph[i ^ 1].c += ret;
			if( used == lin ) break;
		}
	}
	if( used < lin ) dist[u] = INF;
	return vis[u] = false, used;
}

std :: pair<int, int> Dinic( const int &S, const int &T ) {
	Init( S );
	int flow = 0, cost = 0;
	while( Dijkstra( S, T ) ) {
		rep( i, 1, ntot ) vis[i] = false, cur[i] = head[i];
		int tmp = DFS( S, INF, T );
		flow += tmp, cost += dist[T] * tmp;
	}
	return std :: make_pair( flow, cost );
}

int main() {
	int ans = 0;
	Read( N ), Read( M );
	rep( i, 1, M ) {
		int u, v, c, f;
		Read( u ), Read( v ), Read( c ), Read( f );
		if( f <= c ) {
			if( f < c ) AddE( u, v, c - f, 1 );
			if( f ) AddE( v, u, f, 1 );
			AddE( u, v, INF, 2 );
		} else {
			ans += f - c;
			AddE( v, u, f - c, 0 );
			if( c ) AddE( v, u, c, 1 );
			AddE( u, v, INF, 2 );
		}
		deg[u] -= f, deg[v] += f;
	}
	AddE( N, 1, INF, 0 ), ntot = N;
	const int s = ++ ntot, t = ++ ntot;
	rep( i, 1, N ) {
		if( deg[i] > 0 ) AddE( s, i, deg[i], 0 );
		if( deg[i] < 0 ) AddE( i, t, - deg[i], 0 );
	}
	Write( ans + Dinic( s, t ).second ), putchar( '\n' );
	return 0;
}