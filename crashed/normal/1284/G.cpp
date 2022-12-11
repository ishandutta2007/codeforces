#include <cstdio>
#include <vector>
#include <utility>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXL = 25, MAXN = 3e3 + 5, MAXE = 1e6 + 5;

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

struct MyGraph {
	struct Edge {
		int to, nxt, id;
	} Graph[MAXE << 1];
	
	int head[MAXN], cnt;

	MyGraph(): head{}, cnt( 1 ) {}
	
	inline Edge operator [] ( const int &idx ) const { return Graph[idx]; }

	inline void AddE( const int &from, const int &to, const int &W = 0 ) {
		AddEdge( from, to, W ), AddEdge( to, from, W );
	}

	inline void AddEdge( const int &from, const int &to, const int &W = 0 ) {
		Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
		Graph[cnt].id = W, head[from] = cnt;
	}

	inline void Clear( const int &n ) {
		cnt = 1;
		rep( i, 1, n ) head[i] = 0;
	}
};

MyGraph bip, tre;

int dist[MAXN], q[MAXN], pre[MAXN], ntot;

std :: vector<int> asso[MAXN];

int upp[MAXN], deg[MAXN];
int col[MAXN], faE[MAXN], dep[MAXN], cTot;
int seq[MAXN], tot;
bool inde[MAXN];

int frB[MAXN], toB[MAXN], vertA[MAXN];

int fa[MAXN];
int rig[MAXL][MAXL], dow[MAXL][MAXL];
int idA[MAXL][MAXL], idB[MAXL][MAXL];

char grid[MAXL][MAXL], ans[MAXL << 1][MAXL << 1];

int N, M, vA, vB, E;

#define ID( x, y ) ( ( (x) - 1 ) * ( M - 1 ) + (y) )

inline void MakeSet( const int &n ) {
	rep( i, 1, n ) fa[i] = i;
}

int FindSet( const int &u ) {
	return fa[u] == u ? u : ( fa[u] = FindSet( fa[u] ) );
}

inline void UnionSet( const int &u, const int &v ) {
	fa[FindSet( u )] = FindSet( v );
}

inline void Clear() {
	vA = vB = E = 0;
	MakeSet( N * M );
	rep( i, 1, N * M ) col[i] = 0;
	rep( i, 0, N ) rep( j, 0, M ) {
		idA[i][j] = idB[i][j] = 0;
		rig[i][j] = dow[i][j] = 0;
	}
}

void DFS( const int &u, const int &fa, const int &c ) {
	col[u] = c, dep[u] = dep[fa] + 1;
	for( int i = tre.head[u], v ; i ; i = tre[i].nxt )
		if( ( v = tre[i].to ) ^ fa ) 
			faE[v] = i, DFS( v, u, c );
}

