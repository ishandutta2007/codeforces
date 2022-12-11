#include <queue>
#include <cstdio>
#include <utility>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXV = 1e5 + 5, MAXE = 1e6 + 5;
const int MAXN = 55;

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

struct Edge {
	int to, nxt, c, w;
} Graph[MAXE << 1];

std :: queue<int> q;

int id[MAXN][MAXN];
bool res[MAXN][MAXN];
bool banned[MAXN][MAXN];

int dist[MAXV];
bool vis[MAXV];
int head[MAXV], cur[MAXV];
int cnt = 1, ntot;

int N, M;

inline void AddEdge( const int &from, const int &to, const int &C, const int &W ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	Graph[cnt].c = C, Graph[cnt].w = W, head[from] = cnt;
}

inline void AddE( const int &from, const int &to, const int &C, const int &W ) {
	AddEdge( from, to, C, W ), AddEdge( to, from, 0, -W );
}

inline bool SPFA( const int &S, const int &T ) {
	while( ! q.empty() ) q.pop();
	rep( i, 1, ntot ) dist[i] = INF, vis[i] = false;
	dist[S] = 0, q.push( S ), vis[S] = true;
	while( ! q.empty() ) {
		int u = q.front();
		vis[u] = false, q.pop();
		for( int i = head[u], v ; i ; i = Graph[i].nxt )
			if( Graph[i].c && dist[v = Graph[i].to] > dist[u] + Graph[i].w ) {
				dist[v] = dist[u] + Graph[i].w;
				if( ! vis[v] ) q.push( v ), vis[v] = true;
			}
	}
	return dist[T] < INF;
}

int DFS( const int &u, const int &lin, const int &T, int &cost ) {
	if( u == T ) return lin;
	int used = 0, ret, v, c, w; vis[u] = true;
	for( int &i = cur[u] ; i ; i = Graph[i].nxt ) {
		v = Graph[i].to, c = Graph[i].c, w = Graph[i].w;
		if( c && ! vis[v] && dist[v] == dist[u] + w &&
		    ( ret = DFS( v, Min( lin - used, c ), T, cost ) ) ) {
			cost += Graph[i].w * ret;
			used += ret, Graph[i].c -= ret, Graph[i ^ 1].c += ret;
			if( used == lin ) break;
		}
	}
	if( used < lin ) dist[u] = INF;
	return vis[u] = false, used;
}

std :: pair<int, int> Dinic( const int &S, const int &T ) {
	int flow = 0, cost = 0;
	while( SPFA( S, T ) ) {
		rep( i, 1, ntot ) vis[i] = false, cur[i] = head[i];
		flow += DFS( S, INF, T, cost );
	}
	return std :: make_pair( flow, cost );
}

int main() {
	read( N ), read( M );
	rep( i, 1, M ) {
		int u, v;
		read( u ), read( v );
		banned[v][u] = true;
	}
	ntot = N * ( N + 1 ) >> 1;
	const int s = ++ ntot, t = ++ ntot;
	int ID = 0;
	rep( i, 1, N )
		rep( j, i + 1, N )
			id[i][j] = ++ ID;
	rep( i, 1, N )
		rep( j, i + 1, N ) {
			AddE( s, id[i][j], 1, 0 );
			if( ! banned[i][j] ) AddE( id[i][j], j + ID, 1, 0 );
			if( ! banned[j][i] ) AddE( id[i][j], i + ID, 1, 0 );
		}
	rep( i, 1, N )
		rep( j, 1, N - 1 )
			AddE( i + ID, t, 1, 2 * j - 1 );
	std :: pair<int, int> tmp = Dinic( s, t );
	rep( i, 1, N )
		rep( j, i + 1, N ) {
			int u = id[i][j];
			for( int k = head[u] ; k ; k = Graph[k].nxt )
				if( ID < Graph[k].to && Graph[k ^ 1].c ) {
					if( Graph[k].to == ID + j ) res[i][j] = true;
					else res[j][i] = true;
					break;
				}
		}
	rep( i, 1, N ) {
		rep( j, 1, N )
			putchar( res[i][j] ? '1' : '0' );
		puts( "" );
	}
	return 0;
}