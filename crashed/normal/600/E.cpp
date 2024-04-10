#include <cstdio>

typedef long long LL;

const int MAXN = 1e5 + 5;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

struct edge
{
	int to, nxt;
}Graph[MAXN << 1];

int count[MAXN];
int head[MAXN], col[MAXN], siz[MAXN]; LL ans[MAXN];
int mx; LL res;
int N, cnt, dis;

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void init( const int u, const int fa )
{
	siz[u] = 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			init( v, u ), siz[u] += siz[v];
}

void cal( const int u, const int fa, const int t )
{
	if( dis == u ) return ;
	count[col[u]] += t;
	if( count[col[u]] > mx ) mx = count[col[u]], res = col[u];
	else if( count[col[u]] == mx ) res += col[u];
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			cal( v, u, t );
}

void DFS( const int u, const int fa, const bool kep )
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
	cal( u, fa, 1 );
	dis = 0, ans[u] = res;
	if( ! kep ) cal( u, fa, -1 ), mx = res = 0;
}

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( col[i] );
	for( int i = 1, x, y ; i < N ; i ++ ) read( x ), read( y ), addEdge( x, y ), addEdge( y, x );
	init( 1, 0 );
	DFS( 1, 0, 1 );
	for( int i = 1 ; i <= N ; i ++ ) write( ans[i] ), putchar( i == N ? '\n' : ' ' );
	return 0;
}
/*
5
1 2 1 2 1
1 2
1 3
3 4
3 5
*/