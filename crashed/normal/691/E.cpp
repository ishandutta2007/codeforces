#include <cstdio>

typedef long long LL;

#define int LL

const int mod = 1e9 + 7;
const int MAXN = 105;

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

void add( int &, const int );

struct matrix
{
	int mat[MAXN][MAXN] = {};
	int n, m;
	
	matrix() { n = m = 0; }
	matrix( const int N ) { n = m = N; }
	matrix( const int N, const int M ) { n = N, m = M; }
	
	int* operator [] ( const int indx ) { return mat[indx]; }
	
	matrix operator * ( matrix b ) const
	{
		matrix ret = matrix( n, b.m );
		for( int i = 1 ; i <= ret.n ; i ++ )
			for( int k = 1 ; k <= m ; k ++ )
				if( mat[i][k] )
					for( int j = 1 ; j <= ret.m ; j ++ )
						add( ret[i][j], 1ll * mat[i][k] * b[k][j] % mod );
		return ret;
	}
	
	void operator *= ( matrix b ) { *this = *this * b; }
};

matrix vec, G;

LL a[MAXN];
int N; LL K;

int lowbit( const int x ) { return x & ( -x ); }
void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }
int count( LL x ) { int ret = 0; for( ; x ; x -= lowbit( x ) ) ret ++; return ret; }

matrix qkpow( matrix base, LL indx )
{
	matrix ret = matrix( base.n );
	for( int i = 1 ; i <= ret.n ; i ++ ) ret[i][i] = 1;
	while( indx )
	{
		if( indx & 1 ) ret *= base;
		base *= base, indx >>= 1;
	}
	return ret;
}

signed main()
{
	read( N ), read( K );
	G = matrix( N ), vec = matrix( 1, N );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= N ; j ++ )
			if( count( a[i] ^ a[j] ) % 3 == 0 )
				G[i][j] ++;
	for( int i = 1 ; i <= N ; i ++ ) vec[1][i] = 1;
	vec *= qkpow( G, K - 1 );
	int ans = 0;
	for( int i = 1 ; i <= N ; i ++ ) add( ans, vec[1][i] );
	write( ans ), putchar( '\n' );
	return 0;
}