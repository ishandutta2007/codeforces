#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 3e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

struct Edge
{
	int to, nxt;
}Graph[MAXN << 1];

int fa[MAXN];
int fath[MAXN], dep[MAXN];

int fr[MAXN], to[MAXN];
int met[MAXN];

int head[MAXN];
int N, M, Q, cnt = 1;

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void MakeSet( const int n ) { rep( i, 1, n ) fa[i] = i; }
int  FindSet( const int u ) { return fa[u] = ( fa[u] == u ? u : FindSet( fa[u] ) ); }

bool UnionSet( int u, int v )
{
	u = FindSet( u ), v = FindSet( v );
	if( u == v ) return false; fa[u] = v; return true;
}

void DFS( const int u, const int fa )
{
	dep[u] = dep[fath[u] = fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa ) DFS( v, u );
}

void FindPath( int u, int v )
{
	std :: vector<int> fir, sec;
	while( u ^ v )
	{
		if( dep[u] >= dep[v] )
			fir.push_back( u ), u = fath[u];
		else
			sec.push_back( v ), v = fath[v];
	}
	int n = fir.size(), m = sec.size();
	write( n + m + 1 ), putchar( '\n' );
	for( int i = 0 ; i < n ; i ++ )
		write( fir[i] ), putchar( ' ' );
	write( u ), putchar( ' ' );
	for( int i = m - 1 ; ~ i ; i -- )
		write( sec[i] ), putchar( ' ' );
	puts( "" );
}

int main()
{
	read( N ), read( M );
	MakeSet( N );
	rep( i, 1, M )
	{
		int u, v;
		read( u ), read( v );
		if( UnionSet( u, v ) )
			AddEdge( u, v ), AddEdge( v, u );
	}
	read( Q );
	rep( i, 1, Q )
	{
		read( fr[i] ), read( to[i] );
		met[fr[i]] ++, met[to[i]] ++;
	}
	bool flg = true;
	rep( i, 1, N )
		if( met[i] % 2 )
		{ flg = false; break; }
	if( ! flg )
	{
		puts( "NO" );
		int ans = 0;
		rep( i, 1, N )
			ans += met[i] % 2;
		write( ans >> 1 ), putchar( '\n' );
	}
	else
	{
		DFS( 1, 0 );
		puts( "YES" );
		rep( i, 1, Q )
			FindPath( fr[i], to[i] );
	}
	return 0;
}