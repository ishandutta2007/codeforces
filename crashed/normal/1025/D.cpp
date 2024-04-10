#include <cstdio>

const int MAXN = 705; 

template<typename _T>
void read( _T &x )
{
	int f = 1; char s = getchar(); x = 0;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
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

bool f[MAXN][MAXN][2];
bool link[MAXN][MAXN];
int a[MAXN];
int N;

int gcd( const int a, const int b ) { return b ? gcd( b, a % b ) : a; }

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= N ; j ++ )
			link[i][j] = gcd( a[i], a[j] ) > 1;
	for( int i = 1 ; i <= N ; i ++ ) link[0][i] = link[i][0] = link[i][N + 1] = link[N][i + 1] = true;
	for( int i = 0 ; i <= N ; i ++ ) f[i + 1][i][0] = f[i + 1][i][1] = true;
	for( int i = N ; i ; i -- )
		for( int j = i ; j <= N ; j ++ )
			for( int k = i ; k <= j ; k ++ )
			{
				if( link[i - 1][k] ) f[i][j][0] |= f[i][k - 1][1] & f[k + 1][j][0];
				if( link[k][j + 1] ) f[i][j][1] |= f[i][k - 1][1] & f[k + 1][j][0];
			}
	puts( f[1][N][0] | f[1][N][1] ? "Yes" : "No" );
	return 0;
}