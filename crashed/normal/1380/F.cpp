#include <cstdio>

typedef long long LL;

const int mod = 998244353;
const int MAXN = 5e5 + 5;

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

int Mul( LL, int );
int Add( int, int );
int Sub( int, int );

struct Matrix
{
	int mat[3][3] = {};
	int n, m;
	
	Matrix() { n = m = 0; }
	Matrix( int N ) { n = m = N; }
	Matrix( int N, int M ) { n = N, m = M; }
	int* operator [] ( const int indx ) { return mat[indx]; }
	
	Matrix operator * ( Matrix b ) const
	{
		Matrix ret( n, b.m );
		for( int i = 1 ; i <= n ; i ++ )	
			for( int k = 1 ; k <= m ; k ++ )
				if( mat[i][k] )
					for( int j = 1 ; j <= ret.m ; j ++ )
						ret[i][j] = Add( ret[i][j], Mul( mat[i][k], b[k][j] ) );
		return ret;
	}
};

Matrix prod[MAXN << 2];

int num[MAXN];

int coe[105];
int N, M;

int Sub( int x, int v ) { return x < v ? x - v + mod : x - v; }
int Mul( LL x, int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
int Add( int x, int v ) { return x + v >= mod ? x + v - mod : x + v; }
void Upt( const int x ) { prod[x] = prod[x << 1] * prod[x << 1 | 1]; }

Matrix I( const int n ) 
{ 
	Matrix ret( n, n ); 
	for( int i = 1 ; i <= n ; i ++ ) 
		ret[i][i] = 1; 
	return ret;
}

Matrix Get( const int n )
{
	Matrix ret( 2, 2 );
	if( num[n - 1] )
		ret[1][2] = coe[num[n - 1] * 10 + num[n]];
	ret[2][1] = 1, ret[2][2] = coe[num[n]];
	return ret;
}

void Init()
{
	for( int a = 0 ; a <= 9 ; a ++ )
		for( int b = 0 ; b <= 9 ; b ++ )
			coe[a + b] ++;
}

void Build( const int x, const int l, const int r )
{
	if( l > r ) return ;
	if( l == r ) { prod[x] = Get( l ); return ; }
	int mid = l + r >> 1;
	Build( x << 1, l, mid ); 
	Build( x << 1 | 1, mid + 1, r );
	Upt( x );
}

void Update( const int x, const int l, const int r, const int p )
{
	if( p < l || r < p ) return ;
	if( l == r ) { prod[x] = Get( p ); return ; }
	int mid = l + r >> 1;
	if( p <= mid ) Update( x << 1, l, mid, p );
	else Update( x << 1 | 1, mid + 1, r, p );
	Upt( x );
}

int main()
{
	read( N ), read( M );
	for( int i = 1 ; i <= N ; i ++ ) scanf( "%1d", &num[i] );
	Init(); 
	Build( 1, 1, N );
	
	int pos, d;
	Matrix base( 1, 2 );
	base[1][2] = 1;
	while( M -- )
	{
		read( pos ), read( d ), num[pos] = d;
		Update( 1, 1, N, pos ); 
		Update( 1, 1, N, pos + 1 );
		write( ( base * prod[1] )[1][2] ), putchar( '\n' );
	}
	return 0;
}