#include <cstdio>

const int mod = 998244353;
const int MAXN = 3606;

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

int C[MAXN][MAXN], f[MAXN][MAXN], g[MAXN][MAXN];
int fac[MAXN];
int N, M, K;
bool r[MAXN], c[MAXN];

void init()
{
	C[0][0] = fac[0] = 1;
	for( int i = 1 ; i <= N || i <= M ; i ++ )
	{
		fac[i] = 1ll * fac[i - 1] * i % mod, C[i][0] = C[i][i] = 1;
		for( int j = 1 ; j < i ; j ++ ) C[i][j] = ( C[i - 1][j] + C[i - 1][j - 1] ) % mod;
	}
}

int main()
{
	int r1, r2, c1, c2;
	read( N ), read( M ), read( K );
	init();
	for( int i = 1 ; i <= K ; i ++ )
		read( r1 ), read( c1 ), read( r2 ), read( c2 ),
		r[r1] = r[r2] = c[c1] = c[c2] = true;
	r[0] = c[0] = true;
	f[0][0] = 1;
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 0 ; j <= i >> 1 ; j ++ )
		{
			f[i][j] = f[i - 1][j];
			if( j && ! r[i] && ! r[i - 1] ) f[i][j] = ( f[i][j] + f[i - 2][j - 1] ) % mod;
		}
	g[0][0] = 1;
	for( int i = 1 ; i <= M ; i ++ )
		for( int j = 0 ; j <= i >> 1 ; j ++ )
		{
			g[i][j] = g[i - 1][j];
			if( j && ! c[i] && ! c[i - 1] ) g[i][j] = ( g[i][j] + g[i - 2][j - 1] ) % mod;
		}
	int ans = 0, totR = 0, totC = 0;
	for( int i = 1 ; i <= N ; i ++ ) totR += ! r[i];
	for( int i = 1 ; i <= M ; i ++ ) totC += ! c[i];
	for( int i = 0 ; i <= N ; i ++ )
		for( int j = 0 ; j <= M ; j ++ )
			if( totR >= 2 * j && totC >= 2 * i )
				ans = ( ans + 1ll * f[N][j] * g[M][i] % mod * 
									C[totR - 2 * j][i] % mod * C[totC - 2 * i][j] % mod *
									fac[i] % mod * fac[j] % mod ) % mod; 
	write( ans ), putchar( '\n' );
	return 0;
}