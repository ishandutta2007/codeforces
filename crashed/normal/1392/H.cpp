#include <cstdio>

typedef long long LL;

const int mod = 998244353;
const int MAXN = 4e6 + 5;

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

int inv[MAXN];
int w[MAXN];
int N, M;

int Sub( int x, int v ) { return x < v ? x - v + mod : x - v; }
int Mul( LL x, int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
int Add( int x, int v ) { return x + v >= mod ? x + v - mod : x + v; }

void Init( const int siz )
{
	inv[1] = 1;
	for( int i = 2 ; i <= siz ; i ++ )
		inv[i] = Mul( mod - mod / i, inv[mod % i] );
}

int main()
{
	read( N ), read( M );
	Init( N + M );
	
	w[0] = 1;
	for( int i = 1 ; i <= N ; i ++ )
		w[i] = Mul( w[i - 1], Mul( N - i + 1, inv[M + N - i + 1] ) );
	int E = 0, su = 0;
	for( int i = 0 ; i <= N ; i ++ )
		E = Add( E, Mul( Mul( i + 1, Mul( M, inv[M + N - i] ) ), w[i] ) );
	
	for( int i = 1 ; i <= N ; i ++ ) su = Add( su, inv[i] );
	su = Add( Mul( su, M ), 1 );
	write( Mul( E, su ) ), putchar( '\n' );
	return 0;
}