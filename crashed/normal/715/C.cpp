#include <map>
#include <cstdio>
using namespace std;

typedef long long LL;

#define int LL

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
	int to, nxt, w;
}Graph[MAXN << 1];

map<int, int> mp1, mp2;

int pw[MAXN], inv[MAXN], sta[MAXN], seq[MAXN];
int head[MAXN], siz[MAXN], mx[MAXN], dep[MAXN], go[MAXN], to[MAXN];
LL ans;
int N, mod, top, cnt;
bool vis[MAXN];

int fix( const int x ) { return ( x % mod + mod ) % mod; }
bool visible( const int u, const int fa ) { return u ^ fa && ! vis[u]; }

void upt( const int x, const int v )
{
	mp2[go[x]] += v, 
	mp1[fix( -1ll * to[x] * inv[dep[x]] % mod )] += v;
}

void addEdge( const int from, const int to, const int W )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from], Graph[cnt].w = W;
	head[from] = cnt;
}

int exgcd( const int a, const int b, int &x, int &y )
{
	if( ! b ) { x = 1, y = 0; return a; }
	int ret = exgcd( b, a % b, y, x );
	 y -= x * ( a / b );
	return ret;
}

void init()
{
	pw[0] = inv[0] = 1;
	int y; exgcd( pw[1] = 10, mod, inv[1], y ); inv[1] = fix( inv[1] );
	for( int i = 2 ; i <= N ; i ++ ) 
		pw[i] = 10ll * pw[i - 1] % mod, 
		inv[i] = 1ll * inv[i - 1] * inv[1] % mod;
}

void resize( const int u, const int fa )
{
	siz[u] = 1, mx[u] = 0;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( visible( v = Graph[i].to, fa ) )
			resize( v, u ), siz[u] += siz[v], mx[u] = MAX( mx[u], siz[v] );
}

int getCen( const int u, const int fa, const int all )
{
	if( MAX( mx[u], all - siz[u] ) <= all / 2 ) return u;
	for( int i = head[u], v, tmp ; i ; i = Graph[i].nxt )
		if( visible( v = Graph[i].to, fa ) )
			if( tmp = getCen( v, u, all ) ) return tmp;
	return 0;
}

void getDist( const int u, const int fa )
{
	sta[++ top] = u;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( visible( v = Graph[i].to, fa ) )
		{
			dep[v] = dep[u] + 1,
			to[v] = ( 10ll * to[u] % mod + Graph[i].w ) % mod,
			go[v] = ( go[u] + 1ll * Graph[i].w * pw[dep[u]] % mod ) % mod;
			getDist( v, u );
		}
}

void cal( const int u )
{
	int l;
	seq[l = 1] = u;
	mp1[go[u] = dep[u] = 0] ++, mp2[to[u] = 0] ++;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ! vis[v = Graph[i].to] )
		{
			go[v] = to[v] = Graph[i].w, dep[v] = 1;
			getDist( v, u );
			for( int j = 1 ; j <= top ; j ++ )
				ans += mp1[go[sta[j]]] + mp2[fix( -1ll * to[sta[j]] * inv[dep[sta[j]]] % mod )];
			for( ; top ; top -- ) upt( seq[++ l] = sta[top], 1 );
		}
	for( ; l ; l -- ) upt( seq[l], -1 ); 
}

void divide( const int u )
{
	resize( u, 0 ); 
	int tmp = getCen( u, 0, siz[u] );
	cal( tmp ), vis[tmp] = true;
	for( int i = head[tmp], v ; i ; i = Graph[i].nxt )
		if( ! vis[v = Graph[i].to] )
			divide( v );
	vis[tmp] = false;
}

signed main()
{
	read( N ), read( mod );
	for( int i = 1, a, b, c ; i < N ; i ++ )
		read( a ), read( b ), read( c ), a ++, b ++, c %= mod,
		addEdge( a, b, c ), addEdge( b, a, c );
	init();
	divide( 1 );
	write( ans ), putchar( '\n' );
	return 0;
}