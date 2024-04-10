#include <cstdio>
#include <cstring>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5, MAXS = 1e7 + 5, MAXL = 3e6 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = ( s == '-' ), s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) s = getchar();
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

namespace SegTree
{
	int lch[MAXS], rch[MAXS], siz[MAXS];
	int rt[MAXN], ntot = 0;
	
	inline int NewNode( const int x )
	{
		int r = ++ ntot; siz[r] = siz[x];
		lch[r] = lch[x], rch[r] = rch[x];
		return r;
	}
	
	inline void Upt( const int x ) { siz[x] = siz[lch[x]] + siz[rch[x]]; }
	
	int Update( const int x, const int l, const int r, const int p, const int delt )
	{
		int cur = NewNode( x );
		if( l == r ) { siz[cur] += delt; return cur; }
		int mid = ( l + r ) >> 1;
		if( p <= mid ) lch[cur] = Update( lch[x], l, mid, p, delt );
		else rch[cur] = Update( rch[x], mid + 1, r, p, delt );
		Upt( cur ); return cur;
	}

	int Query( const int x, const int l, const int r, const int segL, const int segR )
	{
		if( segL > segR || ! x ) return 0;
		if( segL <= l && r <= segR ) return siz[x];
		int mid = ( l + r ) >> 1, ret = 0;
		if( segL <= mid ) ret += Query( lch[x], l, mid, segL, segR );
		if( mid  < segR ) ret += Query( rch[x], mid + 1, r, segL, segR );
		return ret;
	}
}

namespace Trie
{
	int ch[MAXL][26], prio[MAXL];
	int rt[MAXN], ntot = 0;

	inline int NewNode( const int x )
	{
		int r = ++ ntot; prio[r] = prio[x];
		memcpy( ch[r], ch[x], sizeof ch[x] );
		return r;
	}

	int Insert( const int x, const char *c, const int len, const int dep, const int val )
	{
		int cur = NewNode( x );
		if( len == dep ) { prio[cur] = val; return cur; }
		ch[cur][c[dep] - 'a'] = Insert( ch[x][c[dep] - 'a'], c, len, dep + 1, val );
		return cur;
	}

	int Find( const int x, const char *c, const int len, const int dep )
	{
		if( ! x ) return -1;
		if( len == dep ) return x;
		return Find( ch[x][c[dep] - 'a'], c, len, dep + 1 );
	}
}

int Q;

int main()
{
	read( Q );
	int val;
	char op[20], nam[30];
	for( int cas = 1 ; cas <= Q ; cas ++ )
	{
		scanf( "%s", op );
		Trie :: rt[cas] = Trie :: rt[cas - 1];
		SegTree :: rt[cas] = SegTree :: rt[cas - 1];
		if( op[0] == 's' )
		{
			scanf( "%s", nam ); read( val );
			int L = strlen( nam ), former = Trie :: Find( Trie :: rt[cas], nam, L, 0 );
			if( ~ former && Trie :: prio[former] > 0 ) 
				SegTree :: rt[cas] = SegTree :: Update( SegTree :: rt[cas], 1, 1e9, Trie :: prio[former], -1 );
			Trie :: rt[cas] = Trie :: Insert( Trie :: rt[cas], nam, L, 0, val );
			SegTree :: rt[cas] = SegTree :: Update( SegTree :: rt[cas], 1, 1e9, val, 1 );
		}
		if( op[0] == 'r' )
		{
			scanf( "%s", nam );
			int L = strlen( nam ), former = Trie :: Find( Trie :: rt[cas], nam, L, 0 );
			if( former == -1 || Trie :: prio[former] <= 0 ) continue;
			SegTree :: rt[cas] = SegTree :: Update( SegTree :: rt[cas], 1, 1e9, Trie :: prio[former], -1 );
			Trie :: rt[cas] = Trie :: Insert( Trie :: rt[cas], nam, L, 0, -1 );
		}
		if( op[0] == 'u' )
		{
			read( val );
			Trie :: rt[cas] = Trie :: rt[std :: max( cas - val - 1, 0 )];
			SegTree :: rt[cas] = SegTree :: rt[std :: max( cas - val - 1, 0 )];
		}
		if( op[0] == 'q' )
		{
			scanf( "%s", nam );
			int L = strlen( nam ), former = Trie :: Find( Trie :: rt[cas], nam, L, 0 );
			if( former == -1 || Trie :: prio[former] <= 0 ) puts( "-1" );
			else write( SegTree :: Query( SegTree :: rt[cas], 1, 1e9, 1, Trie :: prio[former] - 1 ) ), putchar( '\n' );
		}
		fflush(stdout);
	}
	return 0;
}