#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int MAXN = 405, MAXM = 605;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

struct Edge
{
	int to, nxt;
}Graph[MAXM << 1];

int dist[MAXN][MAXN];
int head[MAXN];
int N, M, cnt = 1;

inline int Mul( LL x, int v ) { return x * v % mod; }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void BFS( const int sta, int *d )
{
	static int q[MAXN], h, t;
	h = 1, t = 0; int u, v;
	rep( i, 1, N ) d[i] = INF;
	d[q[++ t] = sta] = 0;
	while( h <= t )
	{
		u = q[h ++];
		for( int i = head[u] ; i ; i = Graph[i].nxt )
			if( d[v = Graph[i].to] > d[u] + 1 )
				d[q[++ t] = v] = d[u] + 1;
	}
}

int main()
{
	read( N ), read( M );
	rep( i, 1, M ) { int a, b;
		read( a ), read( b );
		AddEdge( a, b ), AddEdge( b, a );
	}
	rep( i, 1, N ) BFS( i, dist[i] );
	rep( i, 1, N ) rep( j, 1, N )
	{
		int cntZ = 0, ans = 1, in = 0;
		rep( k, 1, N ) 
		{
			if( dist[i][k] + dist[k][j] == dist[i][j] ) cntZ ++;
			else
			{
				in = 0;
				for( int idx = head[k], v ; idx ; idx = Graph[idx].nxt )
					if( dist[i][v = Graph[idx].to] + 1 == dist[i][k] && dist[j][v] + 1 == dist[j][k] )
						in ++;
				ans = Mul( ans, in );
			}
		}
		if( cntZ != dist[i][j] + 1 ) write( 0 );
		else write( ans ); putchar( j == N ? '\n' : ' ' );
	}
	return 0;
}