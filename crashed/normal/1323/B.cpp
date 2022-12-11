#include <cstdio>

typedef long long LL;

const int MAXN = 40005, MAXM = 40005;

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

int totA[MAXN], totB[MAXN];
int a[MAXN], b[MAXM];
int N, M, K;

int main()
{
	read( N ), read ( M ), read( K );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	for( int i = 1 ; i <= M ; i ++ ) read( b[i] );
	for( int i = 1, r ; i <= N ; i ++ )
		if( a[i] )
		{
			for( r = i + 1 ; r <= N && a[r] ; r ++ );
			for( int j = 1 ; j <= r - i ; j ++ ) totA[j] += r - i - j + 1;
			i = r - 1;
		}
	for( int i = 1, r ; i <= M ; i ++ )
		if( b[i] )
		{
			for( r = i + 1 ; r <= M && b[r] ; r ++ );
			for( int j = 1 ; j <= r - i ; j ++ ) totB[j] += r - i - j + 1;
			i = r - 1;
		}
	LL ans = 0;
	int part;
	for( int i = 1 ; 1ll * i * i <= K ; i ++ )
		if( ! ( K % i ) )
		{
			if( i <= N && ( part = K / i ) <= M ) ans += 1ll * totA[i] * totB[part];
			if( i * i != K && i <= M && part <= N ) ans += 1ll * totB[i] * totA[part];
		}
	write( ans ), putchar( '\n' );
	return 0;
}