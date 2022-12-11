#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>

const int INF = 0x3f3f3f3f;
const int MAXN = 2e4 + 5, MAXM = 1e4 + 5, MAXE = 1e6 + 5, MAXSIZ = 1e6 + 5, MAXLOG = 16;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct edge
{
	int to, nxt, c;
}Graph[MAXE << 1], G[MAXN << 1];

std :: queue<int> q;
std :: vector<int> cit, edg;

int f[MAXN][MAXLOG], id[MAXN][MAXLOG];
int head[MAXSIZ], dis[MAXSIZ], cur[MAXSIZ], ref[MAXSIZ];
int dep[MAXN], GHead[MAXN], fE[MAXN], x[MAXM], y[MAXM], ps[MAXN];
int N, M, lg2, siz, cnt = 1, cnt1;
bool vis[MAXSIZ];

void addEdge( const int from, const int to, const int C )
{
	Graph[++ cnt].to = to, Graph[cnt].c = C, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void addEdge( const int from, const int to )
{
	G[++ cnt1].to = to, G[cnt1].nxt = GHead[from], GHead[from] = cnt1;
}

void addE( const int from, const int to, const int C )
{
	addEdge( from, to, C ), addEdge( to, from, 0 );
}

bool BFS( const int S, const int T )
{
	while( ! q.empty() ) q.pop();
	for( int i = 1 ; i <= siz ; i ++ ) dis[i] = INF;
	dis[S] = 0, q.push( S );
	int u, v;
	while( ! q.empty() )
	{
		u = q.front(), q.pop();
		for( int i = head[u] ; i ; i = Graph[i].nxt )
			if( Graph[i].c && dis[v = Graph[i].to] > dis[u] + 1 )
				dis[v] = dis[u] + 1, q.push( v );
	}
	return dis[T] < INF;
}

int DFS( const int u, const int lin, const int T )
{
	if( u == T ) return lin;
	int res, used = 0, v, c;
	for( int &i = cur[u] ; i ; i = Graph[i].nxt )
		if( ( c = Graph[i].c ) && dis[v = Graph[i].to] == dis[u] + 1 &&
			( res = DFS( v, MIN( lin - used, c ), T ) ) )
		{
			used += res, Graph[i].c -= res, Graph[i ^ 1].c += res;
			if( used == lin ) break;
		}
	if( used < lin ) dep[u] = INF;
	return used;
}

int Dinic( const int S, const int T )
{
	int fl = 0;
	while( BFS( S, T ) )
	{
		for( int i = 1 ; i <= siz ; i ++ ) cur[i] = head[i];
		fl += DFS( S, INF, T );
	}
	return fl;
}

void DFS1( const int u, const int fa )
{
	f[u][0] = fa, dep[u] = dep[fa] + 1;
	if( fa ) id[u][0] = ++ siz, ref[siz] = fE[u];
	for( int i = GHead[u], v ; i ; i = G[i].nxt )
		if( ( v = G[i].to ) ^ fa ) fE[v] = i + 1 >> 1, DFS1( v, u );
}

void init()
{
	lg2 = log2( N );
	for( int j = 1 ; ( 1 << j ) <= N ; j ++ )
		for( int i = 1 ; i <= N ; i ++ )
		{
			f[i][j] = f[f[i][j - 1]][j - 1];
			if( ! f[i][j] ) continue; id[i][j] = ++ siz;
			if( f[i][j - 1] ) addE( id[i][j], id[i][j - 1], INF );
			if( f[i][j] ) addE( id[i][j], id[f[i][j - 1]][j - 1], INF );
		}
}

void balance( int &u, const int steps ) { for( int i = 0 ; ( 1 << i ) <= steps ; i ++ ) if( steps & ( 1 << i ) ) u = f[u][i]; }

int LCA( int u, int v )
{
	if( dep[u] > dep[v] ) balance( u, dep[u] - dep[v] );
	if( dep[v] > dep[u] ) balance( v, dep[v] - dep[u] );
	if( u == v ) return u;
	for( int i = lg2 ; ~ i ; i -- ) if( f[u][i] ^ f[v][i] ) u = f[u][i], v = f[v][i];
	return f[u][0];
}

void cover( const int u, const int top, const int s )
{
	int v = u, dis = dep[u] - dep[top];
	if( ! dis ) return ;
	int k = log2( dis ); balance( v, dis - ( 1 << k ) );
	addE( s, id[u][k], INF ); if( id[u][k] ^ id[v][k] ) addE( s, id[v][k], INF );
}

void DFS2( const int u )
{
	vis[u] = true;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( Graph[i].c && ! vis[v = Graph[i].to] ) DFS2( v );
}

int main()
{
	read( N ), read( M );
	for( int i = 1, a, b ; i < N ; i ++ ) read( a ), read( b ), addEdge( a, b ), addEdge( b, a );
	siz = M, DFS1( 1, 0 );
	init();
	const int S = ++ siz, T = ++ siz;
	for( int i = 2 ; i <= N ; i ++ ) addE( id[i][0], T, 1 );
	for( int i = 1, tmp ; i <= M ; i ++ )
	{
		read( x[i] ), read( y[i] );
		tmp = LCA( x[i], y[i] );
		cover( x[i], tmp, i ), cover( y[i], tmp, i );
		addE( S, i, 1 );
	}
	write( Dinic( S, T ) ), putchar( '\n' );
	DFS2( S );
	for( int i = 1 ; i <= M ; i ++ ) if( ! vis[i] ) cit.push_back( i );
	for( int i = 2 ; i <= N ; i ++ ) if( vis[id[i][0]] ) edg.push_back( fE[i] );
	write( cit.size() );
	for( int i = 0 ; i < cit.size() ; i ++ ) putchar( ' ' ), write( cit[i] );
	putchar( '\n' ), write( edg.size() );
	for( int i = 0 ; i < edg.size() ; i ++ ) putchar( ' ' ), write( edg[i] );
	putchar( '\n' );
	return 0;
}