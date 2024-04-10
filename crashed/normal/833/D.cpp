#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> node;

#define val first
#define prod second

const int mod = 1e9 + 7, phi = mod - 1;
const int MAXN = 4e5 + 5, INF = 0x3f3f3f3f;

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
	int to, nxt, w, c;
}Graph[MAXN << 1];

struct Edge
{
	int to, w, c;
	Edge() {} Edge( const int T, const int W, const int C ) { to = T, w = W, c = C; }
};

node p1[MAXN], p2[MAXN];

vector<Edge> G[MAXN];

int mx[MAXN];
int head[MAXN], siz[MAXN];
int N, tot, l1, l2, ans = 1, exc = 1, cnt = 1;
bool vis[MAXN];

void addEdge( const int from, const int to, const int W, const int C ) 
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from], Graph[cnt].w = W, Graph[cnt].c = C;
	head[from] = cnt;
}

void addE( const int from, const int to, const int W, const int C ) 
{ addEdge( from, to, W, C ), addEdge( to, from, W, C ); }

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

int inv( const int a ) { return qkpow( a, mod - 2 ); }

void init( const int u, const int fa )
{
	siz[u] = 1;
	for( int i = 0, v ; i < G[u].size() ; i ++ )
		if( ( v = G[u][i].to ) ^ fa )
		{
			init( v, u ), siz[u] += siz[v];
			ans = 1ll * ans * qkpow( G[u][i].w, 1ll * siz[v] * ( N - siz[v] ) % phi ) % mod;
		}
}

void rebuild( const int u, const int fa )
{
	int lst = 0, cur;
	for( int i = 0, v ; i < G[u].size() ; i ++ )
		if( ( v = G[u][i].to ) ^ fa )
		{
			if( ! lst ) addE( lst = u, v, G[u][i].w, G[u][i].c );
			else addE( lst, cur = ++ tot, 1, -1 ), addE( cur, v, G[u][i].w, G[u][i].c ), lst = cur;
			rebuild( v, u );
		}
}

int getCen( const int u, const int fa, const int all )
{
	int ret = 0, tmp; siz[u] = 1;
	for( int i = head[u], v, id ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && ! vis[id = ( i >> 1 )] )
		{
			tmp = getCen( v, u, all );
			siz[u] += siz[v];
			mx[id] = MAX( siz[v], all - siz[v] );
			if( mx[id] < mx[ret] ) ret = id;
			if( mx[tmp] < mx[ret] ) ret = tmp;
		}
	return ret;
}

void DFS( const int u, const int fa, const int a, const int b, const int prd )
{
	if( u <= N ) p1[++ l1] = node( 2 * a - b, prd ), p2[++ l2] = node( 2 * b - a, prd );
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && ! vis[i >> 1] )
			DFS( v, u, a + ( Graph[i].c == 0 ), b + ( Graph[i].c == 1 ), 1ll * prd * Graph[i].w % mod );
}

int find( node *p, const int len, const node need )
{
	if( p[len] < need ) return len + 1;
	int l = 1, r = len, mid;
	while( r - l > 1 )
	{
		if( p[mid = l + r >> 1] < need ) l = mid + 1;
		else r = mid;
	}
	if( p[l] < need ) return r;
	return l;
}

void DFS1( const int u, const int fa, const int a, const int b, const int prd )
{
	if( u <= N )
	{
		int cur = lower_bound( p1 + 1, p1 + 1 + l1, node( b - 2 * a, 0 ) ) - p1;
		exc = 1ll * exc * qkpow( prd, cur - 1 ) % mod * p1[cur - 1].prod % mod;
		cur = lower_bound( p2 + 1, p2 + 1 + l2, node( a - b * 2, 0 ) ) - p2;
		exc = 1ll * exc * qkpow( prd, cur - 1 ) % mod * p2[cur - 1].prod % mod;
	}
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && ! vis[i >> 1] )
			DFS1( v, u, a + ( Graph[i].c == 0 ), b + ( Graph[i].c == 1 ), 1ll * prd * Graph[i].w % mod );
}

void divide( const int x, const int all )
{
	if( all == 1 ) return ;
	int cur = getCen( x, 0, all );
	int fr = Graph[cur << 1].to, to = Graph[cur << 1 | 1].to, w = Graph[cur << 1].w, c = Graph[cur << 1].c;
	vis[cur] = true;
	l1 = l2 = 0;
	DFS( fr, 0, 0, 0, 1 );
	sort( p1 + 1, p1 + 1 + l1 ), sort( p2 + 1, p2 + 1 + l1 );
	p1[0].prod = p2[0].prod = 1;
	for( int i = 2 ; i <= l1 ; i ++ ) p1[i].prod = 1ll * p1[i - 1].prod * p1[i].prod % mod;
	for( int i = 2 ; i <= l2 ; i ++ ) p2[i].prod = 1ll * p2[i - 1].prod * p2[i].prod % mod;
	DFS1( to, 0, c == 0, c == 1, w );
	if( siz[fr] > siz[to] ) siz[fr] = all - siz[to];
	else siz[to] = all - siz[fr];
	divide( fr, siz[fr] );
	divide( to, siz[to] );
}

int main()
{
	read( N ); tot = N;
	for( int i = 1, a, b, c, d ; i < N ; i ++ )
		read( a ), read( b ), read( c ), read( d ), 
		G[a].push_back( Edge( b, c, d ) ), G[b].push_back( Edge( a, c, d ) );
	init( 1, 0 );
	rebuild( 1, 0 );
	mx[0] = INF, divide( 1, tot );
	write( 1ll * ans * inv( exc ) % mod ), putchar( '\n' );
	return 0;
}