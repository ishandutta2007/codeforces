#include <cstdio>

typedef long long LL;

const int MAXN = 50005, MAXK = 505;

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

int tot[MAXK], sta[MAXN], seq[MAXN];
int head[MAXN], siz[MAXN], mx[MAXN], dist[MAXN];
int N, K, rt, top, cnt; LL ans;
bool vis[MAXN];

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void resize( const int u, const int fa )
{
	mx[u] = 0, siz[u] = 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && ! vis[v] )
			resize( v, u ), siz[u] += siz[v],
			mx[u] = MAX( mx[u], siz[v] );
}

bool getCen( const int u, const int fa, const int all )
{
	if( MAX( mx[u], all - siz[u] ) <= all / 2 ) { return rt = u; }
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && ! vis[v] )
			if( getCen( v, u, all ) ) return true;
	return false;
}

void getDist( const int u, const int fa )
{
	dist[u] = dist[fa] + 1, sta[++ top] = u;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && ! vis[v] )
			getDist( v, u );
}

void cal( const int u )
{
	int len = 0;
	tot[dist[u] = 0] ++, seq[++ len] = u;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ! vis[v = Graph[i].to] )
		{
			getDist( v, u );
			for( int i = 1 ; i <= top ; i ++ )
				if( dist[sta[i]] <= K ) ans += tot[K - dist[sta[i]]];
			while( top ) 
			{
				if( dist[sta[top]] <= K ) tot[dist[seq[++ len] = sta[top]]] ++;
				top --;
			}
		}
	while( len ) tot[dist[seq[len --]]] --;
}

void divide( const int u )
{
	resize( u, 0 );
	getCen( u, 0, siz[u] );
	cal( rt ), vis[rt] = true;
	int tmp = rt;
	for( int i = head[tmp], v ; i ; i = Graph[i].nxt )
		if( ! vis[v = Graph[i].to] )
			divide( v );
	vis[rt] = false;
}

int main()
{
	read( N ), read( K );
	for( int i = 1, a, b ; i < N ; i ++ )
		read( a ), read( b ), addEdge( a, b ), addEdge( b, a );
	divide( 1 );
	write( ans ), putchar( '\n' );
	return 0;
}