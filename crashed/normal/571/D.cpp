#include <cstdio>
#include <vector>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1e6 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = ( s == '-' ), s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

struct Kruskal
{
	int DFN[MAXN], siz[MAXN], lea[MAXN];
	
	int lch[MAXN], rch[MAXN];
	int fa[MAXN], ID, visi;
	
	void MakeSet( const int n ) { rep( i, 1, n ) fa[i] = i; }
	int FindSet( const int u ) { return fa[u] = ( fa[u] == u ? u : FindSet( fa[u] ) ); }
	
	Kruskal(): lch{}, rch{}, fa{}, ID( 0 ) {}
	
	void Init( const int n )
	{
		ID = n;
		rep( i, 1, n << 1 ) 
			fa[i] = i, lch[i] = rch[i] = 0;
	}
	
	void Merge( int u, int v )
	{
		u = FindSet( u ), v = FindSet( v );
		if( u == v ) return ; ID ++;
		lch[ID] = u, rch[ID] = v;
		fa[u] = fa[v] = ID;
	}

	void DFS( const int u )
	{
		siz[u] = 1, DFN[u] = ++ visi;
		if( lch[u] ) DFS( lch[u] ), siz[u] += siz[lch[u]], lea[u] += lea[lch[u]];
		if( rch[u] ) DFS( rch[u] ), siz[u] += siz[rch[u]], lea[u] += lea[rch[u]];
		if( siz[u] == 1 ) lea[u] = 1;
	}

	void Construct() 
	{ 
		visi = 0;
		rep( i, 1, ID ) if( fa[i] == i ) DFS( i );
	}
};

Kruskal uni, mil;

std :: vector<int> del[MAXN];

LL neg[MAXN];
int qry[MAXN];
int add[MAXN], rai[MAXN];

int N, M;

namespace Seg1
{
	int tag[MAXN << 2];
	
	void Update( const int x, const int l, const int r, const int segL, const int segR, const int nTim )
	{
		if( segL <= l && r <= segR ) { tag[x] = nTim; return ; }
		int mid = ( l + r ) >> 1;
		if( segL <= mid ) Update( x << 1, l, mid, segL, segR, nTim );
		if( mid  < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, nTim );
	}

	int Query( const int x, const int l, const int r, const int p )
	{
		int ret = tag[x];
		if( l == r ) return ret;
		int mid = ( l + r ) >> 1;
		if( p <= mid ) ret = std :: max( ret, Query( x << 1, l, mid, p ) );
		else ret = std :: max( ret, Query( x << 1 | 1, mid + 1, r, p ) );
		return ret;
	}
}

namespace Seg2
{
	LL tag[MAXN << 2];
	
	void Update( const int x, const int l, const int r, const int segL, const int segR, const LL delt )
	{
		if( segL <= l && r <= segR ) { tag[x] += delt; return; }
		int mid = ( l + r ) >> 1;
		if( segL <= mid ) Update( x << 1, l, mid, segL, segR, delt );
		if( mid  < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, delt );
	}

	LL Query( const int x, const int l, const int r, const int p )
	{
		LL ret = tag[x];
		if( l == r ) return ret;
		int mid = ( l + r ) >> 1;
		if( p <= mid ) ret += Query( x << 1, l, mid, p );
		else ret += Query( x << 1 | 1, mid + 1, r, p );
		return ret;
	}
}

int main()
{
	read( N ), read( M );
	uni.Init( N ), mil.Init( N );
	char op[10];
	for( int i = 1, X, Y ; i <= M ; i ++ )
	{
		scanf( "%s", op ); read( X );
		if( op[0] == 'U' ) read( Y ), uni.Merge( X, Y );
		if( op[0] == 'M' ) read( Y ), mil.Merge( X, Y );
		if( op[0] == 'A' ) add[i] = uni.FindSet( X );
		if( op[0] == 'Z' ) rai[i] = mil.FindSet( X );
		if( op[0] == 'Q' ) qry[i] = X;
	}
	uni.Construct(), mil.Construct();
	rep( i, 1, M ) 
	{
		if( rai[i] ) 
			Seg1 :: Update( 1, 1, mil.ID, mil.DFN[rai[i]], mil.DFN[rai[i]] + mil.siz[rai[i]] - 1, i );
		if( qry[i] ) 
			del[Seg1 :: Query( 1, 1, mil.ID, mil.DFN[qry[i]] )].push_back( i );
	}
	rep( i, 1, M )
	{
		if( add[i] ) Seg2 :: Update( 1, 1, uni.ID, uni.DFN[add[i]], uni.DFN[add[i]] + uni.siz[add[i]] - 1, uni.lea[add[i]] );
		for( int j = 0 ; j < ( int ) del[i].size() ; j ++ )
			neg[del[i][j]] = Seg2 :: Query( 1, 1, uni.ID, uni.DFN[qry[del[i][j]]] );
		if( qry[i] ) write( Seg2 :: Query( 1, 1, uni.ID, uni.DFN[qry[i]] ) - neg[i] ), putchar( '\n' );
	}
	return 0;
}