int main() {
	int T; read( T );
	while( T -- ) {
		read( N ), read( M ), Clear();
		rep( i, 1, N ) scanf( "%s", grid[i] + 1 );

		rep( i, 1, N ) rep( j, 1, M )
			if( grid[i][j] == 'O' && ( i + j ) % 2 == 0 && ( i != 1 || j != 1 ) )
				idA[i][j] = ++ vA;
		rep( i, 1, vA ) upp[i] = 0, asso[i].clear();

		const int &bound = ( N - 1 ) * ( M - 1 ) + 1;
		rep( i, 1, N ) rep( j, 1, M - 1 )
			if( ! ( grid[i][j] == 'O' && grid[i][j + 1] == 'O' ) ) {
				int u = i == N ? bound : ID( i, j ),
					v = i == 1 ? bound : ID( i - 1, j );
				UnionSet( u, v );
			}
		rep( i, 1, N - 1 ) rep( j, 1, M )
			if( ! ( grid[i][j] == 'O' && grid[i + 1][j] == 'O' ) ) {
				int u = j == M ? bound : ID( i, j ),
					v = j == 1 ? bound : ID( i, j - 1 );
				UnionSet( u, v );
			}
		rep( i, 1, bound ) {
			if( ! col[FindSet( i )] )
				col[FindSet( i )] = ++ vB;
			col[i] = col[FindSet( i )];
		}
		rep( i, 1, N - 1 ) rep( j, 1, M - 1 )
			idB[i][j] = col[ID( i, j )];
		rep( i, 0, N ) idB[i][0] = idB[i][M] = col[bound];
		rep( j, 0, M ) idB[0][j] = idB[N][j] = col[bound];

		rep( i, 1, N ) rep( j, 1, M - 1 ) 
			if( grid[i][j] == 'O' && grid[i][j + 1] == 'O' ) {
				inde[rig[i][j] = ++ E] = false;
				frB[E] = idB[i - 1][j], toB[E] = idB[i][j];
				vertA[E] = idA[i][j] ? idA[i][j] : idA[i][j + 1];
				upp[vertA[E]] ++, asso[vertA[E]].push_back( E );
			} 
		rep( i, 1, N - 1 ) rep( j, 1, M ) {
			if( grid[i][j] == 'O' && grid[i + 1][j] == 'O' ) {
				inde[dow[i][j] = ++ E] = false;
				frB[E] = idB[i][j - 1], toB[E] = idB[i][j];
				vertA[E] = idA[i][j] ? idA[i][j] : idA[i + 1][j];
				upp[vertA[E]] ++, asso[vertA[E]].push_back( E );
			} 
		}

		bool isMatroid = true;
		rep( i, 1, vA )
			if( upp[i] < 2 ) {
				isMatroid = false;
				break;
			}
		if( ! isMatroid ) {
			puts( "NO" );
			continue;
		}
		while( true ) {
			ntot = E;
			const int src = ++ ntot, snk = ++ ntot;
			tot = cTot = 0;
			rep( i, 1, ntot ) dist[i] = INF, pre[i] = 0;
			MakeSet( vB );
			tre.Clear( vB );
			bip.Clear( ntot );
			rep( i, 1, vA ) deg[i] = 0;
			rep( i, 1, vB ) col[i] = 0;
			rep( i, 1, E ) 
				if( inde[i] ) {
					tre.AddE( frB[i], toB[i], i );
					deg[vertA[i]] ++, seq[++ tot] = i;
				}
			rep( i, 1, vB ) if( ! col[i] )
				DFS( i, 0, ++ cTot );
			rep( i, 1, E ) if( ! inde[i] ) {
				if( col[frB[i]] ^ col[toB[i]] ) {
					bip.AddEdge( src, i );
					rep( j, 1, tot )
						bip.AddEdge( seq[j], i );
				} else {
					int u = frB[i], v = toB[i];
					while( u ^ v ) {
						if( dep[u] < dep[v] ) 
							std :: swap( u, v );
						bip.AddEdge( tre[faE[u]].id, i ); 
						u = tre[faE[u] ^ 1].to;
					}
				}
				if( ! vertA[i] || deg[vertA[i]] + 1 <= upp[vertA[i]] - 2 ) {
					bip.AddEdge( i, snk );
					rep( j, 1, tot )
						bip.AddEdge( i, seq[j] );
				} else {
					for( const int &w : asso[vertA[i]] )
						if( inde[w] ) bip.AddEdge( i, w );
				}
			}
			int h = 1, t = 0;
			dist[q[++ t] = src] = 1;
			while( h <= t ) {
				int u = q[h ++];
				for( int i = bip.head[u], v ; i ; i = bip[i].nxt )
					if( dist[v = bip[i].to] > dist[u] + 1 )
						dist[q[++ t] = v] = dist[u] + 1, pre[v] = u;
			}
			if( dist[snk] == INF ) break;
			for( int u = pre[snk] ; 1 <= u && u <= E ; u = pre[u] )
				inde[u] ^= 1;
		}

		int siz = 0;
		rep( i, 1, E ) siz += inde[i];
		if( siz != vB - 1 ) {
			puts( "NO" );
			continue;
		}
		puts( "YES" );
		rep( i, 1, 2 * N - 1 ) 
			rep( j, 1, 2 * M - 1 )
				ans[i][j] = ' ';
		rep( i, 1, N ) rep( j, 1, M )
			ans[i * 2 - 1][j * 2 - 1] = grid[i][j];
		rep( i, 1, N ) rep( j, 1, M - 1 )
			if( rig[i][j] && ! inde[rig[i][j]] )
				ans[2 * i - 1][2 * j] = '-';
		rep( i, 1, N - 1 ) rep( j, 1, M )
			if( dow[i][j] && ! inde[dow[i][j]] )
				ans[2 * i][2 * j - 1] = '|';
		rep( i, 1, 2 * N - 1 ) {
			rep( j, 1, 2 * M - 1 )
				putchar( ans[i][j] );
			puts( "" );
		}
	}
	return 0;
}