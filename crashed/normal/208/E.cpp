#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> query;

const int MAXN = 1e5 + 5, MAXLOG = 20;

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

struct edge
{
	int to, nxt;
}Graph[MAXN << 1];

vector<query> q[MAXN];

int f[MAXN][MAXLOG];
int cnt[MAXN], ans[MAXN];
int head[MAXN], dep[MAXN], siz[MAXN];
int N, M, lg2, count, dis;
bool rt[MAXN];

void addEdge( const int from, const int to )
{
	Graph[++ count].to = to, Graph[count].nxt = head[from];
	head[from] = count;
}

void init( const int u, const int fa )
{
	dep[u] = dep[fa] + 1, siz[u] = 1, f[u][0] = fa;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			init( v, u ), siz[u] += siz[v];
}

void init()
{
	lg2 = log2( N );
	for( int j = 1 ; j <= lg2 ; j ++ )
		for( int i = 1 ; i <= N ; i ++ )
			f[i][j] = f[f[i][j - 1]][j - 1];
}

int jump( int u, const int steps )
{
	for( int i = 0 ; ( 1 << i ) <= steps ; i ++ )
		if( steps & ( 1 << i ) )
			u = f[u][i];
	return u;
}

void edit( const int u, const int fa, const int t )
{
	if( dis == u ) return;
	cnt[dep[u]] += t;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			edit( v, u, t );
}

void DFS( const int u, const int fa, const bool keep )
{
	int heavy = -1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			if( heavy == -1 || siz[heavy] < siz[v] )
				heavy = v;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && v ^ heavy )
			DFS( v, u, false );
	if( ~ heavy ) DFS( heavy, u, true ), dis = heavy;
	edit( u, fa, 1 ), dis = 0;
	for( int i = 0 ; i < ( int ) q[u].size() ; i ++ ) 
		ans[q[u][i].second] = cnt[q[u][i].first] - 1;
	if( ! keep ) edit( u, fa, -1 );
}

int main()
{
	read( N );
	for( int i = 1, f ; i <= N ; i ++ ) 
	{
		read( f );
		if( ! f ) rt[i] = true;
		else addEdge( f, i ), addEdge( i, f );
	}
	for( int i = 1 ; i <= N ; i ++ )
		if( rt[i] ) init( i, 0 );
	init();
	read( M );
	for( int i = 1, t, cur, d ; i <= M ; i ++ )
	{
		read( cur ), read( d );
		if( t = jump( cur, d ) ) q[t].push_back( query( dep[cur], i ) );
	}
	for( int i = 1 ; i <= N ; i ++ )
		if( rt[i] ) DFS( i, 0, false );  
	for( int i = 1 ; i <= M ; i ++ ) write( ans[i] ), putchar( i == M ? '\n' : ' ' );
	return 0;
}