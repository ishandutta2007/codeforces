#include <cstdio>
#include <cstring>

#define Tour( c ) for( int c = 0 ; c < 26 ; c ++ )

typedef long long LL;

const int MAXN = 205, MAXL = 205;

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

struct matrix
{
	LL mat[MAXL][MAXL];
	int n, m;
	matrix() { m = n = 0, memset( mat, 0xc0, sizeof mat ); }
	matrix( const int N, const int M ) { n = N, m = M, memset( mat, 0xc0, sizeof mat ); }
	LL* operator [] ( const int indx ) { return mat[indx]; }
	
	matrix operator * ( matrix b ) 
	{
		matrix ret = matrix( n, b.m );
		for( int i = 1 ; i <= ret.n ; i ++ )
			for( int j = 1 ; j <= ret.m ; j ++ )
				for( int k = 1 ; k <= m ; k ++ )
					ret[i][j] = MAX( ret[i][j], mat[i][k] + b[k][j] );
		return ret;
	}
	
	void operator *= ( matrix b ) { *this = *this * b; }
};

int ch[MAXL][26], fail[MAXL], con[MAXL], q[MAXL];
int a[MAXN];
int N, cnt; LL L;
char S[MAXL];

matrix I( const int n ) { matrix ret = matrix( n, n ); for( int i = 1 ; i <= n ; i ++ ) ret[i][i] = 0; return ret; }

void insert( const int contri )
{
	int p = 0, id;
	for( int i = 1 ; S[i] ; i ++ )
	{
		id = S[i] - 'a';
		if( ! ch[p][id] ) ch[p][id] = ++ cnt;
		p = ch[p][id];
	}
	con[p] += contri;
}

void init()
{
	int h = 1, t = 0, u, v;
	Tour( i ) if( ch[0][i] ) q[++ t] = ch[0][i];
	while( h <= t )
	{
		u = q[h ++];
		Tour( i )
		{
			if( v = ch[u][i] ) fail[v] = ch[fail[u]][i], q[++ t] = v;
			else ch[u][i] = ch[fail[u]][i];
		}
		con[u] += con[fail[u]];
	}
}

matrix qkpow( matrix base, LL indx )
{
	matrix ret = I( base.n );
	while( indx )
	{
		if( indx & 1 ) ret *= base;
		base *= base, indx >>= 1;
	}
	return ret;
}

int main()
{
	read( N ), read( L );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	for( int i = 1 ; i <= N ; i ++ ) scanf( "%s", S + 1 ), insert( a[i] );
	init();
	matrix A = matrix( 1, cnt + 1 ), B = matrix( cnt + 1, cnt + 1 );
	for( int p = 0 ; p <= cnt ; p ++ )
		Tour( c )
			B[p + 1][ch[p][c] + 1] = MAX( B[p + 1][ch[p][c] + 1], ( LL ) con[ch[p][c]] );
	A[1][1] = 0;
	A *= qkpow( B, L );
	LL ans = 0;
	for( int p = 1 ; p <= cnt + 1 ; p ++ ) ans = MAX( ans, A[1][p] );
	write( ans ), putchar( '\n' );
	return 0;
}