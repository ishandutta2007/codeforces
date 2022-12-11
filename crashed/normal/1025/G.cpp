#include <cstdio>

const int mod = 1e9 + 7;
const int MAXN = 505;

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

int pw[MAXN];
int siz[MAXN];
int N;

void sub( int &x, const int v ) { x = ( x < v ? x - v + mod : x - v ); }

int main()
{
	read( N );
	for( int i = 1, a ; i <= N ; i ++ ) read( a ), siz[a] ++;
	pw[0] = 1; for( int i = 1 ; i <= N ; i ++ ) pw[i] = 2ll * pw[i - 1] % mod;
	int ans = pw[N - 1]; sub( ans, 1 );
	for( int i = 1 ; i <= N ; i ++ ) sub( ans, pw[siz[i]] - 1 );
	write( ans ), putchar( '\n' );
	return 0;
}