#include <cstdio>

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

int fa[MAXN], siz[MAXN];
int N, M, mod;

void makeSet() { for( int i = 1 ; i <= N ; i ++ ) fa[i] = i, siz[i] = 1; }
int findSet( const int u ) { return fa[u] = ( fa[u] == u ? fa[u] : findSet( fa[u] ) ); }
void unionSet( int u, int v ) { u = findSet( u ), v = findSet( v ); if( u ^ v ) fa[u] = v, siz[v] += siz[u]; }

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

int main()
{
	int ans = 1, tot = 0;
	read( N ), read( M ), read( mod ); makeSet();
	for( int i = 1, a, b ; i <= M ; i ++ ) read( a ), read( b ), unionSet( a, b );
	for( int i = 1 ; i <= N ; i ++ ) if( fa[i] == i ) ans = 1ll * ans * siz[i] % mod, tot ++;
	if( tot == 1 ) { printf( "%d\n", 1 % mod ); return 0; }
	write( 1ll * ans * qkpow( N, tot - 2 ) % mod ), putchar( '\n' );
	return 0;
}