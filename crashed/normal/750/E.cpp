#include <cstdio>
#include <cstring>

const int INF = 0x3f3f3f3f;
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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct matrix
{
	int mat[6][6];
	int n, m;
	
	matrix() { memset( mat, 0x3f, sizeof mat ), n = m = 0; }
	matrix( int N ) { memset( mat, 0x3f, sizeof mat ), n = m = N; }
	matrix( int N, int M ) { memset( mat, 0x3f, sizeof mat ), n = N, m = M; }
	
	int * operator [] ( const int indx ) { return mat[indx]; }
	
	matrix operator * ( matrix b ) const 
	{
		matrix ret( n, b.m );
		for( int i = 1 ; i <= ret.n ; i ++ )	
			for( int j = 1 ; j <= ret.m ; j ++ )
				for( int k = 1 ; k <= m ; k ++ )
					ret[i][j] = MIN( ret[i][j], mat[i][k] + b[k][j] );
		return ret;
	}
};

matrix prod[MAXN << 2];

char S[MAXN];
int N, Q;

matrix I( const int n )
{
	matrix ret( n );
	for( int i = 1 ; i <= n ; i ++ )
		ret[i][i] = 0;
	return ret;
}

matrix trans( const char c )
{
	matrix ret = I( 5 );
	if( c == '2' ) ret[1][1] = 1, ret[1][2] = 0;
	if( c == '0' ) ret[2][2] = 1, ret[2][3] = 0;
	if( c == '1' ) ret[3][3] = 1, ret[3][4] = 0;
	if( c == '6' ) ret[4][4] = 1, ret[5][5] = 1;
	if( c == '7' ) ret[4][4] = 1, ret[4][5] = 0;
	return ret;
}

void build( const int u, const int l, const int r )
{
	if( l > r ) return ;
	if( l == r ) { prod[u] = trans( S[l] ); return ; }
	int mid = l + r >> 1;
	build( u << 1, l, mid );
	build( u << 1 | 1, mid + 1, r );
	prod[u] = prod[u << 1] * prod[u << 1 | 1];
}

matrix query( const int u, const int l, const int r, const int segL, const int segR )
{
	if( segL <= l && r <= segR ) return prod[u];
	int mid = l + r >> 1;
	if( segR <= mid ) return query( u << 1, l, mid, segL, segR );
	if( mid < segL ) return query( u << 1 | 1, mid + 1, r, segL, segR );
	return query( u << 1, l, mid, segL, segR ) * query( u << 1 | 1, mid + 1, r, segL, segR ); 
}

int main()
{
	read( N ), read( Q );
	scanf( "%s", S + 1 );
	build( 1, 1, N );
	
	matrix beg( 1, 5 );
	beg[1][1] = 0;
	
	while( Q -- )
	{
		int L, R, ans;
		read( L ), read( R );
		ans = ( beg * query( 1, 1, N, L, R ) )[1][5];
		if( ans == INF ) write( -1 ), putchar( '\n' );
		else write( ans ), putchar( '\n' );
	}
	return 0;
}