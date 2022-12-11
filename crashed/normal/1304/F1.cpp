#include <cstdio>

const int INF = 0x3f3f3f3f;
const int MAXN = 55, MAXM = 2e4 + 5;

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

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int f[MAXN][MAXM], pMx[MAXM], sMx[MAXM];
int a[MAXN][MAXM], s[MAXN][MAXM];
int N, M, K, llen, rlen;

int getL( const int x ) { return x - llen; }
int getR( const int x ) { return x + rlen; }
int getS( const int x, const int l, const int r ) { return s[x][r] - s[x][l - 1]; }
int query( const int x, const int mid ) { return getS( x, mid - llen, mid + rlen ); }

int main()
{
	read( N ), read( M ), read( K );
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= M ; j ++ ) 
			read( a[i][j] ), s[i][j] = s[i][j - 1] + a[i][j];
	int lef = K + 1 >> 1, rig = M - ( K >> 1 ); 
	llen = K - 1 >> 1, rlen = K >> 1;
	for( int i = lef ; i <= rig ; i ++ ) f[1][i] = query( 1, i );
	for( int i = 2, cost ; i <= N ; i ++ )
	{
		for( int j = 1 ; j <= M ; j ++ ) pMx[j] = sMx[j] = -INF;
		for( int j = lef ; j <= rig ; j ++ ) pMx[j] = MAX( pMx[j - 1], f[i - 1][j] + query( i, j ) );
		for( int j = rig ; j >= lef ; j -- ) sMx[j] = MAX( sMx[j + 1], f[i - 1][j] + query( i, j ) ); 
		for( int j = lef ; j <= rig ; j ++ )
		{
			f[i][j] = -INF;
			for( int k = MAX( lef, j - K + 1 ) ; k <= MIN( rig, j + K - 1 ) ; k ++ )
			{
				cost = getS( i, MAX( getL( k ), getL( j ) ), MIN( getR( k ), getR( j ) ) );
				f[i][j] = MAX( f[i][j], f[i - 1][k] + query( i, k ) + query( i, j ) - cost ); 
			}
			if( j - K >= lef ) f[i][j] = MAX( f[i][j], pMx[j - K] + query( i, j ) );
			if( j + K <= rig ) f[i][j] = MAX( f[i][j], sMx[j + K] + query( i, j ) );
		}
	}
	int ans = -INF;
	for( int i = lef ; i <= rig ; i ++ ) ans = MAX( ans, f[N][i] );
	write( ans ), putchar( '\n' );
	return 0;
}