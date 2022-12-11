#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN = 4e5 + 5, MAXLOG = 20, MAXS = MAXN * 25;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct edge
{
	int to, nxt;
}Graph[MAXN << 1];

int f[MAXN][MAXLOG];
bool s[MAXS]; int lch[MAXS], rch[MAXS];
int dp[MAXN], seq[MAXN], ID;
int ch[MAXN][26], fa[MAXN], mx[MAXN], head[MAXN], rot[MAXN], fir[MAXN];
int N, lg2, rt, lst, tot, cnt, siz;
char S[MAXN];

void upt( const int x ) { s[x] = s[lch[x]] | s[rch[x]]; }
void copy( int a, int b ) { fa[a] = fa[b], mx[a] = mx[b], memcpy( ch[a], ch[b], sizeof ch[b] ); }

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void expand( const char c )
{
	int x = c - 'a', p = lst, cur = ++ tot;
	mx[cur] = mx[lst] + 1, lst = cur;
	while( p && ! ch[p][x] ) ch[p][x] = cur, p = fa[p];
	if( ! p ) { fa[cur] = rt; return ; }
	int q = ch[p][x];
	if( mx[q] == mx[p] + 1 ) { fa[cur] = q; return ; }
	int nq = ++ tot; copy( nq, q );
	mx[nq] = mx[p] + 1, fa[q] = fa[cur] = nq;
	while( p && ch[p][x] == q ) ch[p][x] = nq, p = fa[p];
}

void update( int &u, const int l, const int r, const int pos )
{
	if( ! u ) u = ++ siz;
	if( l == r ) { s[u] = true; return ; }
	int mid = l + r >> 1;
	if( pos <= mid ) update( lch[u], l, mid, pos );
	else update( rch[u], mid + 1, r, pos );	
	upt( u );
}

bool query( const int u, const int l, const int r, const int segL, const int segR )
{
	if( ! u ) return false;
	if( segL <= l && r <= segR ) return s[u];
	int mid = l + r >> 1, ret = false;
	if( segL <= mid ) ret |= query( lch[u], l, mid, segL, segR );
	if( mid < segR ) ret |= query( rch[u], mid + 1, r, segL, segR );
	return ret;
}

int merg( int u, int v )
{
	if( ! u || ! v ) return u + v;
	int cur = ++ siz;
	lch[cur] = merg( lch[u], lch[v] );
	rch[cur] = merg( rch[u], rch[v] );
	s[cur] = s[u] | s[v];
	return cur;
}

void DFS( const int u )
{
	seq[++ ID] = u;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
	{
		DFS( v = Graph[i].to );
		rot[u] = merg( rot[u], rot[v] );
		fir[u] = MIN( fir[u], fir[v] );
	}
}

int main()
{
	rt = lst = ++ tot;
	memset( fir, 0x3f, sizeof fir );
	read( N ), scanf( "%s", S + 1 );
	for( int i = 1 ; i <= N ; i ++ ) 
		expand( S[i] ), 
		update( rot[lst], 1, N, i ), fir[lst] = i;
	for( int i = 2 ; i <= tot ; i ++ ) addEdge( fa[i], i );
	DFS( rt );
	lg2 = log2( tot );
	for( int i = 1 ; i <= tot ; i ++ ) f[i][0] = fa[i];
	for( int j = 1 ; j <= lg2 ; j ++ )
		for( int i = 1 ; i <= tot ; i ++ )
			f[i][j] = f[f[i][j - 1]][j - 1];
	for( int i = tot, u, p ; i ; i -- )
	{
		u = p = seq[i];
		for( int k = lg2 ; ~ k ; k -- )
			if( f[p][k] > rt && ! query( rot[f[p][k]], 1, N, fir[u] - mx[u] + mx[f[p][k]], fir[u] - 1 ) )
				p = f[p][k];
		p = fa[p];
		dp[p] = MAX( dp[p], dp[u] + 1 );
	}
	write( dp[rt] ), putchar( '\n' );
	return 0;
}