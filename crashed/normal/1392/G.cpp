#include <cstdio>
 
#define Count __builtin_popcount 
 
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5, MAXK = 25, MAXS = ( 1 << 20 ) + 5;
 
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
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
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
 
int N, M, K;
 
typedef struct Permutation
{
	int p[MAXK] = {};
	
	Permutation() 
	{
		for( int i = 1 ; i <= K ; i ++ )
			p[i] = i;
	}
	
	int& operator [] ( const int indx ) { return p[indx]; }
}Per;
 
int f[2][MAXS];
Per suf[MAXN], s, t;
 
Per operator + ( Per a, Per p )
{
	Per ret;
	for( int i = 1 ; i <= K ; i ++ )
		ret[i] = a[p[i]];
	return ret;
}
 
int Transform( Per num )
{
	int ret = 0;
	for( int i = 1 ; i <= K ; i ++ )
		ret = ret << 1 | num[i];
	return ret;
}
 
int main()
{
	read( N ), read( M ), read( K );
	for( int i = 1 ; i <= K ; i ++ ) scanf( "%1d", &s[i] );
	for( int i = 1 ; i <= K ; i ++ ) scanf( "%1d", &t[i] );
	for( int i = 1, a, b ; i <= N ; i ++ )
		read( a ), read( b ), suf[i] = Permutation(),
		swapp( suf[i][a], suf[i][b] );
	suf[N + 1] = Permutation();
	for( int i = N ; i ; i -- ) 
		suf[i] = suf[i] + suf[i + 1];
	int upper = 1 << K;
	for( int S = 0 ; S < upper ; S ++ )
		f[0][S] = INF, f[1][S] = -INF;
	for( int i = N + 1 ; i ; i -- )
	{
		int val = Transform( s + suf[i] );
		f[0][val] = MIN( f[0][val], i );
		val = Transform( t + suf[i] );
		f[1][val] = MAX( f[1][val], i ); 
	}
	int a = Count( Transform( s ) ), 
		b = Count( Transform( t ) ), 
		c, ans = -INF, L, R, val;
	for( int S = upper - 1 ; ~ S ; S -- )
	{
		for( int i = 0 ; i < K ; i ++ )
			if( ! ( S >> i & 1 ) )
				f[0][S] = MIN( f[0][S], f[0][S | ( 1 << i )] ),
				f[1][S] = MAX( f[1][S], f[1][S | ( 1 << i )] );
		if( f[1][S] - f[0][S] >= M )
		{
			c = Count( S );
			val = 2 * c - a - b + K;
			if( val > ans ) L = f[0][S], R = f[1][S] - 1, ans = val;
		}
	}
	write( ans ), putchar( '\n' ); 
	write( L ), putchar( ' ' ), write( R ), putchar( '\n' );
	return 0;
}