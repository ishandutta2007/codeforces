#include <cstdio>
#include <utility>
using namespace std;

typedef long long LL;
typedef pair<int, int> Edge;

const int mod = 998244353;
const int MAXN = 3e3 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ); s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

int f[MAXN][MAXN];
int lch[MAXN], rch[MAXN], tot[MAXN];
bool able[MAXN];

int fa[MAXN], siz[MAXN], Etot[MAXN];

Edge E[MAXN * MAXN];
int Graph[MAXN][MAXN];
int N, ID;

int Edg( const int n ) { return n * ( n - 1 ) >> 1; }
int Sub( int x, int v ) { return x < v ? x + mod - v : x - v; }
int Mul( LL x, int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
int Add( int x, int v ) { return x + v >= mod ? x + v - mod : x + v; }
int FindSet( const int u ) { return fa[u] = ( fa[u] == u ? u : FindSet( fa[u] ) ); }

void DFS( const int u )
{
	if( u <= N ) { tot[u] = f[u][1] = 1; return; }
	int l = lch[u], r = rch[u]; DFS( l ), DFS( r );
	for( int j = 1 ; j <= tot[r] ; j ++ )
		for( int k = 1 ; k <= tot[l] ; k ++ )
			f[u][j + k] = Add( f[u][j + k], Mul( f[l][k], f[r][j] ) );
	tot[u] = tot[l] + tot[r];
	if( able[u] ) f[u][1] = Add( f[u][1], 1 );
}

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= N ; j ++ )
		{
			read( Graph[i][j] );
			if( i < j ) E[Graph[i][j]] = Edge( i, j );
		}
	for( int i = 1 ; i <= N << 1 ; i ++ )
		fa[i] = i, siz[i] = i <= N;
	int cnt = N, rt = N;
	for( int i = 1 ; i <= N ; i ++ ) f[i][1] = 1;
	for( int i = 1, u, v ; i <= Edg( N ) ; i ++ )
	{
		u = FindSet( E[i].first ), 
		v = FindSet( E[i].second );
		if( u != v )
		{
			fa[u] = fa[v] = ++ cnt;
			lch[cnt] = u, rch[cnt] = v, rt = cnt;
			Etot[cnt] = Etot[u] + Etot[v] + 1, siz[cnt] = siz[u] + siz[v];
			if( Etot[cnt] == Edg( siz[cnt] ) ) able[cnt] = true;
		}
		else
		{
			if( ( ++ Etot[u] ) == Edg( siz[u] ) )
				able[u] = true;
		}
	}
	DFS( rt );
	for( int k = 1 ; k <= N ; k ++ ) write( f[rt][k] ), putchar( k == N ? '\n' : ' ' );
	return 0;
}