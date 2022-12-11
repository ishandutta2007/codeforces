#include <cstdio>
#include <cstdlib>
#include <assert.h>
using namespace std;

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1e5 + 5, MAXS = 1e7 + 5;

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

int lch[MAXS], rch[MAXS], val[MAXS], siz[MAXS];

int jump[MAXN], tmp[MAXN];
int N, M, S, tot, ID, rt; LL T;

#define Go( x, i ) ( ( (x) + (i) - 1 + N ) % N + 1 )

void Upt( const int x ) { if( x ) siz[x] = siz[lch[x]] + siz[rch[x]] + 1; }

int Alloc( const int o )
{
	int r = ++ tot;
	if( tot >= MAXS ) exit( 19329874 );
	lch[r] = lch[o], rch[r] = rch[o];
	val[r] = val[o], siz[r] = siz[o];
	return r;
}

void SplitRnk( const int u, const int k, int &x, int &y )
{
	if( ! u ) return void( x = y = 0 ); int cur = Alloc( u );
	if( k <= siz[lch[u]] ) y = cur, SplitRnk( lch[u], k, x, lch[cur] );
	else x = cur, SplitRnk( rch[u], k - siz[lch[u]] - 1, rch[cur], y );
	Upt( cur );
}

int Merge( const int u, const int v )
{
	if( ! u || ! v ) return u + v; 
	int cur;
	if( rand() & 1 )
	{
		cur = Alloc( u );
		rch[cur] = Merge( rch[u], v );
		return Upt( cur ), cur;
	}
	else
	{
		cur = Alloc( v );
		lch[cur] = Merge( u, lch[v] );
		return Upt( cur ), cur;
	}
}

void DFS( const int x )
{
	if( ! x ) return ;
	DFS( lch[x] ); 
	jump[++ ID] = val[x];
	DFS( rch[x] );
}

int Build( const int l, const int r )
{
	if( l > r ) return 0;
	int mid = l + r >> 1;
	val[mid] = jump[mid];
	lch[mid] = Build( l, mid - 1 );
	rch[mid] = Build( mid + 1, r );
	Upt( mid ); return mid;
}

void Rebuild()
{
	ID = 0, DFS( rt );
	tot = N, rt = Build( 1, N );
}

void Init()
{
	rep( i, 1, N ) jump[i] = i;
	rt = Build( 1, N ), tot = N; 
	int p, q, x, y;
	rep( i, 1, N - 1 )
	{
		if( i % 700 == 0 ) Rebuild();
		
		SplitRnk( rt, i, x, p );
		if( M <= siz[p] ) SplitRnk( p, M, p, x );
		else SplitRnk( rt, M - siz[p], x, y ), p = Merge( p, x );
		SplitRnk( rt, N - i, q, x );
		if( N - M <= siz[q] ) SplitRnk( q, siz[q] - ( N - M ), x, q );
		else SplitRnk( rt, M + siz[q], x, y ), q = Merge( y, q );
		rt = Merge( p, q );
	}
	ID = 0, DFS( rt );
}

int main()
{
	srand( 1e9 + 9 );
	read( N ), read( M ), read( S ), read( T );
	Init();
	
	int rem = T % N; T -= rem;
	for( ; rem ; rem -- )
	{
		if( S <= M ) S = Go( S, rem );
		else S = Go( S, - rem );
	}
	for( LL idx = T / N ; idx ; idx >>= 1 )
	{
		if( idx & 1 ) S = jump[S];
		rep( i, 1, N ) tmp[i] = jump[i];
		rep( i, 1, N ) jump[i] = tmp[jump[i]];
	}
	write( S ), putchar( '\n' );
	return 0;
}