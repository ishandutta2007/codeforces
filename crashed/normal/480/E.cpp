#include <cstdio>

#define rep( x, a, b ) for( int (x) = (a) ; (x) <= (b) ; (x) ++ )
#define per( x, a, b ) for( int (x) = (a) ; (x) >= (b) ; (x) -- )

const int MAXN = 2e3 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
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

int up[MAXN][MAXN], down[MAXN][MAXN];

int ans[MAXN];

int Q1[MAXN], h1, t1;
int Q2[MAXN], h2, t2;

int entX[MAXN], entY[MAXN];

char S[MAXN];
int N, M, K;
bool grid[MAXN][MAXN];

void Upt( const int y )
//O(n)
{
	rep( i, 1, N ) up[i][y] = grid[i][y] ? 0 : up[i - 1][y] + 1;
	per( i, N, 1 ) down[i][y] = grid[i][y] ? 0 : down[i + 1][y] + 1; 
}

bool Chk( const int x, const int l )
//O(n)
{
	if( l == 0 ) return true;
	h1 = h2 = 1, t1 = t2 = 0;
	rep( i, 1, l - 1 )
	{
		while( h1 <= t1 && up[x][Q1[t1]] >= up[x][i] ) t1 --;
		while( h2 <= t2 && down[x][Q2[t2]] >= down[x][i] ) t2 --;
		Q1[++ t1] = i, Q2[++ t2] = i;
	}
	rep( i, l, M )
	{
		while( h1 <= t1 && Q1[h1] <= i - l ) h1 ++;
		while( h2 <= t2 && Q2[h2] <= i - l ) h2 ++;
		while( h1 <= t1 && up[x][Q1[t1]] >= up[x][i] ) t1 --;
		while( h2 <= t2 && down[x][Q2[t2]] >= down[x][i] ) t2 --;
		Q1[++ t1] = i, Q2[++ t2] = i;
		if( up[x][Q1[h1]] + down[x][Q2[h2]] - 1 >= l ) return true;
	}
	return false;
}

int Calc( const int p )   
//O(nlogn)
{
	int L = 0, R = MIN( N, M ), mid;
	while( L < R )
	{
		mid = L + R + 1 >> 1;
		if( Chk( p, mid ) ) L = mid;
		else R = mid - 1;
	}
	return L;
}

void Init() { rep( j, 1, M ) Upt( j );}
//O(n^2)

int main()
{
//	freopen( "parking.in", "r", stdin );
//	freopen( "parking-std.out", "w", stdout );
	read( N ), read( M ), read( K );
	rep( i, 1, N )
	{
		scanf( "%s", S + 1 );
		rep( j, 1, M ) grid[i][j] = S[j] == 'X';
	}
	rep( i, 1, K ) read( entX[i] ), read( entY[i] ), grid[entX[i]][entY[i]] = true;
	Init(); 
	rep( i, 1, N ) 
		ans[K] = MAX( ans[K], Calc( i ) );
	per( i, K - 1, 1 )
	{
		grid[entX[i + 1]][entY[i + 1]] = false; Upt( entY[i + 1] );
		ans[i] = MAX( ans[i + 1], Calc( entX[i + 1] ) );
	}
	rep( i, 1, K ) write( ans[i] ), putchar( '\n' );
	return 0;
}