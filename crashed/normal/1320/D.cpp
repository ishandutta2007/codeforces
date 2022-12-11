#include <cstdio>

const int mod = 1e9 + 7;
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

struct modint
{
	int x;
	modint() { x = 0; }
	modint( const int V ) { x = V; }
	modint operator + ( const modint &b ) const { return modint( x + b.x >= mod ? x + b.x - mod : x + b.x ); }
	modint operator - ( const modint &b ) const { return modint( x < b.x ? x - b.x + mod : x - b.x ); }
	modint operator * ( const modint &b ) const { return modint( 1ll * x * b.x % mod ); }
	bool operator == ( const modint &b ) const { return x == b.x; }
};

struct HASH
{
	modint x, y;
	HASH() { x = y = 0; }
	HASH( const modint V ) { x = y = V; }
	HASH( const int V ) { x.x = y.x = V; }
	HASH( const modint X, const modint Y ) { x = X, y = Y; }
	HASH operator + ( const HASH &b ) const { return HASH( x + b.x, y + b.y ); }
	HASH operator - ( const HASH &b ) const { return HASH( x - b.x, y - b.y ); }
	HASH operator * ( const HASH &b ) const { return HASH( x * b.x, y * b.y ); }
	bool operator == ( const HASH &b ) const { return x == b.x && y == b.y; }
}h[2][MAXN], pw[MAXN];

const HASH base = HASH( 13, 19 );

int S[MAXN], cnt[MAXN];
int N, Q;

HASH getHash( const bool odd, const int l, const int r )
{
	return h[odd][r] - h[odd][l - 1] * pw[cnt[r] - cnt[l - 1]];
}

int main()
{
	read( N );
	pw[0] = ( modint ) 1;
	for( int i = 1 ; i <= N ; i ++ ) 
	{
		pw[i] = pw[i - 1] * base;
		scanf( "%1d", &S[i] );
		if( S[i] ) h[0][i] = h[0][i - 1], h[1][i] = h[1][i - 1];
		else h[0][i] = h[0][i - 1] * base + ( i & 1 ), h[1][i] = h[1][i - 1] * base + ! ( i & 1 );
		cnt[i] = cnt[i - 1] + ( ! S[i] );
	}
	read( Q );
	int l, r, L;
	while( Q -- )
	{
		read( l ), read( r ), read( L );
		puts( getHash( l & 1, l, l + L - 1 ) == getHash( r & 1, r, r + L - 1 ) && 
			  cnt[l + L - 1] - cnt[l - 1] == cnt[r + L - 1] - cnt[r - 1] ? "Yes" : "No" );
	}
	return 0;
}