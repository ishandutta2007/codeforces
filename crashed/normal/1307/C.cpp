#include <cstdio>
#include <cstring>

#define int LL

typedef long long LL;

const int MAXN = 1e5 + 5;

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

LL par[30][30];
int bac[30], pr[30];
char S[MAXN];
int N;

int id( const char c ) { return c - 'a'; }

signed main()
{
	LL ans = 0; 
	scanf( "%s", S + 1 );
	N = strlen( S + 1 );
	for( int i = 1 ; i <= N ; i ++ ) bac[id( S[i] )] ++;
	for( int i = 1 ; i <= N ; i ++ ) ans = MAX( ans, ( LL ) bac[id( S[i] )] );
	for( int i = 1, r ; i <= N ; )
	{
		for( r = i ; r <= N && S[r] == S[i] ; r ++ );
		for( int j = 0 ; j < 26 ; j ++ ) par[j][id( S[i] )] += pr[j] * ( r - i );
		par[id( S[i] )][id( S[i] )] += 1ll * ( r - i ) * ( r - i - 1 ) >> 1;
		pr[id( S[i] )] += r - i;
		i = r;
	}
	for( int i = 0 ; i < 26 ; i ++ )
		for( int j = 0 ; j < 26 ; j ++ )
			ans = MAX( ans, par[i][j] );
	write( ans ), putchar( '\n' );
	return 0;
}