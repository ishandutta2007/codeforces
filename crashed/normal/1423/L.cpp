#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef unsigned long long ull;

const int mod = 1e6 + 3;
const int MAXN = 1e3 + 5, MAXS = ( 1 << 20 ) + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

struct Switch
{
	ull bit[18];
	
	Switch(): bit{} {}
	
	void reset() { rep( i, 0, 17 ) bit[i] = 0llu; }
	void set( const int x ) { bit[x >> 6] |= 1llu << ( x & 63 ); }
	
	Switch operator ^ ( const Switch &b ) const
	{
		Switch ret;
		rep( i, 0, 17 )
			ret.bit[i] = bit[i] ^ b.bit[i];
		return ret;
	}
	
	int GetHash() const 
	{
		int ret = 0;
		rep( i, 0, 17 ) ret = ( ret * 69779ll % mod + bit[i] % mod ) % mod;
		return ret;
	}

	bool operator == ( const Switch &b ) const
	{
		rep( i, 0, 17 ) if( bit[i] ^ b.bit[i] ) return false;
		return true;
	}
};

Switch key[MAXS];
int val[MAXS], nxt[MAXS];
int head[mod], tot;

Switch lef[MAXS], rig[MAXS];

Switch s[35], cur;
int N, S, D;

#define Popcount( x ) __builtin_popcount( x )

void Insert( const Switch& nKey, const int nVal )
{
	int h = nKey.GetHash();
	for( int i = head[h] ; i ; i = nxt[i] )
		if( key[i] == nKey ) 
		{ 
			val[i] = std :: min( val[i], nVal ); 
			return ;
		}
	tot ++, key[tot] = nKey, val[tot] = nVal;
	nxt[tot] = head[h], head[h] = tot;
}

int Find( const Switch& nKey )
{
	int h = nKey.GetHash();
	for( int i = head[h] ; i ; i = nxt[i] )
		if( key[i] == nKey ) return val[i];
	return 1e9;
}

int main()
{
	read( N ), read( S ), read( D );
	rep( i, 1, S )
	{
		int C, x; read( C );
		while( C -- ) read( x ), s[i].set( x - 1 );
	}
	int L = S / 3, R = S - L;
	rep( i, 1, L ) lef[1 << ( i - 1 )] = s[i];
	rep( i, L + 1, S ) rig[1 << ( i - L - 1 )] = s[i];
	for( int T = 0 ; T < ( 1 << L ) ; T ++ )
		if( Popcount( T ) > 1 )
			lef[T] = lef[T & ( T - 1 )] ^ lef[T & ( - T )];
	for( int T = 0 ; T < ( 1 << R ) ; T ++ )
	{
		if( Popcount( T ) > 1 )
			rig[T] = rig[T & ( T - 1 )] ^ rig[T & ( - T )];
		Insert( rig[T], Popcount( T ) );
	}
	while( D -- )
	{
		cur.reset(); 
		int T, x; read( T ); 
		while( T -- ) read( x ), cur.set( x - 1 );
		int ans = 1e9;
		for( int U = 0 ; U < ( 1 << L ) ; U ++ )
			ans = std :: min( ans, Popcount( U ) + Find( cur ^ lef[U] ) );
		write( ans > S ? -1 : ans ), putchar( '\n' );
	}
	return 0;
}