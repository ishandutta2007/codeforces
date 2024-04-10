#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef pair<int, int> Shirt;

#define qua first
#define cos second

const int MAXN = 2e5 + 5;

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

int ans[MAXN], ansTag[MAXN];
int tag[MAXN], val[MAXN], aux[MAXN];
int lch[MAXN], rch[MAXN];

Shirt s[MAXN];

int N, K, rt, ntot;

void Add( const int x, const int v1, const int v2 ) 
{
	if( ! x ) return ;
	val[x] += v1, tag[x] += v1;
	ans[x] += v2, ansTag[x] += v2;
}

void Normalize( const int x ) 
{
	if( ! tag[x] && ! ansTag[x] ) return ;
	Add( lch[x], tag[x], ansTag[x] ), Add( rch[x], tag[x], ansTag[x] );
	tag[x] = ansTag[x] = 0;
}

void SplitVal( const int u, const int k, int &x, int &y )
{
	if( ! u ) return void( x = y = 0 ); Normalize( u );
	if( val[u] <= k ) x = u, SplitVal( rch[u], k, rch[u], y );
	else y = u, SplitVal( lch[u], k, x, lch[u] );
}

int Merge( const int u, const int v )
{
	if( ! u || ! v ) return u | v; Normalize( u ), Normalize( v );
	if( aux[u] < aux[v] ) return rch[u] = Merge( rch[u], v ), u;
	return lch[v] = Merge( u, lch[v] ), v;
}

void Insert( int &r, const int ned )
{
	int x;
	SplitVal( r, val[ned] - 1, x, r );
	r = Merge( x, Merge( ned, r ) );
}

void DFS( const int x, int &to )
{
	if( ! x ) return ;
	Normalize( x );
	int t1 = lch[x], t2 = rch[x];
	lch[x] = rch[x] = 0;
	DFS( t1, to ), DFS( t2, to );
	Insert( to, x );
}

void Operate( const int c )
{
	int x, y;
	SplitVal( rt, c - 1, x, rt );
	Add( rt, - c, 1 );
	SplitVal( rt, c - 1, rt, y );
	int t = rt;
	DFS( t, rt = Merge( x, y ) );
}

void Pushdown( const int x )
{
	if( ! x ) return ;
	Normalize( x );
	Pushdown( lch[x] ), Pushdown( rch[x] );
}

int main()
{
	srand( 1e9 + 9 );
	read( N );
	rep( i, 1, N ) read( s[i].cos ), read( s[i].qua ), s[i].cos *= -1;
	read( K );
	rep( i, 1, K ) read( val[i] ), aux[i] = rand() * rand();
	rep( i, 1, K ) Insert( rt, i );
	sort( s + 1, s + 1 + N );
	per( i, N, 1 ) Operate( - s[i].cos );
	Pushdown( rt );
	rep( i, 1, K ) write( ans[i] ), putchar( i == K ? '\n' : ' ' );
	return 0;
}