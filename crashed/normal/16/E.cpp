#include <cstdio>

typedef long long LL;

const int MAXN = 25, MAXS = ( 1 << 18 ) + 5;

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

double f[MAXS];
double a[MAXN][MAXN];
int N;

double P( const int n ) { return 2.0 / n / ( n - 1 ); }
bool in( const int S, const int i ) { return S & ( 1 << i - 1 ); }

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= N ; j ++ )
			scanf( "%lf", &a[i][j] );
	f[( 1 << N ) - 1] = 1;
	for( int S = ( 1 << N ) - 1 ; S ; S -- )
	{
		int siz = 0;
		for( int i = 1 ; i <= N ; i ++ ) siz += in( S, i );
		for( int i = 1 ; i <= N ; i ++ )
			for( int j = 1 ; j <= N ; j ++ )
				if( in( S, i ) && in( S, j ) )
					f[S ^ ( 1 << j - 1 )] += P( siz ) * a[i][j] * f[S];
	}
	for( int i = 1 ; i <= N ; i ++ ) printf( "%.6lf ", f[1 << i - 1] );
	puts( "" );
	return 0;
}