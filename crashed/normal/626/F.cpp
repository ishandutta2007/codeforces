#include <cstdio>
#include <algorithm>

const int mod = 1e9 + 7;
#ifdef _DEBUG
const int MAXN = 15, MAXK = 105;
#else
const int MAXN = 205, MAXK = 1005;
#endif

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

int f[MAXN][MAXN][MAXK];
int a[MAXN];
int N, K;

void upt( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }

int main()
{
	read( N ), read( K );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	std :: sort( a + 1, a + 1 + N );
	f[0][0][0] = 1;
	int t, dif;
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 0 ; j <= i ; j ++ )
			for( int k = 0 ; k <= K ; k ++ )
			{
				dif = a[i] - a[i - 1], t = j * dif;
				if( k >= t ) upt( f[i][j][k], f[i - 1][j][k - t] );
				if( k >= t ) upt( f[i][j][k], 1ll * f[i - 1][j][k - t] * j % mod );
				if( j && k >= ( t - dif ) ) upt( f[i][j][k], f[i - 1][j - 1][k - t + dif] );
				if( j < i && k >= ( t + dif ) ) upt( f[i][j][k], 1ll * f[i - 1][j + 1][k - t - dif] * ( j + 1 ) % mod );
			}
	int ans = 0;
	for( int i = 0 ; i <= K ; i ++ ) upt( ans, f[N][0][i] );
	write( ans ), putchar( '\n' );
	return 0;
}