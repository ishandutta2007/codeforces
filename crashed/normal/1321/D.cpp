#include <cstdio>

const int MAXN = 2e5 + 5, MAXM = 2e5 + 5;

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
}Graph[MAXM];

int q[MAXN];
int dist[MAXN], tot[MAXN];
int head[MAXN], seq[MAXN];
int N, M, K, cnt;

void addEdge( edge *G, int *h, int &count, const int from, const int to )
{
	G[++ count].to = to, G[count].nxt = h[from];
	h[from] = count;
}

void BFS( const int S )
{
	int h = 1, t = 0;
	for( int i = 1 ; i <= N ; i ++ ) dist[i] = N + 1;
	dist[S] = 0, q[++ t] = S;
	int u, v;
	while( h <= t )
	{
		u = q[h ++];
		for( int i = head[u] ; i ; i = Graph[i].nxt )
			if( dist[v = Graph[i].to] > dist[u] + 1 )
				dist[v] = dist[u] + 1, q[++ t] = v;
	}
}

int main()
{
	read( N ), read( M );
	for( int i = 1, a, b ; i <= M ; i ++ ) 
		read( a ), read( b ), addEdge( Graph, head, cnt, b, a );
	read( K );
	for( int i = 1 ; i <= K ; i ++ ) read( seq[i] );
	BFS( seq[K] );
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = head[i] ; j ; j = Graph[j].nxt )
			if( dist[Graph[j].to] == dist[i] + 1 )
				tot[Graph[j].to] ++;
	int mx = 0, mn = 0;
	for( int i = 1, u, v ; i < K ; i ++ )
	{
		u = seq[i], v = seq[i + 1];
		if( dist[v] == dist[u] - 1 ) 
		{
			if( tot[u] > 1 ) mx ++;
		}
		else mn ++, mx ++;
	}
	write( mn ), putchar( ' ' ), write( mx ), putchar( '\n' );
	return 0;
}