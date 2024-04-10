#include<cstdio>

const int mod = 1e9 + 7;
const int MAXN = 3005;

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

int f[MAXN][MAXN];
int head[MAXN];
int N, M, D, cnt;

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

int qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = 1ll * ret * base % mod;
		base = 1ll * base * base % mod, indx >>= 1;
	}
	return ret;
}

int inver( const int a ) { return qkpow( a, mod - 2 ); }
int fix( const int a ) { return ( a % mod + mod ) % mod; }
void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }

void DFS( const int u )
{
	for( int i = 1 ; i <= M ; i ++ ) f[u][i] = 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
	{
		DFS( v = Graph[i].to );
		for( int j = 1 ; j <= M ; j ++ ) 
			f[u][j] = 1ll * f[u][j] * f[v][j] % mod;
	}
	for( int i = 1 ; i <= M ; i ++ ) add( f[u][i], f[u][i - 1] );
}

int Lagrange()
{
	if( D <= M ) return f[1][D];
	int ans = 0, w = 1, L = 1;
	for( int i = 1 ; i <= M ; i ++ ) L = 1ll * L * ( D - i ) % mod;
	for( int i = 2 ; i <= M ; i ++ ) w = 1ll * w * inver( fix( 1 - i ) ) % mod;
	for( int i = 1 ; i <= M ; i ++ )
	{
		add( ans, 1ll * L * w % mod * inver( D - i ) % mod * f[1][i] % mod );
		if( i < M ) w = 1ll * w * fix( i - M ) % mod * inver( i ) % mod;
	}
	return ans;
}

int main()
{
	read( N ), read( D );
	for( int i = 2, p ; i <= N ; i ++ ) read( p ), addEdge( p, i );
	M = N + 1, DFS( 1 );
	write( Lagrange() ), putchar( '\n' );
	return 0;
}