#include <cmath>
#include <cstdio>

const int MAXN = 3005, MAXLOG = 15;

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
_T ABS( const _T a )
{
	return a < 0 ? -a : a;
}

struct edge
{
	int to, nxt;
}Graph[MAXN << 1];

int f[MAXN][MAXLOG];
int sta[MAXN], top;
int cir[MAXN];
int head[MAXN], dep[MAXN], col[MAXN];
int N, lg2, cnt, siz;
bool inSta[MAXN], onCir[MAXN];

void balance( int &u, const int steps ) 
{ 
	for( int i = 0 ; ( 1 << i ) <= steps ; i ++ ) 
		if( steps & ( 1 << i ) ) 
			u = f[u][i]; 
}

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

bool findCircle( const int u, const int fr )
{
	if( inSta[u] )
	{
		int v;
		do onCir[cir[++ siz] = v = sta[top --]] = true; while( v ^ u );
		return true;
	}
	inSta[sta[++ top] = u] = true;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
	{
		v = Graph[i].to;
		if( v ^ fr && findCircle( v, u ) ) return true;
	}
	inSta[sta[top --]] = false;
	return false;
}

void DFS( const int u, const int fa, const int c )
{
	col[u] = c, f[u][0] = fa, dep[u] = dep[fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && ! onCir[v] ) 
			DFS( v, u, c );
}

void init()
{
	lg2 = log2( N );
	for( int j = 1 ; j <= lg2 ; j ++ )
		for( int i = 1 ; i <= N ; i ++ )
			f[i][j] = f[f[i][j - 1]][j - 1];
}

int LCA( int u, int v )
{
	if( dep[u] > dep[v] ) balance( u, dep[u] - dep[v] );
	if( dep[v] > dep[u] ) balance( v, dep[v] - dep[u] );
	if( u == v ) return u;
	for( int i = lg2 ; ~ i ; i -- ) if( f[u][i] ^ f[v][i] ) u = f[u][i], v = f[v][i];
	return f[u][0];
}

int dist( const int u, const int v ) { return dep[u] + dep[v] - 2 * dep[LCA( u, v )] + 1; }

int main()
{
	read( N );
	for( int i = 1, fr, to ; i <= N ; i ++ ) 	
		read( fr ), read( to ), fr ++, to ++, addEdge( fr, to ), addEdge( to, fr );
	findCircle( 1, 0 );
	for( int i = 1 ; i <= siz ; i ++ ) DFS( cir[i], 0, i );
	init();
	double ans = 0;
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= N ; j ++ )
		{
			if( col[i] == col[j] ) ans += 1.0 / dist( i, j );
			else
			{
				int lin = dep[i] + dep[j], lef = ABS( col[i] - col[j] ) - 1, rig = siz - 2 - lef;
				ans += 1.0 / ( lin + lef ) + 1.0 / ( lin + rig ) - 1.0 / ( lin + lef + rig );
			}
		}
	printf( "%.15lf\n", ans );
	return 0;
}